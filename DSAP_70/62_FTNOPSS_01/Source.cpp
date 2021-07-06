// Find two non-overlapping pairs
// having the same sum in an array

// Input: { 3, 4, 7, 3, 4 }
// Output: (4, 3) and (3, 4)
// 
// 
// Input : { 3, 4, 7, 4 }
// Output: No non - overlapping pairs is present in the array
// 
// The pairs(3, 4) and (3, 4) are overlapping as the index of 3 is the same in both pairs.

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

typedef pair<int, int> Pair;

void findPairs(int A[], int lenA)
{
	unordered_map<int, vector<Pair>> sumPairIdx;
	for (int i = 0; i < lenA - 1; i++)
	{
		for (int j = i + 1; j < lenA; j++)
		{
			int sum = A[i] + A[j];
			if (sumPairIdx.find(sum) != sumPairIdx.end())
			{
				for (auto pair : sumPairIdx.find(sum)->second)
				{
					int m = pair.first;
					int n = pair.second;
					if (m != i && m != j && n != i && n != j)
					{
						cout << "First pair is (" << A[i] 
							<< ", " << A[j] << ")" << endl;
						cout << "Second pair is (" << A[m]
							<< ", " << A[n] << ")" << endl;
						return;
					}
				}
			}
			sumPairIdx[sum].push_back({ i, j });
		}
	}
	cout << "No non-overlapping pairs exist.";
}
int main()
{
	int A[] = { 3, 4, 7, 3, 4 };
	int lenA = sizeof(A) / sizeof(A[0]);
	findPairs(A, lenA);
}