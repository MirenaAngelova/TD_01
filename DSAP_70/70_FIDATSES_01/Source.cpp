// Find the index of element that divides an array
// into two non-empty subarrays with equal sum

// Time complexity is O(n)
// and requires extra space

#include <stdio.h>

void findBreakPoint(int A[], int lenA)
{
	int sum = 0;

	for (int i = 0; i < lenA; i++)
	{
		sum += A[i];
	}

	int leftSum = A[0];
	for (int i = 1; i < lenA - 1; i++)
	{
		if (leftSum == sum - A[i] - leftSum)
		{
			printf("The index is %d\n", i);
		}
		leftSum += A[i];
	}
}
int main()
{
	int A[] = { -1, 6, 3, 1, -2, 3, 3 };
	int lenA = sizeof(A) / sizeof(A[0]);
	findBreakPoint(A, lenA);
}