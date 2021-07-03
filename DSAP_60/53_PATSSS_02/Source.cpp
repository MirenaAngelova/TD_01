// Time comlexity is O(n)
// and O(1) space

#include <iostream>
#include <numeric>
#include <iterator>

using namespace std;

int partition(int A[], int lenA)
{
	int sum = accumulate(A, A + lenA, 0);
	int currentSum = 0;
	for (int i = 0; i < lenA; i++)
	{
		if (currentSum == sum - currentSum)
		{
			return i;
		}
		currentSum += A[i];
	}
	return -1;
}
int main()
{
	int A[] = { 6, -4, -3, 2, 3 };
	int lenA = sizeof(A) / sizeof(A[0]);
	int i = partition(A, lenA);

	if (i != -1)
	{
		int sum = 0;
		for (int j = 0; j < i; j++)
		{
			sum += A[j];
		}
		cout << "The two subarrays are [ ";
		copy(A, A + i, ostream_iterator<int>(cout, " "));
		cout << "] and [ ";
		copy(A + i, A + lenA, ostream_iterator<int>(cout, " "));
		cout << "] having equal sum of " << sum << endl;
	}
	

	
}