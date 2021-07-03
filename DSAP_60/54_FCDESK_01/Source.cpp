// Find the count of distinct elements
// in every subarray of size 'k'

// Input:
// 
// arr[] = { 2, 1, 2, 3, 2, 1, 4, 5 };
// k = 5;
// 
// Output:
// 
// The count of distinct elements in subarray{ 2, 1, 2, 3, 2 } is 3
// The count of distinct elements in subarray{ 1, 2, 3, 2, 1 } is 3
// The count of distinct elements in subarray{ 2, 3, 2, 1, 4 } is 4
// The count of distinct elements in subarray{ 3, 2, 1, 4, 5 } is 5

// Time complexity is O(n**3)

#include <stdio.h>
void findDistinctCount(int A[], int lenA, int k)
{
	for (int i = 0; i <= lenA - k; i++)
	{
		int count = 0;
		for (int j = i; j < i + k; j++)
		{
			count++;
			for (int l = i; l < j; l++)
			{
				if (A[j] == A[l])
				{
					count--;
					break;
				}
			}
		}
		printf("The count of distinct elements in subarray [%d, %d]"
			" is %d\n", i, i + k - 1, count);
	}
}
int main()
{
	int A[] = { 2, 1, 2, 3, 2, 1, 4, 5 };
	int k = 5;

	int lenA = sizeof(A) / sizeof(A[0]);
	findDistinctCount(A, lenA, k);
}