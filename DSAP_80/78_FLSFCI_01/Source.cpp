// Find the longest subsequence 
// formed by consecutive integers

// Input: { 2, 0, 6, 1, 5, 3, 7 }

// Output: { 2, 0, 1, 3 }

// Time complexity is O(n)
// and requires O(n) extra space

#include <iostream>
#include <vector>
#include < unordered_set>

using namespace std;

int findMaxLenSubseq(vector<int>& V)
{
	unordered_set<int> unique(V.begin(), V.end());
	int maxLen = 1;
	for (int num: unique)
	{
		if (unique.find(num - 1) == unique.end())
		{
			int len = 1;
			while (unique.find(num + len) != unique.end())
			{
				len++;
			}
			maxLen = max(maxLen, len);
		}
	}
	return maxLen;
}
int main()
{
	vector<int> V = { 2, 0, 6, 1, 5, 3, 7 };

	cout << "The length of the maximum consecutive subsequence is "
		<< findMaxLenSubseq(V);
}