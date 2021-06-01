// Find minimum sum subarray of size k

// Input: {10, 4, 2, 5, 6, 3, 8, 1}, k = 3
// 
// Output : Minimum sum subarray of size 3 is(1, 3)

#include <stdio.h>
#include <limits.h>

void findMinSumSubarray(int A[], int lenArr, int sizeSubarray)
{
	int minSum = INT_MAX;
	int sum = 0;
	int lastIdx = 0;
	for (int i = 0; i < lenArr; i++)
	{
		sum += A[i];
		if (i + 1 >= sizeSubarray)
		{
			if (minSum > sum)
			{
				minSum = sum;
				lastIdx = i;
			}
			sum -= A[i + 1 - sizeSubarray];
		}
	}

	printf("Minimum sum (%d) subarray of size %d is: (%d, %d)", minSum, sizeSubarray, lastIdx + 1 - sizeSubarray, lastIdx);
}

int main()
{
	int A[] = { 10, 4, 2, 5, 6, 3, 8, 1 };
	int lenArr = sizeof(A) / sizeof(A[0]);
	int sizeSubarray = 3;
	findMinSumSubarray(A, lenArr, sizeSubarray);
}

// Time complexity is O(n) and doesn't require any extra space