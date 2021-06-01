// Linear-time solution
// Time complexity is O(n)

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findMajorityElement(vector<int> const &inputVector)
{
	int lenInput = inputVector.size();
	unordered_map<int, int> valueCountMap;
	/*for (int i = 0; i < lenInput; i++)
	{
		if (++valueCountMap[inputVector[i]] > lenInput / 2)
		{
			return inputVector[i];
		}
	}*/

	for (int i = 0; i < lenInput; i++)
	{
		valueCountMap[inputVector[i]]++;
	}

	for ( auto pair: valueCountMap)
	{
		if (pair.second > lenInput / 2)
		{
			return pair.first;
		}
	}
	return -1;
}
int main()
{
	vector<int> inputVector = { 2, 8, 7, 2, 2, 5, 2, 3, 1, 2, 2 };
	int majorityElement = findMajorityElement(inputVector);

	if (majorityElement == -1)
	{
		cout << "The majority element doesn't exist.";
	}
	else
	{
		cout << "The majority element is: "
			<< majorityElement;
	}
}