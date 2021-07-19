#include <stdio.h>

void printArray(int A[], int lenA)
{
	for (int i = 0; i < lenA; i++)
	{
		printf("%d ", A[i]);
	}
}

void exchange(int A[], int i)
{
	int temp = A[i];
	A[i] = A[i - 1];
	A[i - 1] = temp;
}

void bubbleSort(int A[], int i, int lenA)
{
	if (i == lenA - 1)
	{
		return;
	}
	for (int j = lenA - 1; j >= i + 1; j--)
	{
		if (A[j] < A[j - 1])
		{
			exchange(A, j);
		}
	}
	bubbleSort(A, i + 1, lenA);
}

int main()
{
	int A[] = { 2, 5, 4, 6, 1, 3 };
	int lenA = sizeof(A) / sizeof(A[0]);

	bubbleSort(A, 0, lenA);
	printArray(A, lenA);
}