#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define n 10000

int a[n], min, max;
clock_t start, end;
double cpu_time_used;

/**
 * @brief MinMax algorithm to find the minimum and maximum elements in an array.
 * It is a divide and conquer algorithm.
 * @param low: Starting index of the sub-array
 * @param high: Ending index of the sub-array
 */
void MinMax(int low, int high) {
	int mid, min1, max1;
	if (low == high) {
		// If there is only one element in the array, it is both min and max
		max = min = a[low];
	}
	else if (low == high - 1) {
		// If there are two elements in the array, compare them and find min and max
		if (a[low] < a[high]) {
			min = a[low];
			max = a[high];
		}
		else {
			min = a[high];
			max = a[low];
		}
	}
	else {
		// If there are more than two elements in the array, divide the array into two halves
		mid = (low + high) / 2;
		// Find min and max in the first half
		MinMax(low, mid);
		min1 = min;
		max1 = max;
		// Find min and max in the second half
		MinMax(mid + 1, high);
		// Compare the min and max of the two halves and find the overall min and max
		if (max1 > max)
			max = max1;
		if (min1 < min)
			min = min1;
	}
}

int main() {
	int i;
	// Generating random numbers
	for (i = 0; i < n; i++)
		a[i] = rand();
	start = clock();
	MinMax(0, n - 1);
	end = clock();
	printf("Min: %d, Max: %d", min, max);
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nTime taken: %f ms", cpu_time_used * 1000);
	return 0;
}