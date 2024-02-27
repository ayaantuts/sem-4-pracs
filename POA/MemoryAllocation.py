def firstFit(blockSize:list[int], m:int, processSize:list[int], n:int):
	"""
	This function allocates memory to processes using First Fit algorithm.
	"""
	# First calculate the total memory
	totalMem = 0
	for i in range(len(blockSize)):
		totalMem += blockSize[i]
	# Create an array to store the block allocation
	allocation = [-1] * n
	# Create an array to store the block occupancy (true or false)
	blockOcc = [False] * m
	for i in range(n):
		for j in range(m):
			# If the block size is greater than or equal to the process size and the block is not occupied
			if blockSize[j] >= processSize[i] and blockOcc[j] == False:
				# Allocate the block to the process
				allocation[i] = j
				# Mark the block as occupied
				blockOcc[j] = True
				break

	print("First Fit")
	# Calculate the memory utilization
	mem = 0
	print("PNo.\tPSize\tBlock no.")
	for i in range(n):
		print(i + 1, "\t", processSize[i], "\t", end = "")
		if allocation[i] != -1:
			# If the block is allocated, print the block number
			mem += processSize[i]
			print(allocation[i] + 1)
		else:
			print("Not Allocated")
	# Print the memory utilization
	print("Memory Utilization is")
	print(mem/totalMem*100 , "%\n")

def bestFit(blockSize:list[int], m:int, processSize:list[int], n:int):
	# First calculate the total memory
	totalMem = 0
	for i in range(len(blockSize)):
		totalMem += blockSize[i]
	# Create an array to store the block allocation
	allocation = [-1] * n
	# Create an array to store the block occupancy (true or false)
	blockOcc = [False] * m
	for i in range(n):
		# Finding the best fit block index for the process
		bestIdx = -1
		for j in range(m):
			# If the block size is greater than or equal to the process size and the block is not occupied
			if blockSize[j] >= processSize[i] and blockOcc[j] == False:
				# If the best index is not set or the block size is less than the best block size
				if bestIdx == -1 or blockSize[bestIdx] > blockSize[j]:
					# Set the best index to the current index
					bestIdx = j
		# If the best index is set
		if bestIdx != -1:
			# Allocate the block to the process
			allocation[i] = bestIdx
			# Mark the block as occupied
			blockOcc[bestIdx] = True
	# Calculate the memory utilization
	mem=0
	print("Best Fit")
	print("PNo.\tPSize\tBlock no.")
	for i in range(n):
		print(i + 1, "\t", processSize[i], "\t", end = "")
		if allocation[i] != -1:
			# If the block is allocated, print the block number
			mem += processSize[i]
			print(allocation[i] + 1)
		else:
			print("Not Allocated")
	# Print the memory utilization
	print("Memory Utilization is")
	print(mem/totalMem*100 , "%\n")

def worstFit(blockSize:list[int], m:int, processSize:list[int], n:int):
	# First calculate the total memory
	totalMem = 0
	for i in range(len(blockSize)):
		totalMem += blockSize[i]
	# Create an array to store the block allocation
	allocation = [-1] * n
	# Create an array to store the block occupancy (true or false)
	blockOcc = [False] * m
	for i in range(n):
		# Finding the worst fit block index for the process
		wstIdx = -1
		for j in range(m):
			# If the block size is greater than or equal to the process size and the block is not occupied
			if blockSize[j] >= processSize[i] and blockOcc[j] == False:
				# If the worst index is not set or the block size is greater than the worst block size
				if wstIdx == -1 or blockSize[wstIdx] < blockSize[j]:
					# Set the worst index to the current index
					wstIdx = j
		# If the worst index is set
		if wstIdx != -1:
			# Allocate the block to the process
			allocation[i] = wstIdx
			# Mark the block as occupied
			blockOcc[wstIdx] = True
	# Calculate the memory utilization
	mem = 0
	print("Worst Fit")
	print("PNo.\tPSize\tBlock no.")
	for i in range(n):
		print(i + 1, "\t", processSize[i], "\t", end = "")
		if allocation[i] != -1:
			# If the block is allocated, print the block number
			mem += processSize[i]
			print(allocation[i] + 1)
		else:
			print("Not Allocated")
	# Print the memory utilization
	print("Memory Utilization is")
	print(mem/totalMem*100 , "%\n")

no_of_processes = 4
blockSize = [100, 500, 200, 300, 600]
processSize = []
print("Enter process sizes:")
"""
This is a concise way to take input from the user.
The user can enter the process sizes separated by spaces.
The input is then split into a list of strings.
The list of strings is then converted into a list of integers.
"""
# processSize = [int(x) for x in input("Enter process sizes: ").split()]

"""
This is a verbose and simple to understand way to take input from the user.
The user can enter the process sizes one by one.
The process sizes are then appended to the processSize list.
"""
for i in range(no_of_processes):
	processSize.append(int(input("Process " + str(i + 1) + " size: ")))
# processSize = [212, 417, 112, 426]
m = len(blockSize)
n = len(processSize)

print(blockSize)
firstFit(blockSize, m, processSize, n)

bestFit(blockSize, m, processSize, n)

worstFit(blockSize, m, processSize, n)

"""
212
417
112
426
"""