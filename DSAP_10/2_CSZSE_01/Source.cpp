// Check if subarray with zero sum exists
// Input: {3, 4, -7, 3, 1, 3, 1, -4, -2, -2}
// Output: Subarray with zero-sum exists
// The subarrays with the sum of 0 are:
// {3, 4, -7}
// {4, -7, 3}
// {-7, 3, 1, 3}
// {3, 1, -4}
// {3, 1, 3, 1, -4, -2, -2}
// {3, 4, -7, 3, 1, 3, 1, -4, -2, -2}

// Using Hashing

#include <iostream>
#include <unordered_set>

using namespace std;

bool isHasZeroSumSubarray(int A[], int n)
{
	unordered_set<int> set;
	set.insert(0);
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += A[i];
		if (set.find(sum) != set.end())
		{
			return true;
		}
		else
		{
			set.insert(sum);
		}
	}

	return false;
}

int main()
{
	int A[] = { 3, 4, -7, 3, 1, 3, 1, -4, -2, -2 };
	int n = sizeof(A) / sizeof(A[0]);

	isHasZeroSumSubarray(A, n) ?
		cout << "Subarray with zero-sum exists" :
		cout << "Subarray with zero-sum doesn't exist";
}

// Complexity — O(n), where n is input size