// Segregate positive and negative integers in linear time

// Input:  [9, -3, 5, -2, -8, -6, 1, 3]
// 
// Output: [-3, -2, -8, -6, 5, 9, 1, 3]

// Time complexity is O(n)
// and doesn't require any extra space

#include <iostream>
#include <algorithm>

using namespace std;

void segregateIntegers(int A[], int lenA)
{
	int pivotIdx = 0;
	for (int i = 0; i < lenA; i++)
	{
		if (A[i] < 0)
		{
			swap(A[i], A[pivotIdx]);
			pivotIdx++;
		}
	}
}
int main()
{
	int A[] = { 9, -3, 5, -2, -8, -6, 1, 3 };
	int lenA = sizeof(A) / sizeof(A[0]);

	segregateIntegers(A, lenA);
	for (int i = 0; i < lenA; i++)
	{
		cout << A[i] << " ";
	}
}