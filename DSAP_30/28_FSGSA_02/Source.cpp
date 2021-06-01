// Find subarray with given sum in an array,
// using hashing

#include<iostream>
#include<unordered_set>

using namespace std;

bool findSubarrayWithGivenSum(int A[], int lenArr, int sumTarget)
{
	unordered_set<int> sumSet;
	sumSet.insert(0);

	int sum = 0;
	for (int i = 0; i < lenArr; i++)
	{
		sum += A[i];
		cout << "i: " << i << endl;
		cout << "sum: " << sum << endl;
		cout << "sum - sumTarget is: "
			<< sum << " - "
			<< sumTarget << " = "
			<< sum - sumTarget << endl;
		for (auto j:sumSet)
		{
			cout << "sumSet[iter]: " << j << endl;
		}
		
		if (sumSet.find(sum - sumTarget) != sumSet.end())
		{
			cout << "\n\n";
			cout << "i is: " << i << endl;
			cout << "sum - sumTarget is: " 
				<< sum << " - " 
				<< sumTarget << " = " 
				<< sum - sumTarget << endl;
			cout << "\n\n";
			return true;
		}
		sumSet.insert(sum);
	}
	return false;
}

int main()
{
	int A[] = { 0, 5, -7, 1, -4, 7, 6, 1, 4, 1, 10 };
	int lenArr = sizeof(A) / sizeof(A[0]);
	int sumTarget = -3;

	if (findSubarrayWithGivenSum(A, lenArr, sumTarget))
	{
		cout << "The subarray exists";
	}
	else
	{
		cout << "The subarray doesn't exists";
	}
}