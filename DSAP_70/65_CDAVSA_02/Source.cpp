// Time complexity is O(n)
// and requires O(1) extra space

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int countDistAbsVals(vector<int> const& V)
{
	int distinctCount = V.size();
	int leftIdx = 0;
	int rightIdx = V.size() - 1;

	while (leftIdx < rightIdx)
	{
		while (leftIdx < rightIdx && V[leftIdx] == V[leftIdx + 1])
		{
			distinctCount--;
			leftIdx++;
		}

		while (leftIdx < rightIdx && V[rightIdx] == V[rightIdx - 1])
		{
			distinctCount--;
			rightIdx--;
		}

		if (leftIdx == rightIdx)
		{
			break;
		}

		int sum = V[leftIdx] + V[rightIdx];
		if (sum == 0)
		{
			distinctCount--;
			leftIdx++;
			rightIdx--;
		}
		else if (sum < 0)
		{
			leftIdx++;
		}
		else
		{
			rightIdx--;
		}
	}
	return distinctCount;
}
int main()
{
	vector<int> V = { -1, -1, 0, 1, 1, 1 };

	cout << "The total number of distinct absolute values is "
		<< countDistAbsVals(V);
}