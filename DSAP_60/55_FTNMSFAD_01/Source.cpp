// Find two numbers with maximum sum
// formed by array digits

// Input: { 4, 6, 2, 7, 9, 8 }
// Output: The two numbers with maximum sum are 974 and 862
// 
// 
// Input : { 9, 2, 5, 6, 0, 4 }
// Output: The two numbers with maximum sum are 952 and 640

// Time complexity is O(n*log(n))
// and doesn't require any extra space

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> findMaxSum(vector<int> V)
{
	sort(V.rbegin(), V.rend());
	int even = 0;
	int odd = 0;
	for (int i = 0; i < V.size(); i += 2)
	{
		even = even * 10 + V[i];
	}

	for (int j = 1; j < V.size(); j += 2)
	{
		odd = odd * 10 + V[j];
	}
	return make_pair(even, odd);
}
int main()
{
	vector<int> V = { 4, 6, 2, 7, 9, 8 };
	pair<int, int> p = findMaxSum(V);
	cout << "Two numbers with maximum sum are "
		<< p.first << " and " << p.second
		<< endl;
}