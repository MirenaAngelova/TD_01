// Maximum Sum Circular ( concatenate=ing end positions to start ones) Subarray

// Input: {2, 1, -5, 4, -3, 1, -3, 4, -1}
// Output: Subarray with the largest sum is{ 4, -1, 2, 1 } with sum 6.
//
// Input : {-3, 1, -3, 4, -1, 2, 1, -5, 4}
// Output: Subarray with the largest sum is{ 4, -1, 2, 1 } with sum 6.

#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

int kadane(int A[], int lenArr)
{
	int maxSum = 0;
	int currentSum = 0;
	for (int i = 0; i < lenArr; i++)
	{
		currentSum += A[i];
		currentSum = max(currentSum, 0);
		maxSum = max(maxSum, currentSum);
	}
	return maxSum;
}

int maxSumCircular(int A[], int lenArr)
{
	for (int i = 0; i < lenArr; i++)
	{
		A[i] = -A[i];
	}

	int negativeMaxSum = kadane(A, lenArr);

	for (int i = 0; i < lenArr; i++)
	{
		A[i] = -A[i];
	}

	return max(kadane(A, lenArr), accumulate(A, A + lenArr, 0) + negativeMaxSum);
}

int main()
{
	int A[] = { 2, 1, -5, 4, -3, 1, -3, 4, -1 };
	int lenArr = sizeof(A) / sizeof(A[0]);
	cout << "The max sum of largest circular subarray is: "
		<<maxSumCircular(A, lenArr);
}

// Time complexity is O(n) and doesn't require any extra space