// Find the index of zero to be replaced with one to get max sequence of ones

// Input: { 0, 0, 1, 0, 1, 1, 1, 0, 1, 1 }
// Output: 7

#include <stdio.h>
int findIdxZero(int arr[], int lenArr)
{
	int maxCountOnes = 0;
	int countOnes = 0;
	int maxIdxZero = -1;
	int prevIdxZero = -1;
	int one = 1;

	for (int i = 0; i < lenArr; i++)
	{
		if (arr[i] == one) 
		{
			countOnes++;
		}
		else
		{
			countOnes = i - prevIdxZero;
			prevIdxZero = i;
		}

		if (countOnes > maxCountOnes)
		{
			maxCountOnes = countOnes;
			maxIdxZero = prevIdxZero;
		}
	}

	return maxIdxZero;
}
 


int main(void)
{
	int arr[] = { 0, 0, 1, 0, 1, 1, 1, 0, 1, 1 };
	
	int lenArr = sizeof(arr) / sizeof(arr[0]);
	
	int idxZero = findIdxZero(arr, lenArr);
	
	if (idxZero != -1)
	{
		printf("Zero to be replaced is is on position with index: %d", idxZero);
	}
	else
	{
		printf("Invalid input!");
	}
}



