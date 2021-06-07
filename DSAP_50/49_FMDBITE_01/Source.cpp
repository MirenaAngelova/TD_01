// Find the Minimum difference between 
// the index of two given elements
// presnt in an array

// Input:
// 
// arr = { 1, 3, 5, 4, 8, 2, 4, 3, 6, 5 }
// x = 3, y = 2
// 
// Output : Minimum difference between index is 2
// 
// 
// Input :
// 
// arr = { 1, 3, 5, 4, 8, 2, 4, 3, 6, 5 }
// x = 2, y = 5
// 
// Output : Minimum difference between index is 3
   
#include <stdio.h>
#include <limits.h>
#include <math.h>

int min(int a, int b)
{
	return a < b ? a : b;
}
int minDiff(int A[], int lenA, int x, int y)
{
	int xIdx = lenA;
	int yIdx = lenA;
	int diff = INT_MAX;


	for (int i = 0; i < lenA; i++)
	{
		if (A[i] == x) 
		{
			xIdx = i;
			if (yIdx != lenA)
			{
				diff = min(diff, abs(xIdx - yIdx));
			}
		}

		if (A[i] == y)
		{
			yIdx = i;
			if (xIdx != lenA)
			{
				diff = min(diff, abs(xIdx - yIdx));
			}
		}
	}
	return diff;
}

int main()
{
	int A[] = { 1, 3, 5, 4, 8, 2, 4, 3, 6, 5 };
	int x = 2;
	int y = 5;

	size_t lenA = sizeof(A) / sizeof(*A);
	int diff = minDiff(A, lenA, x, y);

	if (diff != INT_MAX)
	{
		printf("Minimum difference is %d", diff);
	}
	else
	{
		printf("Invalid input");
	}
}