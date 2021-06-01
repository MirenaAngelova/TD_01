// Find smallest subarray with sum greater than k,
// using sliding window

// Input: {1, 2, 3, 4, 5, 6, 7, 8}, k = 20
// Output : {6, 7, 8}
// 
// Input: {1, 2, 3, 4, 5, 6, 7, 8}, k = 7
// Output : {8}
// 
// Input: {1, 2, 3, 4, 5, 6, 7, 8}, k = 21
// Output : {5, 6, 7, 8}
// 
// Input: {1, 2, 3, 4, 5, 6, 7, 8}, k = 40
// Output : No subarray exists

#include <stdio.h>
#include<limits.h>

int min(int x, int y)
{
	return x < y ? x : y;
}

int findSmallestSubarray(int A[], int lenArr, int sumTarget)
{
	int sum = 0;
	int lenSmallestSubarray = INT_MAX;
	int j = 0;
	for (int i = 0; i < lenArr; i++)
	{
		sum += A[i];
		while (sum > sumTarget && j <= i)
		{
			lenSmallestSubarray = min(lenSmallestSubarray, i - j + 1);
			sum -= A[j];
			j++;
		}
	}
	return lenSmallestSubarray;
}

int main()
{
	int A[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int lenArr = sizeof(A) / sizeof(A[0]);
	int sumTarget = 21;

	int lenSmallestSubarray = findSmallestSubarray(A, lenArr, sumTarget);
	if (lenSmallestSubarray != INT_MAX)
	{
		printf("The smallest subarray length is %d", lenSmallestSubarray);
	}
	else
	{
		printf("No subarray found");
	}
}

// Time complexity is O(n) and doesn't require any extra space