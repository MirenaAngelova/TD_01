// Boyer-Moore majority vote algorithm, using linear
// time and constant space

#include <stdio.h>

int findMajorityElement(int A[], int lenArr)
{
	int majorityElement;
	int count = 0;

	for (int i = 0; i < lenArr; i++)
	{
		if (count == 0)
		{
			majorityElement = A[i];
			count = 1;
		}
		else
		{
			majorityElement == A[i] ? count++ : count--;
		}
	}
	return majorityElement;
}
int main()
{
	int A[] = { 1, 8, 7, 4, 1, 2, 2, 2, 2, 2, 2 };
	int lenArr = sizeof(A) / sizeof(A[0]);

	printf("The majority element is: %d", findMajorityElement(A, lenArr));
}