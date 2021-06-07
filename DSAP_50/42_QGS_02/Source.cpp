// Efficient solution, using hashing

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

typedef pair<int, int> Pair;

bool hasQuadruplet(int A[], int lenA, int sum)
{
	unordered_map<int, vector<Pair>> sumIndices;

	for (int i = 0; i < lenA - 1; i++)
	{
		for (int j = i + 1; j < lenA; j++)
		{
			int currentDiff = sum - A[i] - A[j];
			if (sumIndices.find(currentDiff) != sumIndices.end())
			{
				for (auto pair : sumIndices.find(currentDiff)->second)
				{
					int firstIdx = pair.first;
					int secondIdx = pair.second;
					if (firstIdx != i && firstIdx != j && secondIdx != i && secondIdx != j)
					{
						cout << "Quadruplet found: "
							<< A[firstIdx] << ", "
							<< A[secondIdx] << ", "
							<< A[i] << ", "
							<< A[j] << endl;
						return true;
					}
				}
			}
			sumIndices[A[i] + A[j]].push_back({ i, j });
		}
	}
	return false;
}
int main()
{
	int A[] = { 2, 7, 4, 0, 9, 5, 1, 3 };
	int lenA = sizeof(A) / sizeof(A[0]);
	int sum = 20;

	if (!hasQuadruplet(A, lenA, sum))
	{
		cout << "Quadruplet doesn't exists";
	}
}

// Time complexity is O(n**3) and
// requires O(n**2) extra space