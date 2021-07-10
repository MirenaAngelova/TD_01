// Time complexity is O(n)
// and requires extra space

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void shuffleArray(vector<int> &V, vector<int> &pos)
{
	int sizeV = V.size();
	unordered_map<int, int> indexElem;
	for (int i = 0; i < sizeV; i++)
	{
		indexElem[pos[i]] = V[i];
	}

	for (auto &item : indexElem)
	{
		V[item.first] = item.second;
	}
}
int main()
{
	vector<int> V = { 1, 2, 3, 4, 5 };
	vector<int> pos = { 3, 2, 4, 1, 0 };

	shuffleArray(V, pos);

	for (int v : V)
	{
		cout << v << " ";
	}
}