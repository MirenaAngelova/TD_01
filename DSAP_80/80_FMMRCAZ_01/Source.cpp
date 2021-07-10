// Fimd minimum moves required for converting
// a given array to an array of zeros

//The minimum number of moves required to convert
// an array{ 0, 0, 0 } to array{ 8, 9, 8 } is 7.
//
// The optimal sequence is 3 increment operations,
// followed by 3 double operations,
// and a single increment operation, as shown below :
//
//     { 0, 0, 0 } — > { 1, 0, 0 }
// — > { 1, 1, 0 } — > { 1, 1, 1 }
// — > { 2, 2, 2 } — > { 4, 4, 4 }
// — > { 8, 8, 8 } — > { 8, 9, 8 }

// Find the minimum number of moves 
// required for converting a given array
// to an array of zeroes using only 
// the decrement and reduce operation.

// Time complexity is O(n*log(n))
// and runs in constant space

#include <stdio.h>

int findMinMoves(int A[], int lenA)
{
	int minMoves = 0;
	while (1)
	{
		int countZeros = 0;
		for (int i = 0; i < lenA; i++)
		{
			if (A[i] % 2 == 1)
			{
				--A[i];
				++minMoves;
			}
			if (A[i] == 0)
			{
				countZeros++;
			}
		}
		if (countZeros == lenA)
		{
			break;
		}

		for (int i = 0; i < lenA; i++)
		{
			A[i] /= 2;
		}
		minMoves++;
	}
	return minMoves;
}
int main()
{
	int A[] = { 8, 9, 8 };
	int lenA = sizeof(A) / sizeof(A[0]);

	printf("The minimum moves required is %d\n", findMinMoves(A, lenA));
}