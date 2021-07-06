// Print all combinations of positive integers
// in increasing order that sums to a given number

// Input:  N = 3
// 
// 1 1 1
// 1 2
// 3
// 
// Input : N = 4
// 
// 1 1 1 1
// 1 1 2
// 1 3
// 2 2
// 4
// 
// Input:  N = 5
// 
// 1 1 1 1 1
// 1 1 1 2
// 1 1 3
// 1 2 2
// 1 4
// 2 3
// 5


#include <stdio.h>
#include <stdlib.h>

void printArray(int A[], int lenA)
{
	for (int i = 0; i < lenA; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}
void printCombinations(int A[], int i, int sum, int sumLeft)
{
	int prevNum = i > 0 ? A[i - 1] : 1;
	for (int num = prevNum; num <= sum; num++)
	{
		A[i] = num;
		if (sumLeft > num)
		{
			printCombinations(A, i + 1, sum, sumLeft - num);
		}

		if (sumLeft == num)
		{
			printArray(A, i + 1);
		}
	}
}
void findCombinations(int sum)
{
	int A[5];
	int initIdx = 0;
	printCombinations(A, initIdx, sum, sum);
}

int main()
{
	int sum = 5;
	findCombinations(sum);
}

// Time complexity is exponential
// and requires additional space for recursion (call stack)