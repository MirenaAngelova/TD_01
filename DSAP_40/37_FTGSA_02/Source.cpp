// Using Hashing

#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;


bool isFindTriplet(int A[], int lenArr, int sum)
{
	unordered_map<int, int> valueIdxMap;
	for (int i = 0; i < lenArr; i++)
	{
		valueIdxMap[A[i]] = i;
	}

	for (int i = 0; i < lenArr - 1; i++)
	{
		for (int j = i + 1; j < lenArr; j++)
		{
			int tempSum = sum - A[i] - A[j];
			if (valueIdxMap.find(tempSum) != valueIdxMap.end() && 
				valueIdxMap[tempSum] != i &&
				valueIdxMap[tempSum] != j)
			{
				return true;
			}
		}
	}
	return false;
}
int main()
{
	int A[] = { 2, 7, 4, 0, 9, 5, 1, 3 };
	int lenArr = sizeof(A) / sizeof(A[0]);
	int sum = 6;

	isFindTriplet(A, lenArr, sum) ?
		cout << "Triplet exists" :
		cout << "Triplet doesn't exists";
}

// Time complexity is O(n**2) and requires O(n)
// extra space