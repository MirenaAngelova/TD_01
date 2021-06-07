// Quickselect algorithm

// Quickselect is a selection algorithm
// to find the k-th smallest element in 
// an unordered list. 
// It is releated to the Quicksort algorithm

// Input:  arr = [7, 4, 6, 3, 9, 1]
// k = 2
// 
// Output : k’th smallest array element is 4
// 
// Input : arr = [7, 4, 6, 3, 9, 1]
// k = 0 (k starts from 0)
// 
// Output : k’th smallest array element is 1

#include <stdio.h>
#include <stdlib.h>

#define SWAP(x, y) {int temp = x; x = y; y = temp;}
#define N (sizeof(A)/sizeof(A[0]))

int partition(int A[], int leftIdx, int rightIdx, int pivotIdx)
{
	int pivot = A[pivotIdx];
	SWAP(A[pivotIdx], A[rightIdx]);

	pivotIdx = leftIdx;
	for (int i = leftIdx; i < rightIdx; i++)
	{
		if (A[i] <= pivot)
		{
			SWAP(A[i], A[pivotIdx]);
			pivotIdx++;
		}
	}
	SWAP(A[pivotIdx], A[rightIdx]);
	return pivotIdx;
}

//int quickselect(int A[], int leftIdx, int rightIdx, int k)
//{
//	if (leftIdx == rightIdx)
//	{
//		return A[leftIdx];
//	}
//
//	int pivotIdx = leftIdx + rand() % (rightIdx - leftIdx + 1);
//	printf("pivotIdx %d\n", pivotIdx);
//	// 5, 3, 4, 3, 3
//	pivotIdx = partition(A, leftIdx, rightIdx, pivotIdx);
//
//	if (k == pivotIdx)
//	{
//		return A[k];
//	}
//	else if (k < pivotIdx)
//	{
//		return quickselect(A, leftIdx, pivotIdx - 1, k);
//	}
//	else
//	{
//		return quickselect(A, pivotIdx + 1, rightIdx, k);
//	}
//}

int quickselect(int A[], int leftIdx, int rightIdx, int k)
{
	while (1)
	{
		if (leftIdx == rightIdx)
		{
			return A[leftIdx];
		}

		int pivotIdx = leftIdx + rand() % (rightIdx - leftIdx + 1);
		pivotIdx = partition(A, leftIdx, rightIdx, pivotIdx);

		if (k == pivotIdx)
		{
			A[k];
		}
		else if (k < pivotIdx)
		{
			rightIdx = pivotIdx - 1;
		}
		else
		{
			leftIdx = pivotIdx + 1;
		}
	}
}
int main()
{
	int A[] = { 7, 4, 6, 3, 9, 1 };
	int k = 2;

	printf("k'th smallest element is %d", quickselect(A, 0, N - 1, k));
}

// Time complexity is O(n)