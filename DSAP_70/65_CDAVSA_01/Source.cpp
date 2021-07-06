// Count distinct absolute values in sorted array

// Input: { -1, -1, 0, 1, 1, 1 }
// Output: The total number of distinct absolute values is 2 (0 and 1)
// 
// 
// Input : { -2, -1, 0, 1, 2, 3 }
// Output: The total number of distinct absolute values is 4 (0, 1, 2 and 3)
// 
// 
// Input : { -1, -1, -1, -1 }
// Output: The total number of distinct absolute values is 1 (only 1)

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cstdlib>

using namespace std;

int countDistAbsVals(vector<int> const& V)
{
	unordered_set<int> unique;
	for (const int& v : V)
	{
		unique.insert(abs(v));
	}

	return unique.size();
}
int main()
{
	vector<int> V = { -1, -1, 0, 1, 1, 1 };

	cout << "The total umber of distinct absolute values is "
		<< countDistAbsVals(V);
}

// Time complexity is O(n)
// and requires O(n) extra space
