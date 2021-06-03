// Linear time solution
// Time complexity is O(n)
// and doesn't require any extra space

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min(int x, int y)
{
	return x < y ? x : y;
}

int findMaxProduct(int A[], int lenA)
{
	if (lenA == 0)
	{
		return 0;
	}

	if (lenA == 1)
	{
		return A[0];
	}
	int product = 1;
	int minAbsNegativeVal = INT_MAX;
	int countNeg = 0;
	int countPos = 0;
	int containsZero = 0;

	for (int i = 0; i < lenA; i++)
	{
		if (A[i] < 0)
		{
			countNeg++;
			minAbsNegativeVal = min(minAbsNegativeVal, abs(A[i]));
		}
		else if (A[i] > 0)
		{
			countPos++;
		}

		if (A[i] == 0)
		{
			containsZero = 1;
		}
		else
		{
			product *= A[i];
		}
	}

	if (countNeg & 1)
	{
		product /= -minAbsNegativeVal;
	}

	if (countNeg == 1 & !countPos & containsZero)
	{
		product = 0;
	}

	return product;
}
int main()
{
	int A[] = { -6, 4, -5, 8, -10, 0, 8 };
	int lenA = sizeof(A) / sizeof(A[0]);

	printf("The maximum product of a subset is %d",
		findMaxProduct(A, lenA));
}