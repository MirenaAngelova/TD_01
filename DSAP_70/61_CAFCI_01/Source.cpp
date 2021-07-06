// Check if an array is formed by consecutive integers

// Input: { -1, 5, 4, 2, 0, 3, 1 }
// 
// Output: The array contains consecutive integers from - 1 to 5.
// 
// 
// Input : { 4, 2, 4, 3, 1 }
// 
// Output: The array does not contain consecutive integers as element 4 is repeated.

#include <iostream>
#include <unordered_set>

using namespace std;

bool isConsecutive(int A[], int lenA)
{
	int minElem = A[0];
	int maxElem = A[0];
	for (int i = 1; i < lenA; i++)
	{
		if (minElem > A[i])
		{
			minElem = A[i];
		}

		if (maxElem < A[i])
		{
			maxElem = A[i];
		}
	}
	if (maxElem - minElem != lenA -1)
	{
		return false;
	}

	unordered_set<int> visited;
	for (int i = 0; i < lenA; i++)
	{
		if (visited.find(A[i]) != visited.end())
		{
			return false;
		}
		visited.insert(A[i]);
	}
	return true;
}
int main()
{
	int A[] = { -1, 5, 4, 2, 0, 3, 1 };
	int lenA = sizeof(A) / sizeof(A[0]);

	isConsecutive(A, lenA) ?
		cout << "The array contains consecutive integers.\n"
		: cout << "The array doesn't contain consequtive integers.\n";
}

// Time complexity is O(n)
// and requires O(n) extra space