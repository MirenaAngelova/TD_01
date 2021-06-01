// Find the subarray with given sum in an array,
// // using Sliding Window Algorithm
// 
// Input: {2, 6, 0, 9, 7, 3, 1, 4, 1, 10}, sum 15
// Output : Subarray{ 6, 0, 9 } exists with sum 15
// 
// Input : {0, 5, -7, 1, -4, 7, 6, 1, 4, 1, 10}, sum 15
// Output :
//	 Subarray{ 1, -4, 7, 6, 1, 4 } exists with sum 15
//	 or
//	 Subarray{ 4, 1, 10 } exists with sum 15
//
// Input : {0, 5, -7, 1, -4, 7, 6, 1, 4, 1, 10}, sum - 3
// Output : Subarray{ 1, -4 } exists with sum - 3

#include <stdio.h>

void findSubarrayWithGivenSum(int A[], int lenArr, int sumTarget)
{
	int sum = 0;
	int j = 0;
	for (int i = 0; i < lenArr; i++)
	{
		while (sum < sumTarget && j < lenArr)
		{
			sum += A[j];
			j++;
		}

		if (sum == sumTarget)
		{
			printf("Subarray found [%d, %d]", i, j - 1);
			return;
		}
		sum -= A[i];
	}
}
int main()
{
	int A[] = { 2, 6, 0, 9, 7, 3, 1, 4, 1, 10 };
	int lenArr = sizeof(A) / sizeof(A[0]);
	int sumTarget = 15;
	findSubarrayWithGivenSum(A, lenArr, sumTarget);
}

// Time complexity is O(n) and doesn't require any extra space