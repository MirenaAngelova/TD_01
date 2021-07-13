// Left rottate an array

// Left rotate an array twice
// Input: { 1, 2, 3, 4, 5 }
// 
// Output: { 3, 4, 5, 1, 2 };

#include <stdio.h>

void leftRotateByOne(int A[],int lenA)
{
	int temp = A[0];
	for (int i = 0; i < lenA; i++)
	{
		A[i] = A[i + 1];
	}
	A[lenA - 1] = temp;
}
void leftRotateTwice(int A[], int lenA, int r)
{
	for (int i = 0; i < r; i++)
	{
		leftRotateByOne(A, lenA);
	}
}
int main()
{
	int A[] = { 1, 2, 3, 4, 5 };
	int lenA = sizeof(A) / sizeof(A[0]);
	int r = 2;

	leftRotateTwice(A, lenA, r);

	for (int i = 0; i < lenA; i++)
	{
		printf("%d ", A[i]);
	}
}

// Time complexity is O(n**2)