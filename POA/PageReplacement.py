print("Ayaan Shaikh - C1-1 - C026")
print("Page Replacement Policies")

# Taking the input
print("Enter the page sequence: ", end="")
# Split the input by ", " and convert each element to int (assuming the input is comma separated integers)
pages = [int(x) for x in input("").split(", ")]

def FIFO(pages:list[int]):
	"""A function that simulates the FIFO page replacement policy"""
	frame = [-1] * 3
	hit_count = 0
	miss_count = 0
	# k is the index of the frame to be replaced
	k = 0
	print("==== FIFO ====")
	print("==== Pages ====")
	print("Page\tF1\tF2\tF3")
	for page in pages:
		hit = False
		print(page, end=":\t")
		if page in frame:
			hit_count += 1
			hit = True
		else:
			miss_count += 1
			# Replace the page at index k
			frame[k] = page
			# Increment k to replace the next page in the next iteration of the loop (circularly)
			k = (k + 1) % 3
		for f in frame:
			print(f, end="\t")
		print("H" if hit else "M")

	print("Number of hits:", hit_count, " and faults:", miss_count)
	print("Hit ratio:", hit_count / len(pages), " Miss ratio:", miss_count / len(pages))

def LRU(pages:list[int]):
	"""A function that simulates the LRU page replacement policy"""
	frame = [-1] * 3
	hit_count = 0
	miss_count = 0
	usedTimes = [0] * 3
	# clock is the time at which the page is accessed
	clock = 1
	print("==== LRU ====")
	print("==== Pages ====")
	print("Page\tF1\tF2\tF3")
	for page in pages:
		hit = False
		print(page, end=":\t")
		if page in frame:
			hit_count += 1
			minIndex = frame.index(page)
			hit = True
		else:
			miss_count += 1
			# Replace the page that was least recently used
			minIndex = usedTimes.index(min(usedTimes))
			frame[minIndex] = page
		# Update the time at which the page was accessed
		usedTimes[minIndex] = clock
		clock += 1
		for f in frame:
			print(f, end="\t")
		print("H" if hit else "M")
			
	print("Number of hits:", hit_count, "and faults:", miss_count)
	print("Hit ratio:", hit_count / len(pages), "Miss ratio:", miss_count / len(pages))

def Optimal(pages: list[int]):
	"""A function that simulates the Optimal page replacement policy"""
	frame = [-1] * 3
	hit_count = 0
	miss_count = 0
	print("==== Optimal ====")
	print("==== Pages ====")
	print("Page\tF1\tF2\tF3")
	
	for page in pages:
		index = pages.index(page)
		hit = False
		print(page, end=":\t")
		
		if page in frame:
			hit_count += 1
			hit = True
		else:
			miss_count += 1
			# Replace the page that will not be used for the longest time
			future = pages[index:]
			futureIdx = [-1] * 3
			# If there is an empty frame, replace it with the page
			if -1 in frame:
				ind = frame.index(-1)
				frame[ind] = page
			else:
				# Find the index of the page in the future list and replace the page with the maximum index
				for i in range(3):
					# If the page is in the future list, store its index
					if frame[i] in future:
						futureIdx[i] = future.index(frame[i])
					else:
						# If the page is not in the future list, replace it
						futureIdx[i] = float("inf") # float("inf") is used to represent infinity
				
			ind = futureIdx.index(max(futureIdx))
			frame[ind] = page
		
		for f in frame:
			print(f, end="\t")
		print("H" if hit else "M")
	
	print("Number of hits:", hit_count, "and faults:", miss_count)
	print("Hit ratio:", hit_count / len(pages), "Miss ratio:", miss_count / len(pages))

FIFO(pages)
print()
LRU(pages)
print()
Optimal(pages)
# 2, 3, 2, 1, 5, 2, 4, 5, 3, 2, 5
# 6, 0, 12, 0, 30, 4, 2, 30, 32, 1, 20, 15