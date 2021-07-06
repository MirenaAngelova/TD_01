// Find maximum length sequence of continuous ones

// Time complexity is O(n)
// and doesn't require any extra space

#include <stdio.h>

int max(int a, int b)
{
	return a > b ? a : b;
}

int findMaxSeq(int A[], int lenA)
{
	int maxLen = 0;
	int zeroIdx = -1;
	for (int i = 1; i < lenA; i++)
	{
		if (A[i] == 1)
		{
			A[i] += A[i - 1];
		}
	}

	for (int i = lenA - 1; i >= 0; i--)
	{
		maxLen = max(maxLen, A[i]);
		if (A[i])
		{
			A[i] = maxLen;
		}
		else
		{
			maxLen = 0;
		}
	}

	/*printf("A[-1] is %d\n", A[-1]);
	printf("A[lenA] is %d\n", A[lenA]);*/

	maxLen = 0;
	for (int i = 0; i < lenA; i++)
	{
		if (A[i] == 0)
		{
			if (i == 0 && maxLen < A[i + 1] + 1)
			{
				maxLen = A[i + 1] + 1;
				zeroIdx = i;
			}
			else if (i == lenA - 1 && maxLen < A[i - 1] + 1)
			{
				maxLen = A[i - 1] + 1;
				zeroIdx = i;
			}
			else if (maxLen < A[i - 1] + A[i + 1] + 1)
			{
				maxLen = A[i - 1] + A[i + 1] + 1;
				zeroIdx = i;
			}
		}
	}

	for (int i = 0; i < lenA; i++)
	{
		if (A[i])
		{
			A[i] = 1;
		}
	}
	return zeroIdx;
}
int main()
{
	int A[] = { 0, 0, 1, 0, 1, 1, 1, 0, 1, 1 };
	int lenA = sizeof(A) / sizeof(A[0]);

	int zeroIdx = findMaxSeq(A, lenA);
	if (zeroIdx != -1)
	{
		printf("Index to be replaced is %d", zeroIdx);
	}
}