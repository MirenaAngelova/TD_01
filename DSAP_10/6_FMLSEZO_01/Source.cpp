// Find maximum length subarray with equal 0s and 1s

// Input: ( 0, 0, 1, 0, 1, 0 ,0 }
// Output: Largest subarray is: { 0, 1, 0, 1 } or { 1, 0, 1, 0 }

#include <iostream>
#include <unordered_map>

using namespace std;

void findMaxSubarray(int arr[], int n)
{
	unordered_map<int, int> sumStartIdx;
	sumStartIdx[0] = -1;
	
	int maxLength = 0;
	int sum = 0;
	int lastIdx = -1;

	for (int i = 0; i < n; i++)
	{
		sum += arr[i] == 0 ? -1 : 1;
		if (sumStartIdx.find(sum) != sumStartIdx.end())
		{
			if (maxLength < i - sumStartIdx[sum])
			{
				maxLength = i - sumStartIdx[sum];
				lastIdx = i;
			} 
		}
		else
		{
			sumStartIdx[sum] = i;
		}
	}

	if (lastIdx != -1)
	{
		int startIdx = lastIdx - maxLength + 1;
		unordered_map<int, int>::iterator iter;
		for (iter = sumStartIdx.begin(); iter != sumStartIdx.end(); ++iter)
		{
			cout << "First - Second: " << iter->first << " - " << iter->second << endl;
		}

		cout << "The max length of subarray { ";
		for (int k = startIdx; k < lastIdx + 1; k++)
		{
			cout << arr[k] << " ";
		}
		cout << "}\n";

		cout << "with equal amount of zeros and ones"
			<< " is: " 
			<< maxLength
			<< ",\nand starts from "
			<< startIdx 
			<< " position, and ends in " 
			<< lastIdx 
			<< " position.\n";
	}
}

int main()
{
	int arr[] = { 0, 0, 1, 0, 1, 0, 0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	findMaxSubarray(arr, n);
}
//// unordered_map::find
//#include <iostream>
//#include <string>
//#include <unordered_map>
//
//int main()
//{
//    std::unordered_map<std::string, double> mymap = {
//       {"mom",5.4},
//       {"dad",6.1},
//       {"bro",5.9} };
//
//    std::string input;
//    std::cout << "who? ";
//    getline(std::cin, input);
//
//    std::unordered_map<std::string, double>::const_iterator got = mymap.find(input);
//
//    if (got == mymap.end())
//        std::cout << "not found";
//    else
//        std::cout << got->first << " is " << got->second;
//
//    std::cout << std::endl;
//
//    return 0;
//}

// unordered_map::begin/end example
//#include <iostream>
//#include <unordered_map>
//
//int main()
//{
//    std::unordered_map<std::string, std::string> mymap;
//    mymap = { {"Australia","Canberra"},{"U.S.","Washington"},{"France","Paris"} };
//
//    std::cout << "mymap contains:";
//    for (auto it = mymap.begin(); it != mymap.end(); ++it)
//        std::cout << " " << it->first << ":" << it->second;
//    std::cout << std::endl;
//
//    std::cout << "mymap's buckets contain:\n";
//    for (unsigned i = 0; i < mymap.bucket_count(); ++i) {
//        std::cout << "bucket #" << i << " contains:";
//        for (auto local_it = mymap.begin(i); local_it != mymap.end(i); ++local_it)
//            std::cout << " " << local_it->first << ":" << local_it->second;
//        std::cout << std::endl;
//    }
//
//    return 0;
//}