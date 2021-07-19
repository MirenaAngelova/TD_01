// Insertion sort algorithm

// Input: {5, 2, 4, 6, 1, 3}
// Output: {1, 2, 3, 4, 5, 6}

#include <stdio.h>

void printArray(int A[], int lenA)
{
	for (int i = 0; i < lenA; i++)
	{
		printf("%d ", A[i]);
	}
}
void insertionSort(int A[], int lenA)
{
	for (int j = 1; j < lenA; j++)
	{
		int key = A[j];
		int i = j - 1;
		while (i >= 0 && A[i] > key)
		{
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = key;
	}
}
int main()
{
	//int A[] = { 5, 2, 4, 6, 1, 3 };
	int A[] = { 3, 8, 5, 4, 1, 9, -2 };
	int lenA = sizeof(A) / sizeof(A[0]);
	insertionSort(A, lenA);
	printArray(A, lenA);
}

