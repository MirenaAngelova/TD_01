// Find all triplets formed an arithmetic progression

// Input:  A[] = { 5, 8, 9, 11, 12, 15 }
// 
// Output:
// 5 8 11
// 9 12 15
// 
// 
// Input : A[] = { 1, 3, 5, 6, 8, 9, 15 }
// 
// Output:
// 1 3 5
// 1 5 9
// 3 6 9
// 1 8 15
// 3 9 15

#include <stdio.h>

void findTriplets(int A[], int lenA)
{
	for (int j = 1; j < lenA - 1; j++)
	{
		int i = j - 1;
		int k = j + 1;
		while (i >= 0 && k < lenA)
		{
			if (A[i] + A[k] == 2 * A[j])
			{
				printf("%d %d %d\n", A[i], A[j], A[k]);
				i--;
				k++;
			}
			else if (A[i] + A[k] > 2 * A[j])
			{
				i--;
			}
			else
			{
				k++;
			}
		}
	}
}
int main()
{
	int A[] = { 1, 3, 5, 6, 8, 9, 15 };
	size_t lenA = sizeof(A) / sizeof(*A);

	findTriplets(A, lenA);
}

// Time complexity is O(n**2)
// and requires O(1) space