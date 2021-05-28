// Sort an array of zeros, ones, and twos - Dutch National Flag Problem

// Input: { 0, 1, 2, 2, 1, 0, 0, 2, 0, 1, 1, 0 }
// Output: { 0, 0, 0, 0, 0, 1, 1, 1, 1, 2, 2, 2 }

#include <stdio.h>
void swap(int A[], int i, int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

void sortArray(int A[], int lenArr)
{
	int lastIdx = lenArr - 1;
	int startIdx = 0;
	int midIdx = 0;

	int pivotOne = 1;

	while (midIdx <= lastIdx)
	{
		if (A[midIdx] < pivotOne)
		{
			swap(A, startIdx, midIdx);
			++startIdx, ++midIdx;
		}
		else if (A[midIdx] > pivotOne)
		{
			swap(A, midIdx, lastIdx);
			--lastIdx;
		}
		else
		{
			++midIdx;
		}
	}

	printf("{ ");
	for (int i = 0; i < lenArr; i++)
	{
		printf("%d ", A[i]);
	}
	printf("}");
}

int main()
{
	int A[] = { 0, 1, 2, 2, 1, 0, 0, 2, 0, 1, 1, 0 };
	int n = sizeof(A) / sizeof(A[0]);

	sortArray(A, n);
}

// Time complexity - O(n)