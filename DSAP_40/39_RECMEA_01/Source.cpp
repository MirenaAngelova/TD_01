// Reverse every consecutive m-elements of a subarray

// A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
// m = 3
// 
// Then for subarray[i, j], where i and j is
// 
// Input : i = 1, j = 7 or 8
// Output : { 1, 4, 3, 2, 7, 6, 5, 8, 9, 10}
// 
// Input:  i = 1, j = 9
// Output : { 1, 4, 3, 2, 7, 6, 5, 10, 9, 8}
// 
// Input:  i = 3, j = 5
// Output : { 1, 2, 3, 6, 5, 4, 7, 8, 9, 10}
// 
// Input:  i = 3, j = 4
// Output : { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}

// Time complexity is O(n) with O(n)
// auxiliary extra space

#include <stdio.h>

int min(int x, int y)
{
	return x < y ? x : y;
}

void swap(int A[], int i, int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

void reverseSubarray(int A[], int i, int j)
{
	while (i < j)
	{
		swap(A, i, j);
		i++;
		j--;
	}
}

void reverse(int A[], int firstIdx, int lastIdx, int countElem)
{
	if (countElem > lastIdx - firstIdx + 1)
	{
		return;
	}

	for (int i = firstIdx; i <= lastIdx; i += countElem)
	{
		if (countElem <= lastIdx - i + 1)
		{
			reverseSubarray(A, i, i + countElem - 1);
		}
	}
}


void printArray(int A[], int lenArr)
{
	printf("Reversed array is: ");
	for (int i = 0; i < lenArr; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}

int main()
{
	int A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int lenArr = sizeof(A) / sizeof(A[0]);
	int firstIdx = 1;
	int lastIdx = 8;
	int countElem = 3;
	reverse(A, firstIdx, min(lastIdx, lenArr - 1), countElem);
	printArray(A, lenArr);
}