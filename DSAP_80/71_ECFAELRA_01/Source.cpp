// Efficiently calculate the frequency of
// all elements present in a limited range array

// Input: { 2, 3, 3, 2, 1 }
// 
// Output:
// 
// Element 1 appears once.
// Element 2 appears twice.
// Element 3 appears twice.

// Time complexity is O(n)
// and requires O(n) extra space

#include <stdio.h>

void findFreqElems(int A[], int lenA)
{
	int* freq = new int[lenA];
	for (int i = 0; i < lenA; i++)
	{
		freq[i] = 0;
	}

	for (int i = 0; i < lenA; i++)
	{
		freq[A[i]]++;
	}

	for (int num = 0; num < lenA; num++)
	{
		if (freq[num])
		{
			printf("Element %d appears %d times.\n", num, freq[num]);
		}
	}
}
int main()
{
	int A[] = { 2, 3, 3, 2, 1 };
	int lenA = sizeof(A) / sizeof(A[0]);
	findFreqElems(A, lenA);
}