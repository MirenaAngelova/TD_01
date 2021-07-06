// Time complexity is O(n)
// and requires constant space

#include <stdio.h>
#include <limits.h>

int min(int a, int b)
{
	return a < b ? a : b;
}

int findMinProduct(int A[], int lenA)
{
	if (lenA < 3)
	{
		return INT_MAX;
	}

	int min1 = A[0];
	int min2 = INT_MAX;
	int min3 = INT_MAX;

	int max1 = A[0];
	int max2 = INT_MIN;

	int minProduct;

	for (int i = 1; i < lenA; i++)
	{
		if (min1 > A[i])
		{
			min3 = min2;
			min2 = min1;
			min1 = A[i];
		}
		else if (min2 > A[i])
		{
			min3 = min2;
			min2 = A[i];
		}
		else if (min3 > A[i])
		{
			min3 = A[i];
		}
	}

	for (int i = 0; i < lenA; i++)
	{
		if (max1 < A[i])
		{
			max2 = max1;
			max1 = A[i];
		}
		else if (max2 < A[i])
		{
			max2 = A[i];
		}
	}
	
	minProduct = min(min1 * min2 * min3, min1 * max1 * max2);
	return minProduct;
}
int main()
{
	int A[] = { 4, -1, 3, 5, 9 };
	int lenA = sizeof(A) / sizeof(A[0]);

	int minProduct = findMinProduct(A, lenA);

	if (minProduct == INT_MAX)
	{
		printf("No triplet exists.");
	}
	else
	{
		printf("The minimum pruduct is %d\n", minProduct);
	}
}