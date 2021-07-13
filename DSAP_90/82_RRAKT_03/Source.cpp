// Time complexity O(n)
// and requires O(1) extra time

#include <stdio.h>

void reverse(int A[], int low, int high)
{
	for (int i = low, j = high; i < j; i++, j--)
	{
		int temp = A[i];
		A[i] = A[j];
		A[j] = temp;
	}
}
void rightRotate(int A[], int lenA, int k)
{
	reverse(A, lenA - k, lenA - 1);
	reverse(A, 0, lenA - k - 1);
	reverse(A, 0, lenA - 1);
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