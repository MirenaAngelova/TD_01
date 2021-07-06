// Find maximum length sequence of continuous ones

// Input: { 0, 0, 1, 0, 1, 1, 1, 0, 1, 1 }
// 
// Output: Index to be replaced is 7

// Time complexity is O(n)
// and doesn't require any extra space

#include <stdio.h>

int findMaxLenSeq(int A[], int lenA)
{
	int initIdx = 0;
	int zeroIdx = -1;
	int prevZeroIdx;
	int lastOneLen = 0;

	int zerosCount = 0;

	for (int i = 0; i < lenA; i++)
	{
		if (A[i] == 0)
		{
			prevZeroIdx = i;
			zerosCount++;
		}

		if (zerosCount == 2)
		{
			while (A[initIdx])
			{
				initIdx++;
			}
			initIdx++;
			zerosCount--;
		}

		if (lastOneLen < i - initIdx + 1)
		{
			lastOneLen = i - initIdx + 1;
			zeroIdx = prevZeroIdx;
		}
	}
	return zeroIdx;
}
int main()
{
	int A[] = { 0, 0, 1, 0, 1, 1, 1, 0, 1, 1 };
	int lenA = sizeof(A) / sizeof(A[0]);
	int index = findMaxLenSeq(A, lenA);

	if (index != -1)
	{
		printf("Index to be replaced is %d", index);
	}
	else
	{
		printf("Invalid input.");
	}
}