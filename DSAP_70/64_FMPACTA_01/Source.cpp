// Find minimum product among all
// combinations of triplets in an array

// Input: { 4, -1, 3, 5, 9 }
// Output: The minimum product is - 45 (-1, 5, 9)
// 
// 
// Input : { 1, 4, 10, -2, 4 }
// Output: The minimum product is - 80 (10, 4, -2)
// 
// 
// Input : { 3, 4, 1, 2, 5 }
// Output: The minimum product is 6 (3, 1, 2)

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int findMinProduct(vector<int> V)
{
	int sizeV = V.size();
	sort(V.begin(), V.end());

	if (sizeV < 3)
	{
		return INT_MAX;
	}

	return min(V[0] * V[1] * V[2], V[sizeV - 1] * V[sizeV - 2] * V[0]);
}
int main()
{
	vector<int> V = { 4, -1, 3, 5, 9 };

	int minProduct = findMinProduct(V);
	if (minProduct == INT_MAX)
	{
		cout << "The triplet doesn't exist.";
	}
	else
	{
		cout << "The minimum product is " << minProduct << endl;
	}
}

// Time complexity is O(n*log(n))