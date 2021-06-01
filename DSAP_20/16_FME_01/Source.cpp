// Find majority element - Boyer-Moore majority vote algorithm
// majority element appears more than n/2 times

//Brute-Force solution

#include <stdio.h>

int findMajorityElement(int A[], int lenArr)
{
	for (int i = 0; i < lenArr/2; i++)
	{
		int count = 1;
		for (int j = i + 1; j < lenArr; j++)
		{
			if (A[i] == A[j])
			{
				count++;
			}
		}
		if (count > lenArr/2)
		{
			return A[i];
		}
	}
	return - 1;
}
int main()
{
	int A[] = { 2, 8, 7, 2, 2, 5, 2, 3, 1, 2, 2 };
	int lenArr = sizeof(A) / sizeof(A[0]);
	int majorityElement = findMajorityElement(A, lenArr);

	if (majorityElement == -1)
	{
		 printf("The majority element doesn't exist.");
	}
	else
	{
		printf("the majority element is: %d", majorityElement);
	}
}

// Time complexity O(n**2)