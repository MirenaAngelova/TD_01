// Using partitionic logic of Quicksort

#include <stdio.h>

void printArray(int A[], int lenArr)
{
	printf("Sorted Array is: ");
	for (int i = 0; i < lenArr; i++)
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

void partition(int A[], int lenArr)
{
	int j = 0;
	for (int i = 0; i < lenArr; i++)
	{
		if (A[i] != 0)
		{
			swap(A, i, j);
			j++;
		}
	}
}

int main()
{
	int A[] = { 6, 0, 8, 2, 3, 0, 4, 0, 1 };
	int lenArr = sizeof(A) / sizeof(A[0]);

	partition(A, lenArr);
	printArray(A, lenArr);
}

// Time complexity is O(n)