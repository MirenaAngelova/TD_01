// Add elements of two arrays into a new array

// Input:
// a = { 23, 5, 2, 7, 87 }
// b = { 4, 67, 2, 8 }
// 
// Output: { 2, 7, 7, 2, 4, 1, 5, 8, 7 }
// 
// 
// Input:
// a = {}
// b = { 4, 67, 2, 8 }
// 
// Output: { 4, 6, 7, 2, 8 }

#include <iostream>
#include <vector>

using namespace std;

void splitSum(int sum, vector<int> &V3)
{
	if (sum > 0)
	{
		splitSum(sum/10, V3);
		V3.push_back(sum % 10);
	}
}
void addElements(vector<int> const& V1, vector<int> const& V2, vector<int> &V3)
{
	int sizeV1 = V1.size();
	int sizeV2 = V2.size();
	int i = 0;
	while (i < sizeV1 && i < sizeV2)
	{
		int sum = V1[i] + V2[i];
		splitSum(sum, V3);
		i++;
	}

	while (i < sizeV1)
	{
		splitSum(V1[i++], V3);
	}

	while (i < sizeV2)
	{
		splitSum(V2[i++], V3);
	}
}
int main()
{
	vector<int> V1 = { 23, 5, 2, 7, 87 };
	vector<int> V2 = { 4, 67, 2, 8 };

	vector<int> V3;
	addElements(V1, V2, V3);

	cout << "{ ";
	for (int v: V3)
	{
		cout << v << " ";
	}
	cout << "}" << endl;
}

// Time complexity is O(n)
// and runs in constant space