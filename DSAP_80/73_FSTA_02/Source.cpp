// Time complexity is linear 
// and doesn't require any extra space

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

void findTriplet(vector<int> V, tuple<int, int, int> triplet)
{
	int tempMinIdx = 0;
	int minIdx = -1;
	int midIdx = -1;
	int sizeV = V.size();
	if (sizeV < 3)
	{
		cout << "Triplet doesn't exist." << endl;
	}

	for (int i = 1; i < sizeV; i++)
	{
		if (V[tempMinIdx] > V[i])
		{
			tempMinIdx = i;
		}
		else if (midIdx == -1)
		{
			minIdx = tempMinIdx;
			midIdx = i;
		}
		else if (V[midIdx] >= V[i])
		{
			minIdx = tempMinIdx;
			midIdx = i;
		}
		else
		{
			triplet = make_tuple(minIdx, midIdx, i);
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
		;
	findTriplet(V, triplet);
}