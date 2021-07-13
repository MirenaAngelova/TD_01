// Find minimum removals required 
// in an array to satisfy given constraints

// Given an integer array, trim it such that 
// its maximum element becomes less than twice
// the minimum, return the minimum number
// of removals required for the conversion.

// Input: [4, 6, 1, 7, 5, 9, 2]
// 
// Output : The minimum number of removals is 4
// 
// The trimmed array is[7, 5, 9] where 9 < 2 × 5.
// 
// 
// Input : [4, 2, 6, 4, 9]
// 
// Output : The minimum number of removals is 3
// 
// The trimmed array is[6, 4] where 6 < 2 × 4.

#include <iostream>
#include <algorithm>
#include <limits>


using namespace std;

int findMinRemovals(int A[], int lenA)
{
	int maxRange = 0;
	int minNum;
	int maxNum;

	for (int i = 0; i < lenA && i < lenA - maxRange; i++)
	{
		minNum = A[i];
		maxNum = A[i];
		for (int j = i; j < lenA; j++)
		{
			minNum = min(minNum, A[j]);
			maxNum = max(maxNum, A[j]);
			if (maxNum >= minNum * 2)
			{
				break;
			}
			maxRange = max(maxRange, j - i + 1);
		}
	}
	return lenA - maxRange;
}
int main()
{
	int A[] = { 4, 6, 1, 7, 5, 9, 2 };
	int lenA = end(A) - begin(A);

	cout << "The minimum number of removals is "
		<< findMinRemovals(A, lenA) << endl;
}

// Time complexity is O(n**2)
// and doesn't require any extra space