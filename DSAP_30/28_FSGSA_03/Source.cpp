// Find a subarray with given sum in an array,
// using hashing

#include <iostream>
#include <unordered_map>

using namespace std;

void findSubarrayWithGivenSum(int A[], int lenArr, int sumTarget)
{
	unordered_map<int, int> sumIndexMap;
	sumIndexMap.insert(pair<int, int>(0, -1));
	int sum = 0;
	for (int i = 0; i < lenArr; i++)
	{
		sum += A[i];
		if (sumIndexMap.find(sum - sumTarget) != sumIndexMap.end())
		{
			cout << "Subarray found ["
				<< sumIndexMap[sum - sumTarget] + 1
				<< ", " << i << "]"
				<< endl;
			return;
		}
		sumIndexMap.insert(pair<int, int>(sum, i));
	}
}
int main()
{
	int A[] = { 0, 5, -7, 1, -4, 7, 6, 1, 4, 1, 10 };
	int lenArr = sizeof(A) / sizeof(A[0]);
	int sumTarget = 15;

	findSubarrayWithGivenSum(A, lenArr, sumTarget);
}

// Time complexity is O(n) and doesn't require any extra space