#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define n 1000

int a[n], i, j, temp;
clock_t start, end;
double cpu_time_used;
void insertionSort() {
		start = clock();
	for (i = 1; i < n; i++) {
		temp = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > temp) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time taken: %f ms", cpu_time_used * 1000);
}

int main() {
	printf("Best case:\n");
	for (i = 0; i < n; i++)
		a[i] = i;
	insertionSort();

	printf("\n\nAverage case:\n");
	for (i = 0; i < n; i++)
		a[i] = rand();
	insertionSort();

	printf("\n\nWorst case:\n");
	for (i = 0; i < n; i++)
		a[i] = n - i;
	insertionSort();

	// printf("Unsorted array:\n");
	// for (i = 0; i < n; i++)
	// 	printf("%d ", a[i]);
	
	// printf("\n\nSorted array:\n");
	// for (i = 0; i < n; i++)
	// 	printf("%d ", a[i]);

	return 0;
}