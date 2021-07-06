// Time complexity is O(n)
// and runs in constant space

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void addElements(vector<int> const& V1, vector<int> const& V2, vector<int> &V3)
{
	string concat;
	int sizeV1 = V1.size();
	int sizeV2 = V2.size();
	int i = 0;
	while (i < sizeV1 && i < sizeV2)
	{
		concat += to_string(V1[i] + V2[i]);
		i++;
	}

	while (i < sizeV1)
	{
		concat += to_string(V1[i++]);
	}

	while (i < sizeV2)
	{
		concat += to_string(V2[i++]);
	}

	for (char c : concat)
	{
		V3.push_back(c - '0');
	}
}
int main()
{
	vector<int> V1 = { };
	vector<int> V2 = { 4, 67, 2, 8 };

	vector<int> V3;
	addElements(V1, V2, V3);

	cout << "( ";
	for (int v : V3)
	{
		cout << v << " ";
	}
	cout << ")" << endl;
}