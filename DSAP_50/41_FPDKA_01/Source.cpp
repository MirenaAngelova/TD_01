// Find pairs with difference k in an array

// Input:
// 
// arr = [1, 5, 2, 2, 2, 5, 5, 4]
// k = 3
// 
// Output :
// 
// 	(2, 5) and (1, 4)

#include <iostream>
#include <unordered_set>

using namespace std;

void findPair(int A[], int lenA, int diff)
{
	unordered_set<int> notFound;
	for (int i = 0; i < lenA; i++)
	{
		if (notFound.find(A[i] - diff) != notFound.end())
		{
			cout << "(" << A[i] - diff
				<< ", " << A[i] << ")\n";
		}

		if (notFound.find(A[i] + diff) != notFound.end())
		{
			cout << "(" << A[i] + diff
				<< ", " << A[i] << ")\n";
		}
		notFound.insert(A[i]);
	}
}
int main()
{
	int A[] = { 1, 5, 2, 2, 2, 5, 5, 4 };
	int lenA = sizeof(A) / sizeof(A[0]);
	int diff = 3;
	findPair(A, lenA, diff);
}

// Time complexity is O(n) and
// requires O(n) extra space