// Rearrange an array with alternate high and low elements
// Every second element becomes greater than it's left and right
// No duplicates in array

// Input: { 1, 2, 3, 4, 5, 6, 7 }
// Output: {1, 3, 2, 5, 4, 7, 6 }

//Input: { 9, 6, 8, 3, 7 }
// Output: { 6, 9, 3, 8, 7 }

// Input: { 6, 9, 2, 5, 1, 4 }
// Output: { 6, 9, 2, 5, 1, 4 }

#include <stdio.h>

void printArray(int A[], int lenArr)
{
	printf("Rearranged array is: ");
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
void rearrangeArray(int A[], int lenArr)
{
	for (int i = 1; i < lenArr; i += 2)
	{
		if (A[i] < A[i - 1])
		{
			swap(A, i, i - 1);
		}

		if (i + 1 < lenArr && A[i] < A[i + 1])
		{
			swap(A, i, i + 1);
		}
	}
}
int main()
{
	// int A[] = { 1, 2, 3, 4, 5, 6, 7 };
	// int A[] = { 9, 6, 8, 3, 7 };
	int A[] = { 6, 9, 2, 5, 1, 4 };
	int lenArr = sizeof(A) / sizeof(A[0]);

	rearrangeArray(A, lenArr);
	printArray(A, lenArr);
}

// Time complexity is O(n)