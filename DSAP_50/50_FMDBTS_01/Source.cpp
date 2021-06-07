// Find the maximum absolute difference between
// the sum of two non-overlapping subarrays

// Input:  A[] = { -3, -2, 6, -3, 5, -9, 3, 4, -1, -8, 2 }
// 
// Output: The maximum absolute difference is 19.
// 
// The two subarrays are{ 6, -3, 5 }, { -9, 3, 4, -1, -8 }
// whose sum of elements are 8 and -11, 
// respectively.So, abs(8 - (-11)) or abs(-11 - 8) = 19.

#include <iostream>
#include <climits>
#include <algorithm>
#include <functional>

using namespace std;

void findMaxSumSubarray(int A[], int aux[], int i, int j, int diff)
{
	int maxCurrent = A[i];
	int maxLast = A[i];
	aux[i] = A[i];
	for (int k = i + diff; k != j; k += diff)
	{
		maxLast = max(A[k], maxLast + A[k]);
		maxCurrent = max(maxCurrent, maxLast);
		aux[k] = maxCurrent;
	}
}
void fillArrays(int A[], int lenA, int minLeft[], int minRight[], int maxLeft[], int maxRight[])
{
	findMaxSumSubarray(A, maxLeft, 0, lenA - 1 ,1);
	findMaxSumSubarray(A, maxRight, lenA - 1, 0, -1);

	transform(A, A + lenA, A, negate<int>());

	findMaxSumSubarray(A, minLeft, 0, lenA - 1, 1);
	findMaxSumSubarray(A, minRight, lenA - 1, 0, -1);

	transform(minLeft, minLeft + lenA, minLeft, negate<int>());
	transform(minRight, minRight + lenA, minRight, negate<int>());

	transform(A, A + lenA, A, negate<int>());
}
int maxAbsDiff(int A[], int lenA)
{
	int minLeft[11];
	int minRight[11];
	int maxLeft[11];
	int maxRight[11];
	fillArrays(A, lenA, minLeft, minRight, maxLeft, maxRight);

	int maxAbsDiff = INT_MIN;

	for (int i = 0; i < lenA - 1; i++)
	{
		maxAbsDiff = max(maxAbsDiff,
			max(abs(maxLeft[i] - minRight[i + 1]),
				abs(minLeft[i] - maxRight[i + 1])));
	}

	return maxAbsDiff;
}
int main()
{
	int A[] = { -3, -2, 6, -3, 5, -9, 3, 4, -1, -8, 2 };
	int lenA = sizeof(A) / sizeof(A[0]);

	cout << "The maximum absolute difference is " << maxAbsDiff(A, lenA);
}

// Time complexity is O(n)
// using extra space