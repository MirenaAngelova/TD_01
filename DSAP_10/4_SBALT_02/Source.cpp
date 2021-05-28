// Quicksort partition logic

#include <stdio.h>

void swap(int A[], int i, int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

void quicksort(int A[], int n)
{
	int pivot = 1;
	int j = 0;
	for (int i = 0; i < n; i++)
	{
		if (A[i] < pivot)
		{
			swap(A, i, j);
			j++;
		}
	}
}

int main()
{
	int A[] = {1, 0, 0, 0, 1, 0, 1, 1};
	int n = sizeof(A) / sizeof(A[0]);
	quicksort(A, n);

	for (int i = 0; i < n; i++)
	{
		printf("%d ", A[i]);
	}
	
}