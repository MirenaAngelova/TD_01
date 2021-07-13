// Time complexity is O(n)
// and requires extra space

#include <stdio.h>

void leftRotate(int A[], int lenA, int r)
{
	int* aux = new int[r];
	for (int i = 0; i < r; i++)
	{
		aux[i] = A[i];
	}

	for (int i = r; i < lenA; i++)
	{
		A[i - r] = A[i];
	}

	for (int i = lenA - r; i < lenA; i++)
	{
		A[i] = aux[i - (lenA - r)];
	}
}
int main()
{
	int A[] = { 1, 2, 3, 4, 5 };
	int lenA = sizeof(A) / sizeof(A[0]);
	int r = 2;
	leftRotate(A, lenA, r);

	for (int i = 0; i < lenA; i++)
	{
		printf("%d ", A[i]);
	}
}