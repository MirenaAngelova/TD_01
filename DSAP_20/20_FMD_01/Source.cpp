// Find max difference between two elements in array
// satisfied some constrains

// Input: { 2, 7, 9, 5, 1, 3, 5 }
// Output: The maximum difference is 7.
// The pair is (2, 9)

// Time complexity is O(n**2) and doesn't require any extra space

#include <stdio.h>
#include <limits.h>

int max(int diff, int diffAjAi)
{
	return diff > diffAjAi ? diff : diffAjAi;
}
int diff(int A[], int lenArr)
{
	int diff = INT_MIN;

	for (int i = 0; i < lenArr - 1; i++)
	{
		for (int j = i + 1; j < lenArr; j++)
		{
			diff = max(diff, A[j] - A[i]);
		}
	}

	return diff;
}
int main()
{
	int A[] = { 2, 7, 9, 5, 1, 3, 5 };
	int lenArr = sizeof(A) / sizeof(A[0]);

	printf("The max difference is %d", diff(A, lenArr));
}