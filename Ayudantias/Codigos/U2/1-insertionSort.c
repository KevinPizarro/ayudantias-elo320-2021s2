// C program for insertion sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 50000

void insertionSort(short int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

// A utility function to print an array of size n
void printArray(short int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

/* Driver program to test insertion sort */
int main()
{
	short int arr[SIZE];
	int n = sizeof(arr) / sizeof(arr[0]);

	clock_t begin = clock();
	insertionSort(arr, n);
	clock_t end = clock();
	double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Tiempo de ejecución: %lf[s].\n", time_spent);

	return 0;
}
