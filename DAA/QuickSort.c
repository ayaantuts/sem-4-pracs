#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define n 1000

int a[n], b[n], i, j, temp;
clock_t start, end;
double cpu_time_used;

/**
 * @brief This function is used to swap the elements of the array.
 * 
 * @param i: Index of the first element
 * @param j: Index of the second element
 */
void swap(int i, int j) { int temp = a[i]; a[i] = a[j]; a[j] = temp; }

/**
 * @brief This function is used to partition the array into two sub-arrays, based on a pivot.
 * The pivot element is placed at its correct position in the array, thus dividing the array into two sub-arrays.
 * @param low: Starting index of the array
 * @param high: Ending index of the array
 * @return int: Correct Index of the pivot element
 */
int partition(int low, int high) {
	int pivot = a[high], i = low - 1, j;
    for (j = low; j < high; j++)
        if (a[j] < pivot) {
            i++;
            swap(i, j);
        }
    swap(i + 1, high);
    return i + 1;
}

/**
 * @brief This function is used to sort the array using quick sort algorithm.
 * @param low 
 * @param high 
 */
void quickSort(int low, int high) {
    int pivot;
	if (low < high) {
		// Partition the array into two sub-arrays
        pivot = partition(low, high);
		// Call quickSort recursively for the two sub-arrays
		quickSort(low, pivot - 1);
		quickSort(pivot + 1, high);
	}
}

int main() {
	// Best case: Pivot selected is always the median of the array
	printf("Best case:\n");
	for (i = 0; i < n; i++)
		a[i] = i;
	start = clock();
	quickSort(0, n - 1);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time taken: %f ms", cpu_time_used * 1000);

	// Average case: Pivot selected is random
	printf("\n\nAverage case:\n");
	for (i = 0; i < n; i++)
		a[i] = rand();
	start = clock();
	quickSort(0, n - 1);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time taken: %f ms", cpu_time_used * 1000);

	// Worst case: Pivot selected is always the first or last element
	printf("\n\nWorst case:\n");
	for (i = 0; i < n; i++)
		a[i] = n - i;
	start = clock();
	quickSort(0, n - 1);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time taken: %f ms", cpu_time_used * 1000);

	return 0;
}