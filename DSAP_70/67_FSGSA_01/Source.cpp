// Find subarray with the given sum in an array

// Input:
// 
// A[] = { 3, 4, -7, 1, 3, 3, 1, -4 }
// Sum = 7
// 
// Output :
// 
// Subarrays with the given sum are
// 
// { 3, 4 }
// { 3, 4, -7, 1, 3, 3 }
// { 1, 3, 3 }
// { 3, 3, 1 }

// Time complexity is O(n**3)

#include <stdio.h>

void printArray(int A[], int i, int j)
{
	printf("The subarray [%d..%d] - {", i, j);
	for (int k = i; k <= j; k++)
	{
		printf(" %d", A[k]);
	}
	printf(" }\n");
}
void findSubarray(int A[], int lenA, int sum)
{
	for (int i = 0; i < lenA; i++)
	{
		int currentSum = 0;
		for (int j = i; j < lenA; j++)
		{
			currentSum += A[j];
			if (currentSum == sum)
			{
				printArray(A, i, j);
			}
		}
	}
}
int main()
{
	int A[] = { 3, 4, -7, 1, 3, 3, 1, -4 };
	int sum = 7;

	int lenA = sizeof(A) / sizeof(A[0]);

	findSubarray(A, lenA, sum);
}
