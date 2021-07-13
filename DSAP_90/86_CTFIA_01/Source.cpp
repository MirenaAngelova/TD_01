// Count triplets which form 
// an inversion in an array

// Input:  A[] = [1, 9, 6, 4, 5]
// Output : The inversion count is 2
// 
// There are two inversions of size three in the array :
// (9, 6, 4) and (9, 6, 5).
// 
// 
// Input : A[] = [9, 4, 3, 5, 1]
// Output : The inversion count is 5
// 
// There are five inversions of size three in the array :
// (9, 4, 3), (9, 4, 1), (9, 3, 1), (4, 3, 1), and (9, 5, 1).

// Time complexity is O(n**3)

#include <stdio.h>

int countTripletInversions(int A[], int lenA)
{
	int countInversions = 0;
	for (int i = 0; i < lenA - 2; i++)
	{
		for (int j = i + 1; j < lenA - 1; j++)
		{
			for (int k = j + 1; k < lenA; k++)
			{
				if (A[i] > A[j] && A[j] > A[k])
				{
					countInversions++;
				}
			}
		}
	}
	return countInversions;
}
int main()
{
	int A[] = { 1, 9, 6, 4, 5 };
	int lenA = sizeof(A) / sizeof(A[0]);

	int count = countTripletInversions(A, lenA);

	printf("The inversions count is %d\n", count);
}