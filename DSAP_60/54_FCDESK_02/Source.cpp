// time complexity is O(n**2),
// using O(n) extra space

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void findDistinctCount(vector<int> const& V, int k)
{
	for (int i = 0; i <= V.size() - k; i++)
	{
		unordered_set<int> distinctSet(V.begin() + i, V.begin() + i + k);
		cout << "The count of distinct elements in subarray ["
			<< i << ", " << i + k - 1 << "] is "
			<< distinctSet.size() << endl;
	}
}
int main()
{
	vector<int> V = { 2, 1, 2, 3, 2, 1, 4, 5 };
	int k = 5;
	findDistinctCount(V, k);
}