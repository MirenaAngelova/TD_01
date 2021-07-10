// Time complexity is O(n)
// and doesn't require any extra space

#include <stdio.h>

void findSeqElems(int A[], int lenA)
{
	for (int i = 0; i < lenA; i++)
	{
		A[A[i] % lenA] += lenA;
	}

	for (int i = 0; i < lenA; i++)
	{
		if (A[i] / lenA != 0)
		{
			printf("Element %d appears %d times.\n", i, A[i] / lenA);
		}
	}

	/*for (int i = 0; i < lenA; i++)
	{
		A[i] %= lenA;
	}*/
}
int main()
{
	int A[] = { 5, 4, 4, 1, 0, 0 };
	int lenA = sizeof(A) / sizeof(A[0]);

	findSeqElems(A, lenA);
}