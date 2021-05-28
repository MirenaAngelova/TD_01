// Using multimap to print all subarrays

#include <iostream>
#include <unordered_map>

using namespace std;

void printAllSubarrays(int arr[], int n)
{
	unordered_multimap<int, int> map;
	map.insert(pair<int, int>(0, -1));
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
		if (map.find(sum) != map.end())
		{
			auto it = map.find(sum);
			while (it != map.end() && it->first == sum)
			{
				cout << "Subarray found [" << it->second + 1 << "-" << i << "]" << endl;
				it++;
			}
		}
		map.insert(pair<int, int>(sum, i));
	}
}

int main()
{
	int arr[] = {3, 4, -7, 3, 1, 3, 1, -4, -2, -2};
	int n = sizeof(arr) / sizeof(arr[0]);
	printAllSubarrays(arr, n);
}