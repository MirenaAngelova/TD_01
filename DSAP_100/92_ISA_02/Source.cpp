#include <stdio.h>

void printArray(int A[], int lenA)
{
	for (int i = 0; i < lenA; i++)
	{
		printf("%d ", A[i]);
	}
}

void insertionSort(int A[], int j, int lenA)
{
	if (j == lenA)
	{
		return;
	}
	int key = A[j];
	int i = j - 1;
	while (i >= 0 && A[i] > key)
	{
		A[i + 1] = A[i];
		i--;
	}
	A[i + 1] = key;
	insertionSort(A, j + 1, lenA);
}

int main()
{
	int A[] = { 3, 8, 5, 4, 1, 9, -2 };
	int lenA = sizeof(A) / sizeof(A[0]);

	insertionSort(A, 1, lenA);
	printArray(A, lenA);
}