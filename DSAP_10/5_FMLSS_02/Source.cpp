// Solution in linear time with comlexity O(n)

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

//#include <iostream>
//#include <unordered_map>
//
//int main()
//{
//	std::unordered_map<std::string, std::string> mymap;
//	mymap = { {"Australia","Canberra"},{"U.S.","Washington"},{"France","Paris"} };
//
//	std::cout << "mymap contains:";
//	for (auto it = mymap.begin(); it != mymap.end(); ++it)
//		std::cout << " " << it->first << ":" << it->second;
//	std::cout << std::endl;
//
//	std::cout << "mymap's buckets contain:\n";
//	for (unsigned i = 0; i < mymap.bucket_count(); ++i) {
//		std::cout << "bucket #" << i << " contains:";
//		for (auto local_it = mymap.begin(i); local_it != mymap.end(i); ++local_it)
//			std::cout << " " << local_it->first << ":" << local_it->second;
//		std::cout << std::endl;
//	}
//
//	return 0;
//}

void findMaxLengthSubarray(int arr[], int n, int S)
{
	int maxLength = 0;
	int sum = 0;
	int lastIdx = -1;

	unordered_map<int, int> sumStartIdx;
	unordered_map<int, int>::iterator it;
	sumStartIdx[0] = -1;
	int c = -1;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
		//auto b = sumLastIdx.begin();
		//cout << "Begin: " << b->first << b->second << endl;
		if (sumStartIdx.find(sum) == sumStartIdx.end())
		{
			sumStartIdx[sum] = i;
		}
		
		if (sumStartIdx.find(sum - S) != sumStartIdx.end() && maxLength < i - sumStartIdx[sum - S])
		{
			
			maxLength = i - sumStartIdx[sum - S];
			lastIdx = i;
		}
	}
	
	int startIdx = lastIdx - maxLength + 1;
	printf("The subarray with length %d, and sum %d was found [", maxLength, S);
	cout << startIdx << "..." << lastIdx << "]: " << endl;
	cout << "{ ";
	for (int k = startIdx; k < lastIdx + 1; k++)
	{
		cout << arr[k] << " ";
	}
	cout << "}\n\n";
}

int main()
{
	int arr[] = { 5, 6, -5, 5, 3, 5, 3, -2, 0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int S = 8;
	findMaxLengthSubarray(arr, n, S);
}