// 4-sum problem / Quadruplets with given sum,
// using naive reqursive approach

// Input:
// 
// arr = [2, 7, 4, 0, 9, 5, 1, 3]
// sum = 20
// 
// Output : Quadruplet exists.
// 
// Below are quadruplets with the given sum 20
// 
// (0, 4, 7, 9)
// (1, 3, 7, 9)
// (2, 4, 5, 9)

#include <iostream>

using namespace std;

bool hasQuadruplet(int A[], int lenA, int sum, int count)
{
	if (sum == 0 && count == 4)
	{
		return true;
	}

	if (lenA == 0 || count > 4)
	{
		return false;
	}

	return hasQuadruplet(A, lenA - 1, sum - A[lenA - 1], count + 1) ||
		hasQuadruplet(A, lenA - 1, sum, count);
}
int main()
{
	int A[] = { 2, 7, 4, 0, 9, 5, 1, 3 };
	int lenA = sizeof(A) / sizeof(A[0]);
	int sum = 20;

	hasQuadruplet(A, lenA, sum, 0) ?
		cout << "Quadruplet exists" :
		cout << "Qudruplet doesn't exists";
}

// Time complexity is exponential and
// requires additional space for recursion (call stack)