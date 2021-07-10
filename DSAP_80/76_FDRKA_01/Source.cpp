// Find duplicates within a range 'k' in an array

// Input:
// 
// A[] = { 5, 6, 8, 2, 4, 6, 9 }
// k = 4
// 
// Output : Duplicates found
// 
// (element 6 repeats at distance 4 which is <= k)
// 
// 
// Input:
// 
// A[] = { 5, 6, 8, 2, 4, 6, 9 }
// k = 2
// 
// Output : No duplicates were found
// 
// (element 6 repeats at distance 4 which is > k)
// 
// 
// Input:
// 
// A[] = { 1, 2, 3, 2, 1 }
// k = 7
// 
// Output : Duplicates found
// 
// (element 1 and 2 repeats at distance 4 and 2, respectively which are both <= k)

// Time complexity is O(n) and requires O(n) extra space

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool hasDuplicates(vector<int>& V, int k)
{
	unordered_map<int, int> elemIndex;
	for (int i = 0; i < V.size(); i++)
	{
		if (elemIndex.find(V[i]) != elemIndex.end())
		{
			if (i - elemIndex[V[i]] <= k)
			{
				return true;
			}
		}
		elemIndex[V[i]] = i;
	}
	return false;
}
int main()
{
	vector<int> V = { 5, 6, 8, 2, 4, 6, 9 };
	int k = 2;

	if (hasDuplicates(V, k))
	{
		cout << "Duplicates found." << endl;
	}
	else
	{
		cout << "No duplicates were found." << endl;
	}
}
