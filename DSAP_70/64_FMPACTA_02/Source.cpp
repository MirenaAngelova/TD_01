// Time complexity is O(n)
// and requires O(n) extra space

#include <stdio.h>
#include <limits.h>

int min(int a, int b)
{
	return a < b ? a : b;
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int minimum(int a, int b, int c, int d)
{
	return min(min(a, b), min(c, d));
}
int findMinProduct(int A[], int lenA)
{
	const int len = 5;
	int leftMin[len];
	int leftMax[len];
	int rightMin[len];
	int rightMax[len];
	int minVal = INT_MAX;
	int maxVal = INT_MIN;
	int minProduct = INT_MAX;

	for (int i = 0; i < lenA; i++)
	{
		leftMin[i] = minVal;
		leftMax[i] = maxVal;

		minVal = min(minVal, A[i]);
		maxVal = max(maxVal, A[i]);
	}

	minVal = INT_MAX;
	maxVal = INT_MIN;
	
	for (int i = lenA - 1; i >= 0; i--)
	{
		rightMin[i] = minVal;
		rightMax[i] = maxVal;

		minVal = min(minVal, A[i]);
		maxVal = max(maxVal, A[i]);
	}

	for (int i = 1; i < lenA - 1; i++)
	{
		minProduct = min(minProduct, minimum(A[i] * leftMin[i] * leftMax[i],
											 A[i] * leftMin[i] * rightMin[i],
											 A[i] * leftMax[i] * rightMin[i],
											 A[i] * leftMax[i] * rightMax[i]));
	}
	return minProduct;
}
int main()
{
	int A[] = { 4, -1, 3, 5, 9 };
	int lenA = *(&A + 1) - A;

	int minProduct = findMinProduct(A, lenA);
	if (minProduct == INT_MAX)
	{
		printf("No triplet exsts.");
	}
	else
	{
		printf("The minimum product is %d", minProduct);
	}
}