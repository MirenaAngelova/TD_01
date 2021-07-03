// Find all symmetric pairs in an array of pairs

// Input: {3, 4}, { 1, 2 }, { 5, 2 }, { 7, 10 }, { 4, 3 }, { 2, 5 }
// 
// Output:
// 
// {4, 3} | {3, 4}
// {2, 5} | {5, 2}

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

struct Pair
{
	int x;
	int y;
};

template<typename T, size_t n>

void findPairs(T const(&pair)[n])
{
	unordered_set<string> currentPair;
	for (int i = 0; i < n; i++)
	{
		string p = "{" + to_string(pair[i].x) 
			+ ", " + to_string(pair[i].y) + "}";

		currentPair.insert(p);

		string pSymmetric = "{" + to_string(pair[i].y) 
			+ ", " + to_string(pair[i].x) + "}";

		if (currentPair.find(pSymmetric) != currentPair.end())
		{
			cout << pSymmetric << " | " << p << endl;
		}
	}
}

int main()
{
	Pair pair[] = { {3, 4}, {1, 2}, {5, 2}, {7, 10}, {4, 3}, {2, 5} };
	findPairs(pair);
}

//Time complexity is O(n) and
// requires O(n) extra space