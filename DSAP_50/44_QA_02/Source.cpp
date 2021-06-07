#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> A = { 7, 4, 6, 3, 9, 1 };

	const size_t k = 2;

	nth_element(A.begin(), A.begin() + k, A.end());
	cout << "The smallest k-th element is " << A[k];
}
