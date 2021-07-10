// Determine the index of element 
// that satisfied given constrains in an array

// Input:  A[] = { 4, 2, 3, 5, 1, 6, 9, 7 }
// 
// Output: Index 5
// 
// All elements before index 5 are smaller, and all elements after index 5 are greater.

// Time complexity is linear
// and requires some extra space

#include <stdio.h>
#include <limits.h>

int max(int a, int b)
{
	return a > b ? a : b;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int findPosition(int A[], int lenA)
{
	int* leftMaxElems = new int[lenA];
	int* rightMinElems = new int[lenA];
	leftMaxElems[0] = INT_MIN;
	rightMinElems[lenA - 1] = INT_MAX;

	for (int pos = 1; pos < lenA; pos++)
	{
		leftMaxElems[pos] = max(leftMaxElems[pos - 1], A[pos - 1]);
	}

	for (int pos = lenA - 2; pos >= 0; pos--)
	{
		rightMinElems[pos] = min(rightMinElems[pos + 1], A[pos + 1]);
	}

	for (int pos = 1; pos < lenA; pos++)
	{
		if (leftMaxElems[pos] < A[pos] && A[pos] < rightMinElems[pos])
		{
			return pos;
		}
	}
	return -1;
}
int main()
{
	int A[] = { 4, 2, 3, 5, 1, 6, 9, 7 };
	int lenA = sizeof(A) / sizeof(A[0]);
	int position = findPosition(A, lenA);
	if (position != -1)
	{
		printf("The position of element is %d\n", position);
	}
	else
	{
		printf("Invalid input.\n");
	}
}