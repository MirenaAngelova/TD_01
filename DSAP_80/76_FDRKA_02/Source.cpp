// Solving the problem, using sliding window

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool contains(unordered_set<int>& unique, int elem)
{
	return unique.find(elem) != unique.end();
}
bool hasDuplicates(vector<int>& V, int k)
{
	unordered_set<int> unique;
	for (int i = 0; i < V.size(); i++)
	{
		if (contains(unique, V[i]))
		{
			return true;
		}
		unique.insert(V[i]);

		if (i >= k)
		{
			unique.erase(V[i - k]);
		}
	}
	return false;
}
int main()
{
	vector<int> V = { 5, 6, 8, 2, 4, 9 };
	int k = 4;

	if (hasDuplicates(V, k))
	{
		cout << "Duplicates found." << endl;
	}
	else
	{
		cout << "No duplicates were found." << endl;
	}
}