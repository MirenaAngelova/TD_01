// Find an index of the maximum occuring
// element with equal probability

// Input: { 4, 3, 6, 8, 4, 6, 2, 4, 5, 9, 7, 4 }
// The maximum occuring element is 4 at
// 0, 4, 7, and 11 positions

#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <ctime>
// #include <Windows.h>
#include <cstdlib>
#include <time.h>

using namespace std;

int findIndex(vector<int> const& V)
{
	unordered_map<int, int> elemCount;
	int maxCountElem;
	for (int elem: V)
	{
		elemCount[elem]++;
	}

	for (auto pair: elemCount)
	{
		if (elemCount[maxCountElem] < pair.second)
		{
			maxCountElem = pair.first;
		}
	}
	srand(time(nullptr));
	int r = (rand() % elemCount[maxCountElem]) + 1;
	
	int index = 0;
	while (r && index < V.size())
	{
		if (V.at(index) == maxCountElem)
		{
			r--;
		}
		index++;
	}
	return index - 1;
}
int main()
{
	vector<int> V = { 4, 3, 6, 8, 4, 6, 2, 4, 5, 9, 7, 4 };

	//Sleep(2);
	cout << "The index of the maximum occuring element is "
		<< findIndex(V) << endl;
}

// Time complexity is O(n)
// and requires O(n) extra space



