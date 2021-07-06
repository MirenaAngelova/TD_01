// Time complexity is O(n**2)
// and requires O(n) extra space

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iterator>

using namespace std;

void printArray(int A[], int i, vector<int>& V)
{
	for (int v : V)
	{
		cout << "[" << v + 1 << " - " << i << "] -- { ";
		copy(A + v + 1, A + i + 1,
			ostream_iterator<int>(cout, " "));
		cout << "}\n";
	}
}
void findSubarrays(int A[], int lenA, int sum)
{
	unordered_map<int, vector<int>> sumLastIdx;
	int currentSum = 0;
	sumLastIdx[0].push_back(-1);

	for (int i = 0; i < lenA; i++)
	{
		currentSum += A[i];
		auto iter = sumLastIdx.find(currentSum - sum);
		if (iter != sumLastIdx.end())
		{
			printArray(A, i, sumLastIdx[iter->first]);
		}
		sumLastIdx[currentSum].push_back(i);
	}
}

int main()
{
	int A[] = { 3, 4, -7, 1, 3, 3, 1, -4 };
	int sum = 7;

	int lenA = sizeof(A) / sizeof(A[0]);
	findSubarrays(A, lenA, sum);
}