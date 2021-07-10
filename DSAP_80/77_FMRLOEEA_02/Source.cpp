// Time complexity is linear

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

pair<int, int> findMinRange(vector<int> V1, vector<int> V2, vector<int> V3)
{
	int i = 0;
	int j = 0;
	int k = 0;
	pair<int, int> minMaxValues;
	int diff = numeric_limits<int>::max();
	while (i < V1.size() && j < V2.size() && k < V3.size())
	{
		int minValue = min(min(V1[i], V2[j]), V3[k]);
		int maxValue = max(max(V1[i], V2[j]), V3[k]);
		if (diff > maxValue - minValue)
		{
			minMaxValues = make_pair(minValue, maxValue);
			diff = maxValue - minValue;
		}

		if (V1[i] == minValue)
		{
			i++;
		}
		else if (V2[j] == minValue)
		{
			j++;
		}
		else
		{
			k++;
		}
	}
	return minMaxValues;
}
int main()
{
	vector<int> V1 = { 2, 3, 4, 8, 10, 15 };
	vector<int> V2 = { 1, 5, 12 };
	vector<int> V3 = { 7, 8, 15, 16 };

	pair<int, int> minMaxValues;
	minMaxValues = findMinRange(V1, V2, V3);
	cout << "Minimum range is "
		<< minMaxValues.first << " - "
		<< minMaxValues.second << endl;
}