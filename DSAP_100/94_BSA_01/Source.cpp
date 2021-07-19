// Bubble sort algorithm

#include <stdio.h>

void printArray(int A[], int lenA)
{
	for (int i = 0; i < lenA; i++)
	{
		printf("%d ", A[i]);
	}
}
void swap(int A[], int i)
{
	int temp = A[i];
	A[i] = A[i - 1];
	A[i - 1] = temp;
}

void bubbleSort(int A[], int lenA)
{
	for (int i = 0; i < lenA - 1; i++)
	{
		for (int j = lenA - 1; j >= i + 1; j--)
		{
			if (A[j] < A[j - 1])
			{
				swap(A, j);
			}
		}
	}
}

int main()
{
	int A[] = { 2, 5, 4, 6, 1, 3 };
	int lenA = sizeof(A) / sizeof(A[0]);

	bubbleSort(A, lenA);
	printArray(A, lenA);
}