// Time complexity is linear

#include <stdio.h>
#include <limits.h>

void printTriplet(int A[], int lenA)
{
	if (lenA < 3)
	{
		printf("Triplet doesn't exist.");
	}

	int right = 0;
	int rightMinusOne = -1;
	int rightMinusTwo = -1;

	int left = -1;
	int leftPlusOne = 0;

	for (int i = 1; i < lenA; i++)
	{
		if (A[i] > A[right])
		{
			rightMinusTwo = rightMinusOne;
			rightMinusOne = right;
			right = i;
		}
		else if (rightMinusOne == -1 || A[i] > A[rightMinusOne])
		{
			rightMinusTwo = rightMinusOne;
			rightMinusOne = i;
		}
		else if (rightMinusTwo == -1 || A[i] > A[rightMinusTwo])
		{
			rightMinusTwo = i;
		}
	}

	for (int i = 1; i < lenA; i++)
	{
		if (A[i] < A[leftPlusOne])
		{
			left = leftPlusOne;
			leftPlusOne = i;
		}
		else if (left == -1 || A[i] < A[left])
		{
			left = i;
		}
	}

	if (A[right] * A[rightMinusOne] * A[rightMinusTwo] < A[left] * A[leftPlusOne] * A[right])
	{
		printf("Triplet is (%d, %d, %d)", A[left], A[leftPlusOne], A[right]);
	}
	else
	{
		printf("Triplet is (%d, %d, %d)", A[rightMinusTwo], A[rightMinusOne], A[right]);
	}
}
int main()
{
	int A[] = { -4, 1, -8, 9, 6 };
	int lenA = sizeof(A) / sizeof(A[0]);
	printTriplet(A, lenA);
}