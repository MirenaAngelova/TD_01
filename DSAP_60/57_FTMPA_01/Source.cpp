// Find a triplet having a maximum product in an array

// Input: { -4, 1, -8, 9, 6 }
// Output: The triplet having the maximum product is(-4, -8, 9)
// 
// Input : { 1, 7, 2, -2, 5 }
// Output: The triplet having the maximum product is(7, 2, 5)

// Time complexity is O(n*log(n))

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findTriplet(vector<int> V)
{
	sort(V.begin(), V.end());
	int sizeV = V.size();
	if (sizeV < 3)
	{
		cout << "No triplet exists. The array has less then 3 elements.";
	}
	else
	{
		cout << "The triplet having maximum product is: ( ";
	}
	if (V[sizeV - 1] * V[sizeV - 2] * V[sizeV - 3] > V[0] * V[1] * V[sizeV - 1])
	{
		cout << V[sizeV - 3] << ", "
			<< V[sizeV - 2] << ", "
			<< V[sizeV - 1] << " )\n";
	}
	else
	{
		cout << V[0] << ", "
			<< V[1] << ", "
			<< V[sizeV - 1] << " )\n";
	}
}
int main()
{
	vector<int> V = { -4, 1, -8, 9, 6 };
	findTriplet(V);
}