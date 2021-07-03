// Find the minimum index of
// a repeating element in an array

// Input: { 5, 6, 3, 4, 3, 6, 4 }
// Output: The minimum index of the repeating element is 1
// 
// 
// Input : { 1, 2, 3, 4, 5, 6 }
// Output: Invalid Input

// Time complexity is O(n)
// and requires O(n) extra space

#include <iostream>
#include <unordered_set>

using namespace std;

int findMinIndex(int A[], int lenA)
{
	int minIdx = lenA;
	unordered_set<int> unique;
	for (int i = lenA -1; i >= 0; i--)
	{
		if (unique.find(A[i]) != unique.end())
		{
			minIdx = i;
		}
		else
		{
			unique.insert(A[i]);
		}
	}
	return minIdx;
}
int main()
{
	// int A[] = { 5, 6, 3, 4, 3, 6, 4 };
	int A[] = { 1, 2, 3, 4, 5, 6 };
	int lenA = sizeof(A) / sizeof(A[0]);

	int minIdx = findMinIndex(A, lenA);
	if (minIdx != lenA)
	{
		cout << "The minimum index of repeating element is "
			<< minIdx << endl;
	}
	else
	{
		cout << "Invalid input." << endl;
	}
}