// Find maximum product subset in array,
// using Brute_force solution
// 
// Input:  A[] = { -6, 4, -5, 8, -10, 0, 8 }
// Output: The maximum product of a subset is 15360
// 
// The subset with the maximum product of its elements is{ -6, 4, 8, -10, 8 }
// 
//  
// Input:  A[] = { 4, -8, 0, 8 }
// Output: The maximum product of a subset is 32
// 
// The subset with the maximum product of its elements is{ 4, 8 }

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void findMaxProduct(vector<int> const& subsetV, int& maxProduct)
{
	int product = 1;
	for (int i : subsetV)
	{
		product *= i;
	}
	if (subsetV.size())
	{
		maxProduct = max(maxProduct, product);
	}
}
void findPowerSet(vector<int> const& V, vector<int>& subsetV, int lenV, int& maxProduct)
{
	if (lenV == 0)
	{
		findMaxProduct(subsetV, maxProduct);
		return;
	}
	subsetV.push_back(V[lenV - 1]);
	findPowerSet(V, subsetV, lenV - 1, maxProduct);
	subsetV.pop_back();
	findPowerSet(V, subsetV, lenV - 1, maxProduct);
}
int main()
{
	vector<int> V = { -6, 4, -5, 8, -10, 0, 8 };
	int lenV = V.size();

	vector<int> subsetV;
	int maxProduct = INT_MIN;
	findPowerSet(V, subsetV, lenV, maxProduct);
	printf("The maximum product of a subset is %d", maxProduct);
}

// Time comlexity is exponential
// and requires additional space for recursion(call stack)