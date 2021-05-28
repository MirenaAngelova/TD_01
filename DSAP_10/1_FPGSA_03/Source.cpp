// Using Hashing

#include <iostream>
#include <unordered_map>

using namespace std;

void findPair(int arr[], int n, int sum)
{
	unordered_map<int, int> map;
	bool isFound = false;
	for (int i = 0; i < n; i++)
	{
		if (map.find(sum - arr[i]) != map.end())
		{
			//cout << "\t" << sum - arr[i] << endl;
			cout << "Pair found (" << arr[map[sum - arr[i]]] << ", " << arr[i] << ")" << endl;
			//return;
			isFound = true;
		}
		map[arr[i]] = i;
	}
	if (isFound == false)
	{
		cout << "Pair not found";
	}
}

int main()
{
	int arr[] = { 8, 7, 2, 5, 3, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int sum = 10;

	findPair(arr, n, sum);
}
// Complexity is O(n), where n is input size