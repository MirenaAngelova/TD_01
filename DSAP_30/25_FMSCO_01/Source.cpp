// Find max sequence of continuous ones
// by replacing k zeros by ones

// Input: A[] = { 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0 }
// 
// For k = 0,
// The length of the longest sequence is 4 (from index 6 to 9)
// 
// For k = 1,
// The length of the longest sequence is 7 (from index 3 to 9)
// 
// For k = 2,
// The length of the longest sequence is 10 (from index 0 to 9)
// 
// For k = 3,
// The length of the longest sequence is 11 (from index 0 to 10)

#include <stdio.h>

void findLongestOnes(int A[], int lenArr, int countZerosToReplace)
{
	
	int countZeros = 0;
	int countOnes = 0;
	int startIdx = 0;
	int j = 0;
	for (int i = 0; i < lenArr; i++)
	{
		if (A[i] == 0)
		{
			countZeros++;
		}

		while (countZeros > countZerosToReplace)
		{
			if (A[j] == 0)
			{
				countZeros--;
			}
			j++;
		}

		if (countOnes < i - j + 1)
		{
			countOnes = i - j + 1;
			startIdx = j;
		}
	}

	printf("The longest sequence has length %d from index %d to %d",
		countOnes, startIdx, startIdx + countOnes - 1);
}
int main()
{
	int A[] = { 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0 };
	int lenArr = sizeof(A) / sizeof(A[0]);
	int countZerosToReplace = 2;
	findLongestOnes(A, lenArr, countZerosToReplace);
}

// Time complexity is O(n) and doesn't require any extra space