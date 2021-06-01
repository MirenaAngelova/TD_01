// Print subarray with max sum - Kadane's algorithm

// Input: { -2, 1, -3, 4, -1, 2, 1, -5, 4 }
// Output: The contiguous subarray with larget sum is: { 4, -1, 2, 1 }

// Input: {8, -7, -3, 5, 6, -2, 3, -4, 2}
// Output: The contiguous subarray with the largest sum is{ 5, 6, -2, 3 }

#include <iostream>

using namespace std;

void kadane(int A[], int lenArr)
{
	int maxSum = 0;
	int currentSum = 0;
	int firstIdx = 0;
	int lastIdx = 0;
	int currentFirstIdx = 0;

	for (int i = 0; i < lenArr; i++)
	{
		currentSum += A[i];
		if (currentSum < 0)
		{
			currentSum = 0;
			currentFirstIdx = i + 1;
		}
		if (maxSum < currentSum)
		{
			maxSum = currentSum;
			firstIdx = currentFirstIdx;
			lastIdx = i;
		}
	}

	cout << "The largest sum " << maxSum
		<< " of contiguous subarray ";
	for (int j = firstIdx; j < lastIdx + 1; j++)
	{
		cout << A[j] << " ";
	}
	cout << endl;
}

int main()
{
	int A[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
	int lenArr = sizeof(A) / sizeof(A[0]);
	kadane(A, lenArr);
}

// Comlexity time is O(n) and requires O(n) extra space