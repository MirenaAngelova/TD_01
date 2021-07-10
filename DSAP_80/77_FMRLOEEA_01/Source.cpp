// Find a minimum range with at least one element
// from each of the given arrays

// Input: 3 sorted arrays of variable length
// 
// [3, 6, 8, 10, 15]
// [1, 5, 12]
// [4, 8, 15, 16]
// 
// Output : Minimum range is 3–5
// 
// 
// Input : 3 sorted arrays of variable length
// 
// [2, 3, 4, 8, 10, 15]
// [1, 5, 12]
// [7, 8, 15, 16]
// 
// Output : Minimum range is 4–7

// Time complexity is O(n**3)

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

pair<int, int> findMinRange(vector<int>& V1, vector<int>& V2, vector<int>& V3)
{
	pair<int, int> firstThirdPair;
	int diff = numeric_limits<int>::max();
	for (int i = 0; i < V1.size(); i++)
	{
		for (int j = 0; j < V2.size(); j++)
		{
			for (int k = 0; k < V3.size(); k++)
			{
				int firstElem = min(min(V1[i], V2[j]), V3[k]);
				int thirdElem = max(max(V1[i], V2[j]), V3[k]);
				if (diff > thirdElem - firstElem)
				{
					firstThirdPair = make_pair(firstElem, thirdElem);
					diff = thirdElem - firstElem;
				}
			}
		}
	}
	return firstThirdPair;
}
int main()
{
	vector<int> V1 = { 3, 6, 8, 10, 15 };
	vector<int> V2 = { 1, 5, 12 };
	vector<int> V3 = { 4, 8, 15, 16 };

	pair<int, int> firstThirdPair;
	firstThirdPair = findMinRange(V1, V2, V3);
	cout << "Minimum range is "
		<< firstThirdPair.first << " - "
		<< firstThirdPair.second << endl;
}