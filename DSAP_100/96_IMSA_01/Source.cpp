// Iterative merge sort algorithm
// (bottom_up merge sort)

// The worst-case time complexity of iterative merge sort
// remains the same as recursive implementation, i.e.
// O(n*lg(n)). Although it saves òhe auxilary space
// required for the call stack

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 15

void printArray(int A[])
{
	for (int i = 0; i < N; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}

int min(int a, int b)
{
	return a < b ? a : b;
}

void merge(int A[], int aux[], int p, int q, int r)
{
	int i = p;
	int j = q + 1;
	int k = p;
	
	while (i <= q && j <= r)
	{
		if (A[i] < A[j])
		{
			aux[k++] = A[i++];
		}
		else
		{
			aux[k++] = A[j++];
		}
	}

	while (i < N && i <= q)
	{
		aux[k++] = A[i++];
	}

	for (int i = p; i <= r; i++)
	{
		A[i] = aux[i];
	}
}
void mergeSort(int A[], int aux[], int p, int r)
{
	for (int j = 1; j <= r - p; j *= 2)
	{
		for (int i = p; i < r; i += 2*j)
		{
			int pNext = i;
			int q = i + j - 1;
			int rNext = min(i + 2 * j - 1, r);
			merge(A, aux, pNext, q, rNext);
		}
	}
}

int main()
{
	int A[N];
	int aux[N];
	srand(time(NULL));

	for (int i = 0; i < N; i++)
	{
		A[i] = aux[i] = rand() % 50;
	}

	printf("Original array: ");
	printArray(A);
	
	mergeSort(A, aux, 0, N - 1);

	printf("Modified array: ");
	printArray(A);
}