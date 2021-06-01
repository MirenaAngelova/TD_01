// Longest Bitonic Subarray (LBS) Problem

// Input: { 3, 5, 8, 4, 5, 9, 10, 8, 5, 3, 4 }
// Output: { 4, 5, 9, 10, 8, 5, 3 }

// Input: [1, 2, 3, 4, 5]
// Output: [1, 2, 3, 4, 5]

// Input: [5, 4, 3, 2, 1]
// Output: [5, 4, 3, 2, 1]

// Time complexity is O(n) requiring O(n) extra space

#include <stdio.h>

void findLongestBitonicSub(int A[], int lenArr)
{
	const int lenSub = 11;
	int IncreasingSub[lenSub] = { 1 };
	for (int i = 1; i < lenArr; i++)
	{
		IncreasingSub[i] = 1;
		if (A[i - 1] < A[i])
		{
			IncreasingSub[i] = IncreasingSub[i - 1] + 1;
		}
	}

	int DecreasingSub[lenSub] = { 1 };
	for (int j = lenSub -2; j >= 0; j--)
	{
		DecreasingSub[j] = 1;
		if (A[j] > A[j + 1])
		{
			DecreasingSub[j] = DecreasingSub[j + 1] + 1;
		}
	}

	int lenLBS = 1;
	int startIdx = 0;
	int lastIdx = 0;

	for (int k = 0; k < lenArr; k++)
	{
		if (lenLBS < IncreasingSub[k] + DecreasingSub[k] - 1)
		{
			lenLBS = IncreasingSub[k] + DecreasingSub[k] - 1;
			startIdx = k - IncreasingSub[k] + 1;
			lastIdx = k + DecreasingSub[k] - 1;
		}
	}

	printf("The longest bitonic subarray is: ");
	for (int l = startIdx; l < lastIdx + 1; l++)
	{
		printf("%d ", A[l]);
	}
	printf("\nStarting from position %d, "
		"and ending at position %d, having length %d."
		, startIdx, lastIdx, lenLBS);


}
int main()
{
	int A[] = { 3, 5, 8, 4, 5, 9, 10, 8, 5, 3, 4 };
	int lenArr = sizeof(A) / sizeof(A[0]);
	findLongestBitonicSub(A, lenArr);
}

