// Shuffle an array according to
// the given order of elements

// Input:
// 
// arr[] = { 1, 2, 3, 4, 5 }
// pos[] = { 3, 2, 4, 1, 0 }
// 
// Output:
// 
// arr[] = { 5, 4, 2, 1, 3 }
// 
// i.e., if pos[i] = j, then update arr[j] = arr[i] for every index i.
// In other words, update arr[pos[i]] = arr[i] for every index i.

// Time complexity is O(n)
// and requires extra space

#include <stdio.h>

void shuffleArray(int A[], int pos[], int lenA)
{
	int* aux = new int[lenA];
	for (int i = 0; i < lenA; i++)
	{
		aux[pos[i]] = A[i];
	}

	for (int i = 0; i < lenA; i++)
	{
		A[i] = aux[i];
	}
}
int main()
{
	int A[] = { 1, 2, 3, 4, 5 };
	int pos[] = { 3, 2, 4, 1, 0 };
	int lenA = sizeof(A) / sizeof(A[0]);

	shuffleArray(A, pos, lenA);
	for (int i = 0; i < lenA; i++)
	{
		printf("%d ", A[i]);
	}
}