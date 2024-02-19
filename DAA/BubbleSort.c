#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define n 1000

int a[n], i, j, temp;
clock_t start, end;
double cpu_time_used;

/**
 * @brief Bubble sort algorithm
 * 
 */
void bubbleSort() {
	start = clock();
	for (i = 0; i < n; i++)
		for (j = 0; j < n - i; j++)
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
	
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time taken: %f ms", cpu_time_used * 1000);
}

int main() {
	// Best case: Array is already sorted
	printf("Best case:\n");
	for (i = 0; i < n; i++)
		a[i] = i;
	bubbleSort();

	// Average case: Array is filled with random numbers
	printf("\n\nAverage case:\n");
	for (i = 0; i < n; i++)
		a[i] = rand();
	bubbleSort();

	// Worst case: Array is sorted in reverse order
	printf("\n\nWorst case:\n");
	for (i = 0; i < n; i++)
		a[i] = n - i;
	bubbleSort();

	return 0;
}