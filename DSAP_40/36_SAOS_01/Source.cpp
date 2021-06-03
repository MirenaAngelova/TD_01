// Sort an array in one swap
// whose two elements are swapped

// Input:  A[] = [3, 8, 6, 7, 5, 9] 
// 			  OR [3, 5, 6, 9, 8, 7] 
// 		      OR [3, 5, 7, 6, 8, 9]
// 
// Output : A[] = [3, 5, 6, 7, 8, 9]

#include <iostream>
#include <algorithm>

using namespace std;

void sortInOneSwap(int A[], int lenArr)
{
	int idxFirst = -1;
	int idxSecond = -1;
	int prevElement = A[0];

	for (int i = 1; i < lenArr; i++)
	{
		if (prevElement > A[i])
		{
			if (idxFirst == -1)
			{
				idxFirst = i - 1;
				idxSecond = i;
			}
			else
			{
				idxSecond = i;
			}
		}
		prevElement = A[i];
	}
	swap(A[idxFirst], A[idxSecond]);
}
int main()
{
	int A[] = { 3, 5, 6, 9, 8, 7 };
	int lenArr = sizeof(A) / sizeof(A[0]);

	sortInOneSwap(A, lenArr);

	for (int i = 0; i < lenArr; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}

// Time complexity is O(n)