// Time complexity is O(n) and doesn't require any extra space

#include <stdio.h>
#include <stdlib.h>

void findLBS(int A[], int lenArr)
{
	int maxLen = 1;
	int lastIdx = 0;
	int i = 0;
	while (i < lenArr - 1)
	{
		int len = 1;
		while (i < lenArr - 1 && A[i] < A[i + 1])
		{
			i++;
			len++;
		}

		while (i < lenArr - 1 && A[i] > A[i + 1])
		{
			i++;
			len++;
		}

		if (maxLen < len)
		{
			maxLen = len;
			lastIdx = i;
		}
	}

	printf("The longest bitonic subarray is: ");
	for (int l = lastIdx - maxLen + 1; l < lastIdx + 1; l++)
	{
		printf("%d ", A[l]);
	}
	printf("\nStarting from position %d, "
		"and ending at position %d, having length %d."
		, lastIdx - maxLen + 1, lastIdx, maxLen);
}
int main()
{
	int A[] = { 3, 5, 8, 4, 5, 9, 10, 8, 5, 3, 4 };
	int lenArr = sizeof(A) / sizeof(A[0]);

	findLBS(A, lenArr);
}