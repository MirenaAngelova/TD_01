// Find equilibrium index of an array

// Input: { 0, -3, 5, -4, -2, 3, 1, 0 }
// Output: 0, 3, 7

#include <iostream>
#include <numeric>

using namespace std;

void equilibriumIndex(int A[], int lenArr)
{
	int totalSum = accumulate(A, A + lenArr, 0);
	int rightSum = 0;
	for (int i = lenArr - 1; i >= 0; i--)
	{
		if (rightSum == totalSum - (A[i] + rightSum))
		{
			printf("Equilibrium index found: %d\n", i);
		}
		rightSum += A[i];
	}
}

int main()
{
	int A[] = { 0, -3, 5, -4, -2, 3, 1, 0 };
	int lenArr = sizeof(A) / sizeof(A[0]);

	equilibriumIndex(A, lenArr);
}

// Time complexity is O(n)