// Time complexity is O(n**2)

#include <stdio.h>

int countTripletInversions(int A[], int lenA)
{
	int countInversions = 0;
	for (int j = 1; j < lenA - 1; j++)
	{
		int countLeft = 0;
		for (int i = 0; i < j; i++)
		{
			if (A[i] > A[j])
			{
				countLeft++;
			}
		}
		int countRight = 0;
		for (int k = j + 1; k < lenA; k++)
		{
			if (A[j] > A[k])
			{
				countRight++;
			}
		}
		countInversions += countLeft * countRight;
	}
	return countInversions;
}
int main()
{
	int A[] = { 1, 9, 6, 4, 5 };
	int lenA = sizeof(A) / sizeof(A[0]);

	int countInversions = countTripletInversions(A, lenA);
	printf("The inversions count is %d\n", countInversions);
}