// Time complexity is O(n)
// and requires O(1) extra space

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
void leftRotate(int A[], int lenA, int r)
{
	reverse(A, 0, r - 1);
	reverse(A, r, lenA - 1);
	reverse(A, 0, lenA - 1);
}
int main()
{
	int A[] = { 1, 2, 3, 4 , 5 };
	int lenA = sizeof(A) / sizeof(A[0]);
	int r = 2;

	leftRotate(A, lenA, r);
	for (int i = 0; i < lenA; i++)
	{
		printf("%d ", A[i]);
	}
}