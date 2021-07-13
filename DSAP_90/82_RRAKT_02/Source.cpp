// Time complexity O(n)
// and requires O(n) extra space

#include <stdio.h>

void rightRotate(int A[], int lenA, int k)
{
	int* aux = new int[k];
	for (int i = 0; i < k; i++)
	{
		aux[i] = A[lenA - k + i];
	}
	for (int i = lenA - k -1; i >= 0; i--)
	{
		A[i + k] = A[i];
	}
	for (int i = 0; i < k; i++)
	{
		A[i] = aux[i];
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