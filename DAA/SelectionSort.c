#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define n 1000

int a[n], i, j, imin;
clock_t start, end;
double cpu_time_used;

/**
 * @brief This function is used to sort the array using selection sort algorithm.
 * 
 */
void selectionSort() {
	start = clock();
	for (i = 0; i < n - 1; i++) {
        imin = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[imin])
                imin = j;

        if (imin != i) {
            j = a[imin];
            a[imin] = a[i];
            a[i] = j;
        }
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
	selectionSort();

	// Average case: Array is filled with random values
	printf("\n\nAverage case:\n");
	for (i = 0; i < n; i++)
		a[i] = rand();
	selectionSort();

	// Worst case: Array is sorted in reverse order
	printf("\n\nWorst case:\n");
	for (i = 0; i < n; i++)
		a[i] = n - i;
	selectionSort();

	return 0;
}