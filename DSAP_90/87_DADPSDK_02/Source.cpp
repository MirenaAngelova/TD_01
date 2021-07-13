// Time comlexity is O(n)
// and requires O(n) extra space

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool findPairs(vector<int>& V, int k)
{
	if (V.size() & 1)
	{
		return false;
	}

	unordered_map<int, int> remainderCount;
	for (auto v : V)
	{
		remainderCount[v % k] += 1;
	}
	/*for (auto it = remainderCount.begin(); it != remainderCount.end(); it++)
	{
		cout << "it.first is " << it->first << endl;
		cout << "it.second is " << it->second << endl;
	}*/

	for (auto& pair : remainderCount)
	{
		int remainder = pair.first;
		int count = pair.second;
		if (remainder == 0)
		{
			if (count % 2 != 0)
			{
				return false;
			}
		}
		else if (count != remainderCount[k - remainder])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	// vector<int> V = { 2, 9, 4, 1, 3, 5 };
	vector<int> V = { 3, 1, 2, 6, 9, 4 };
	int k = 6;

	if (findPairs(V, k))
	{
		cout << "Pairs can be formed.\n";
	}
	else
	{
		cout << "Pairs can't be formed.\n";
	}
}