// Find the sorted triplet in an array

// Input:  A[] = { 5, 4, 3, 7, 6, 1, 9 }
// 
// Output: Any one of the following triplets :
// 
// (5, 7, 9)
// (4, 7, 9)
// (3, 7, 9)
// (5, 6, 9)
// (4, 6, 9)
// (3, 6, 9)

// Time complexity is O(n)
// and requires O(n) extra space

#include <iostream>
#include <vector>
#include <tuple>
#include <functional>

using namespace std;

void findTriplet(vector<int> const& V, tuple<int, int, int> triplet)
{
	int sizeV = V.size();
	int minIdx = 0;
	int maxIdx = sizeV - 1;
	vector<int> minIndices(sizeV, -1);
	vector<int> maxIndices(sizeV, -1);
	if (sizeV < 3)
	{
		cout << "Triplet doesn't exist." << endl;
	}

	for (int i = 1; i < sizeV; i++)
	{
		if (V[minIdx] > V[i])
		{
			minIdx = i;
		}
		else
		{
			minIndices[i] = minIdx;
		}
	}

	for (int i = sizeV - 2; i >= 0; i--)
	{
		if (V[maxIdx] < V[i])
		{
			maxIdx = i;
		}
		else
		{
			maxIndices[i] = maxIdx;
		}
	}

	for (int i = 0; i < sizeV; i++)
	{
		if (minIndices[i] != -1 && maxIndices[i] != -1)
		{
			triplet = make_tuple(minIndices[i], i, maxIndices[i]);
			cout << "Triplet found: { "
				<< V[get<0>(triplet)] << ", "
				<< V[get<1>(triplet)] << ", "
				<< V[get<2>(triplet)] << " }" << endl;
			return;
		}
	}
}
int main()
{
	vector<int> V = { 5, 4, 3, 7, 6, 1, 9 };
	tuple<int, int, int> triplet;
	findTriplet(V, triplet);
}