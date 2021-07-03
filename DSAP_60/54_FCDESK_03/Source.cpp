// Time complexity is O(n),
// using sliding window technique

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void findDistinctCount(vector<int> const& V, int k)
{
	unordered_map<int, int> elemFreq;
	int distinctCount = 0;
	for (int i = 0; i < V.size(); i++)
	{
		if (i >= k)
		{
			elemFreq[V[i - k]]--;
			if (elemFreq[V[i - k]] == 0)
			{
				distinctCount--;
			}
		}
		elemFreq[V[i]]++;
		if (elemFreq[V[i]] == 1)
		{
			distinctCount++;
		}

		if (i >= k - 1)
		{
			cout << "The count od distinct elements in subarray ["
				<< i - k + 1 << ", " << i << "] is "
				<< distinctCount << endl;
		}
	}
	
}
int main()
{
	vector <int> V = { 1, 1, 2, 1, 3 };
	int k = 3;
	findDistinctCount(V, k);
}