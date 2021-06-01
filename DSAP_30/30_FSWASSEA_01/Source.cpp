// Find the smallest window in array sorting
// to sort entire array

// Input: { 1, 2, 3, 7, 5, 6, 4, 8 }
// Output: Sort the array from index 3 to 6
// 
// Input : { 1, 3, 2, 7, 5, 6, 4, 8 }
// Output: Sort the array from index 1 to 6

#include <iostream>
#include <climits>

using namespace std;

void findSmallestSubarray(int A[], int lenArr)
{
	int firstIdx = -1;
	int lastIdx = -1;
	int maxValue = INT_MIN;
	for (int i = 0; i < lenArr; i++)
	{
		if (maxValue < A[i])
		{
			maxValue = A[i];
		}

		if (A[i] < maxValue)
		{
			lastIdx = i;
		}
	}

	int minValue = INT_MAX;
	for (int j = lenArr - 1; j >= 0; j--)
	{
		if (minValue > A[j])
		{
			minValue = A[j];
		}

		if (A[j] > minValue)
		{
			firstIdx = j;
		}
	}
	cout << "The smallest subarray sorting is from index "
		<< firstIdx << " to "
		<< lastIdx << endl;
}
int main()
{
	int A[] = { 1, 2, 3, 7, 5, 6, 4, 8 };
	int lenArr = sizeof(A) / sizeof(A[0]);

	findSmallestSubarray(A, lenArr);
}

// Time complexity is O(n) and doesn't require any extra space