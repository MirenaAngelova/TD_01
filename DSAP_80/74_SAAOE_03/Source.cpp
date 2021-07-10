// Time complexity is O(n)
// and requires O(1) extra space

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void shuffleArray(vector<int>& V, vector<int>& pos)
{
	for (int i = 0; i < V.size(); i++)
	{
		while (pos[i] != i)
		{
			swap(V[pos[i]], V[i]);
			swap(pos[pos[i]], pos[i]);
		}
	}
}
int main()
{
	vector<int> V = { 1, 2, 3, 4 ,5 };
	vector<int> pos = { 3, 2, 4, 1, 0 };
	shuffleArray(V, pos);

	for (int i = 0; i < V.size(); i++)
	{
		cout << V[i] << " ";
	}
}