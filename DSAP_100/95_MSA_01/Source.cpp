// Merge sort algorithm

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 15

void merge(int A[], int aux[], int p, int q, int r)
{
	int i = p;
	int j = q + 1;
	int k = p;
	while (i <= q && j <= r)
	{
		if (A[i] <= A[j])
		{
			aux[k++] = A[i++];
		}
		else
		{
			aux[k++] = A[j++];
		}
	}

	while (i <= q)
	{
		aux[k++] = A[i++];
	}

	for (int l = p; l <= r; l++)
	{
		A[l] = aux[l];
	}
}

void mergeSort(int A[], int aux[], int p, int r)
{
	if (p == r)
	{
		return;
	}
	int q = (p + r) / 2;
	// int q = p + ((r - p) >> 1);
	mergeSort(A, aux, p, q);
	mergeSort(A, aux, q + 1, r);
	merge(A, aux, p, q, r);
}

int main()
{
	int A[N];
	int aux[N];
	srand(time(NULL));

	for (int i = 0; i < N; i++)
	{
		aux[i] = A[i] = rand() % 100 - 50;
	}
	mergeSort(A, aux, 0, N - 1);

	for (int i = 0; i < N; i++)
	{
		printf("%d ", A[i]);
	}
}


