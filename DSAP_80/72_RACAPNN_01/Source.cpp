// Rearrange an array such that it contains
// alternate positive and negative numbers

// Input: { 9, -3, 5, -2, -8, -6, 1, 3 }
// Output: { 5, -2, 9, -6, 1, -8, 3, -3 }
// 
// Input: { 9, -3, 5, -2, -8, -6 }
// Output: { 5, -2, 9, -6, -3, -8 }
// 
// Input: { 9, -3, 5, -2, 8, 6, 1, 3 }
// Output: { 5, -2, 9, -3, 8, 6, 1, 3 }

// Time complexity is O(n)
// and doesn't require any extra space

#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int partitionArray(int A[], int lenA)
{
	int pivot = 0;
	int negIdx = 0;
	for (int posIdx = 0; posIdx < lenA; posIdx++)
	{
		if (A[posIdx] < pivot)
		{
			swap(A[posIdx], A[negIdx]);
			negIdx++;
		}
	}
	return negIdx;
}

void rearrangeArray(int A[], int lenA)
{
	int posIdx = partitionArray(A, lenA);

	for (int negIdx = 0; negIdx < posIdx && posIdx < lenA; negIdx += 2, posIdx++)
	{
		swap(A[negIdx], A[posIdx]);
	}
}
int main()
{
	int A[] = { 9, -3, 5, -2, -8, -6, 1, 3 };
	int lenA = sizeof(A) / sizeof(A[0]);

	rearrangeArray(A, lenA);

	for (int i = 0; i < lenA; i++)
	{
		cout << setw(3) << A[i];
	}
}