// Partition an array into
// two contiguous subarrays with the same sum

// Input: {6, -4, -3, 2, 3}
// 
// Output: The two subarrays are{ 6, -4 }and { -3, 2, 3 } having equal sum of 2
// 
// 
// Input : {6, -5, 2, -4, 1}
// 
// Output: The two subarrays are{}and { 6, -5, 2, -4, 1 } having equal sum of 0
   
#include <iostream>
#include <numeric>
#include <iterator>

using namespace std;

int partition(int A[], int lenA)
{
	for (int i = 0; i < lenA; i++)
	{
		int leftSum = 0;
		int rightSum = 0;
		for (int j = 0; j < i; j++)
		{
			leftSum += A[j];
		}

		for (int j = i; j < lenA; j++)
		{
			rightSum += A[j];
		}

		if (leftSum == rightSum)
		{
			return i;
		}
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
	else
	{
		cout << "The array can't be partitioned" << endl;
	}
}

// Time complexity is O(n)