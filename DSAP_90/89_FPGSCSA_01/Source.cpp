// Find a pair with the given sum
// in a circularly sorted array

// Input:  A[] = { 10, 12, 15, 3, 6, 8, 9 }, sum = 18
// 
// Output : Pair found(3, 15)
// 
// 
// Input : A[] = { 5, 8, 3, 2, 4 }, sum = 12
// 
// Output : Pair found(4, 8)
// 
// 
// Input : A[] = { 9, 15, 2, 3, 7 }, sum = 20
// 
// Output : Pair not found

// Time complexity is O(n)
// and doesn't require any extra space

#include <stdio.h>

int findPivotIdx(int A[], int lenA)
{
	for (int i = 0; i < lenA - 1; i++)
	{
		if (A[i] > A[i + 1])
		{
			return i + 1;
		}
	}
	return lenA;
}

void findPair(int A[], int lenA, int sum)
{
	int pivotIdx = findPivotIdx(A, lenA);
	int leftShiftIdx = pivotIdx - 1;
	int rightShiftIdx = pivotIdx % lenA;

	while (leftShiftIdx != rightShiftIdx)
	{
		if (A[leftShiftIdx] + A[rightShiftIdx] == sum)
		{
			printf("Pair found{% d,% d}\n", A[rightShiftIdx], A[leftShiftIdx]);
			return;
		}

		if (A[leftShiftIdx] + A[rightShiftIdx] > sum)
		{
			leftShiftIdx = (leftShiftIdx - 1 + lenA) % lenA;
		}
		else
		{
			rightShiftIdx = (rightShiftIdx + 1) % lenA;
		}
	}
	printf("Pair not found.\n");
}
int main()
{
	int A[] = { 9, 15, 2, 3, 7 };
	int lenA = sizeof(A) / sizeof(A[0]);
	int sum = 8;

	findPair(A, lenA, sum);
}