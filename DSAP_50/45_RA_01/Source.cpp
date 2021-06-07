// Rearrange array such that A[A[i]]
// is set to i for every element A[i]

// Input: {1, 3, 4, 2, 0}
// Output: {4, 0, 3, 1, 2}
// 
// Explanation:
// 
// A[0] = 1, A[1] becomes 0, A[A[0]] = A[1] = 0
// A[1] = 3, A[3] becomes 1, A[A[1]] = A[3] = 1
// A[2] = 4, A[4] becomes 2, A[A[2]] = A[4] = 2
// A[3] = 2, A[2] becomes 3, A[A[3]] = A[2] = 3
// A[4] = 0, A[0] becomes 4, A[A[4]] = A[0] = 4

#include <stdio.h>

void rearrange(int A[], int lenA)
{
	printf("lenA is %d\n", lenA);
	int aux[5];

	for (int i = 0; i < lenA; i++)
	{
		aux[A[i]] = i;
	}

	for (int i = 0; i < lenA; i++)
	{
		A[i] = aux[i];
	}
}
int main()
{
	int A[] = { 1, 3, 4, 2, 0 };
	//size_t lenA = sizeof(A) / sizeof(*A);
	int lenA = *(&A + 1) - A;
	rearrange(A, lenA);
	for (int i = 0; i < lenA; i++)
	{
		printf("%d ", A[i]);
	}
}


// Time complexity is O(n)
// and requires O(n) extra space