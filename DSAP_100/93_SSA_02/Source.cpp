#include <stdio.h>

void printArray(int A[], int lenA)
{
	for (int i = 0; i < lenA; i++)
	{
		printf("%d ", A[i]);
	}
}

void swap(int A[], int i, int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

void selectionSort(int A[], int i, int lenA)
{
	if (i == lenA - 1)
	{
		return;
	}
	int minValueIdx = i;
	for (int j = i + 1; j < lenA; j++)
	{
		if (A[minValueIdx] > A[j])
		{
			minValueIdx = j;
		}
	}
	swap(A, i, minValueIdx);
	selectionSort(A, i + 1, lenA);
}

int main()
{
	int A[] = { 2, 5, 4, 6, 3, 1 };
	int lenA = sizeof(A) / sizeof(A[0]);

	selectionSort(A, 0, lenA);
	printArray(A, lenA);
}