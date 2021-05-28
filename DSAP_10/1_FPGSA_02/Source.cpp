// Using Sorting

#include <iostream>
#include <algorithm>

using namespace std;

void findPair(int arr[], int n, int sum)
{
	sort(arr, arr + n);
	int low = 0;
	int high = n - 1;

	while (low < high)
	{
		if (arr[low] + arr[high] == sum)
		{
			cout << "Pair found (" << arr[low] << ", " << arr[high] << ")"<< endl;
			return;
		}

		arr[low] + arr[high] < sum ? low++ : high--;
	}

	cout << "Pair not found";
}
int main()
{
	int arr[] = { 8, 7, 2, 5, 3, 1 };
	int sum = 10;

	int n = sizeof(arr) / sizeof(arr[0]);
	findPair(arr, n, sum);
}

// Tme complexity — O(n * log(n))