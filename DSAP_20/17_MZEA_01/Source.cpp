// Move all zeros present in an array to the end

// Input: { 6, 0, 8, 2, 3, 0, 4, 0, 1 }
// Output: { 6, 8, 2, 3, 4, 1, 0, 0, 0 }

// Time complexity is O(n)

#include <stdio.h>

void printArray(int A[], int lenArr)
{
	printf("Reordered array is: ");
	for (int i = 0; i < lenArr; i++)
	{
		printf("%d ", A[i]);
	}
}

void reorderArray(int A[], int lenArr)
{
	int nonZeroIdx = 0;
	for (int i = 0; i < lenArr; i++)
	{
		if (A[i] != 0)
		{
			A[nonZeroIdx++] = A[i];
		}
	}

	for (int j = nonZeroIdx; j < lenArr; j++)
	{
		A[j] = 0;
	}
}

int main()
{
	int A[] = { 6, 0, 8, 2, 3, 0, 4, 0, 1 };
	int lenArr = sizeof(A) / sizeof(A[0]);

	reorderArray(A, lenArr);
	printArray(A, lenArr);
}