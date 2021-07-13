// Right rotate an array k times

// Right rotating array three times

// Input: { 1, 2, 3, 4, 5, 6, 7 }
//
// Output: { 5, 6, 7, 1, 2, 3, 4 }

// Time complexity is O(n**2)

#include <stdio.h>

void rightRotateByOne(int A[], int lenA)
{
	int temp = A[lenA - 1];
	for (int i = lenA -2; i >= 0; i--)
	{
		A[i + 1] = A[i];
	}
	A[0] = temp;
}
void rightRotate(int A[], int lenA, int k)
{
	for (int i = 0; i < k; i++)
	{
		rightRotateByOne(A, lenA);
	}
}

int main()
{
	int A[] = { 1, 2, 3, 4, 5, 6, 7 };
	int lenA = sizeof(A) / sizeof(A[0]);
	int k = 3;

	rightRotate(A, lenA, k);
	for (int i = 0; i < lenA; i++)
	{
		printf("%d ", A[i]);
	}
}