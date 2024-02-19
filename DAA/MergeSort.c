#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define n 10000

int a[n], b[n], i, j, temp;
clock_t start, end;
double cpu_time_used;

/**
 * @brief This function is used to merge and sort the sub-arrays.
 * it is used in merge sort algorithm.
 * @param low: Starting index of the first sub-array
 * @param mid: Starting index of the second sub-array
 * @param high: Ending index of the second sub-array
 */
void merge(int low, int mid, int high) {
	int  i = low, j = mid + 1, k = low;
	while (i <= mid && j <= high) {
		if (a[i] < a[j])
			b[k++] = a[i++];
		else
			b[k++] = a[j++];
	}
	while (i <= mid)
		b[k++] = a[i++];
	while (j <= high)
		b[k++] = a[j++];
	for (i = low; i <= high; i++)
		a[i] = b[i];
}

/**
 * @brief This function is used to break the array into two halves (sub-arrays).
 * This function is called recursively to break the array into smaller sub-arrays.
 * @param low: Starting index of the array
 * @param high: Ending index of the array
 */
void mergeSort(int low, int high) {
	// Calculating mid index of the array, to break the array into two halves
	int mid = (low + high) / 2;
	if (low < high) {
		mergeSort(low, mid);
		mergeSort(mid + 1, high);
		merge(low, mid, high);
	}
}

int main() {
	// Best case: Array is already sorted
	printf("Best case:\n");
	for (i = 0; i < n; i++)
		a[i] = i;
	start = clock();
	mergeSort(0, n - 1);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time taken: %f ms", cpu_time_used * 1000);

	// Average case: Array is filled with random numbers
	printf("\n\nAverage case:\n");
	for (i = 0; i < n; i++)
		a[i] = rand();
	start = clock();
	mergeSort(0, n - 1);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time taken: %f ms", cpu_time_used * 1000);

	// Worst case: Array is sorted in reverse order
	printf("\n\nWorst case:\n");
	for (i = 0; i < n; i++)
		a[i] = n - i;
	start = clock();
	mergeSort(0, n - 1);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time taken: %f ms", cpu_time_used * 1000);

	return 0;
}