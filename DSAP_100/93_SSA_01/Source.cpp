// Selection sort algorithm

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

void selectionSort(int A[], int lenA)
{
	for (int i = 0; i < lenA - 1; i++)
	{
		int minValueIdx = i;
		for (int j = i + 1; j < lenA; j++)
		{
			if (A[minValueIdx] > A[j])
			{
				minValueIdx = j;
			}
		}
		swap(A, minValueIdx, i);
	}
}

int main()
{
	int A[] = { 2, 5, 4, 6, 1, 3 };
	int lenA = sizeof(A) / sizeof(A[0]);

	selectionSort(A, lenA);
	printArray(A, lenA);
}