// Fisher-Yates shuffle algorithm
// //
// //
// //
// //
// //
// //
// //
// 
//
//
//
//
//
//
//
//
//
//
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int A[], int lenArr)
{
	printf("Fisher-Yard shuffled array:");
	for (int i = 0; i < lenArr; i++)
	{
		printf("%d ", A[i]);
	}
}
void swap(int A[], int i, int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}
void fisherYatesShuffle(int A[], int lenArr)
{
	// i <= j < lenArr

	/*for (int i = lenArr - 1; i >= 1; i--)
	{
		int j = rand() % (i + 1);
		printf("rand() - j are: %d - %d\n", rand(), j);
		swap(A, i, j);
	}*/

	for (int i = 0; i < lenArr - 1; i++)
	{
		int j = i + rand() % (lenArr - i);
		printf("rand() - j are: %d - %d\n", rand(), j);
		swap(A, i, j);
	}
}

int main()
{
	int A[] = { 1, 2, 3, 4, 5, 6 };
	int lenArr = sizeof(A) / sizeof(A[0]);
	
	srand(time(NULL));
	fisherYatesShuffle(A, lenArr);
	printArray(A, lenArr);
}

// Time Complexity - O(n)