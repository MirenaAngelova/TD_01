// Time complexity is O(n)
// and doesn't require any extra space

#include <stdio.h>

void rearrange(int A[], int lenA)
{
	for (int i = 0; i < lenA; i++)
	{
		A[A[i] % lenA] += i * lenA;
	}

	for (int i = 0; i < lenA; i++)
	{
		A[i] /= lenA;
	}
}
int main()
{
	int A[] = { 1, 3, 4, 2, 0 };
	size_t lenA = sizeof(A) / sizeof(*A);

	rearrange(A, lenA);
	
	for (int i = 0; i < lenA; i++)
	{
		printf("%d ", A[i]);
	}
}