// Print all triplets that form
// geometric progression

// Input:  A[] = { 1, 2, 6, 10, 18, 54 }
// 
// Output:
// 2 6 18
// 6 18 54
// 
// 
// Input : A[] = { 2, 8, 10, 15, 16, 30, 32, 64 }
// 
// Output:
// 2 8 32
// 8 16 32
// 16 32 64

#include <stdio.h>

void printTriplets(int A[], int lenA)
{
	if (lenA < 3)
	{
		return;
	}

	for (int j = 1; j < lenA - 1; j++)
	{ 
		int i = j - 1;
		int k = j + 1;
		while (i)
		{
			while (i >= 0 && k < lenA && A[j] % A[i] == 0 
				&& A[k] % A[j] == 0 && A[j] / A[i] == A[k] / A[j]) 
			{
				printf("%d %d %d\n", A[i], A[j], A[k]);
				i--;
				k++;
			}

			if (i < 0 || k >= lenA)
			{
				break;
			}

			if (A[j] % A[i] == 0 && A[k] % A[j] == 0) 
			{
				if (A[j] / A[i] < A[k] / A[j])
				{
					i--;
				}
				else
				{
					k++;
				}
			}
			else if (A[j] % A[i] == 0)
			{
				k++;
			}
			else
			{
				i--;
			}
		}
	}
}
int main()
{
	int A[] = { 1, 2, 6, 18, 36, 54 };
	size_t lenA = sizeof(A) / sizeof(*A);

	printTriplets(A, lenA);
}

// Time complexity is O(n**2)
// and requires O(n) auxilary space