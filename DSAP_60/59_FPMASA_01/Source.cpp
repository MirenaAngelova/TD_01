// Find a pair with a minimum
// absolute sum in an array

// Input:  A = [-6, -5, -3, 0, 2, 4, 9]
// 
// Output : Pair is(-5, 4)
// 
// (-5, 4) = abs(-5 + 4) = abs(-1) = 1, which is minimum among all pairs.

#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

void findPair(int A[], int lenA)
{
	if (lenA < 2)
	{
		return;
	}
	int lowIdx = 0;
	int highIdx = lenA - 1;
	int i;
	int j;
	int sum = INT_MAX;

	while (lowIdx < highIdx)
	{
		if (sum > abs(A[lowIdx] + A[highIdx]))
		{
			sum = abs(A[lowIdx] + A[highIdx]);
			i = lowIdx;
			j = highIdx;
		}

		if (sum == 0)
		{
			break;
		}

		A[lowIdx] + A[highIdx] < 0 ? lowIdx++ : highIdx--;
	}
	cout << "Pair is (" << A[i] 
		<< ", " << A[j] << ")" << endl;
}
int main()
{
	int A[] = { -6, -5, -3, 0, 2, 4, 9 };
	int lenA = sizeof(A) / sizeof(A[0]);
	findPair(A, lenA);
}