// Handle duplicates
// Time complexity is O(n*log(n))
// and requires O(n) extra space

#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

void findPair(int A[], int lenA, int diff)
{
	unordered_set<int> notFound;
	sort(A, A + lenA);
	for (int i = 0; i < lenA; i++)
	{
		while (i < lenA - 1 && A[i] == A[i + 1])
		{
			i++;
		}
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