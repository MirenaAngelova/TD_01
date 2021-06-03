// Find the longest continuous sequence length
// with the same sum in given binary arrays

// Input:
// X[] = { 0, 0, 1, 1, 1, 1 };
// Y[] = { 0, 1, 1, 0, 1, 0 };

// The length of the longest continuous 
// sequense with the same sum is 5

// X[0, 4] = { 0, 0, 1, 1, 1 } sum = 3
// Y[0, 4] = { 0, 1, 1, 0, 1 } sum = 3

// Time complexity is O(n)
// and doesn't require any extra space

#include <iostream>
#include <unordered_map>

using namespace std;

int findLongestSeqLen(bool X[], bool Y[], int lenX)
{
	unordered_map<int, int> diffIdxMap;
	diffIdxMap[0] = -1;
	int lenLongestSeq = 0;
	int sumX = 0;
	int sumY = 0;

	for (int i = 0; i < lenX; i++)
	{
		sumX += X[i];
		sumY += Y[i];
		int diffSumXSumY = sumX - sumY;
		if (diffIdxMap.find(diffSumXSumY) == diffIdxMap.end())
		{
			diffIdxMap[diffSumXSumY] = i;
		}
		else
		{
			lenLongestSeq = max(lenLongestSeq, i - diffIdxMap[diffSumXSumY]);
		}
	}

	return lenLongestSeq;
}
int main()
{
	bool X[] = { 0, 0, 1, 1, 1, 1 };
	bool Y[] = { 0, 1, 1, 0, 1, 0 };

	int lenX = sizeof(X) / sizeof(X[0]);
	cout << "The length of longest continuous sequence  with the same sum is: "
		<< findLongestSeqLen(X, Y, lenX);
}