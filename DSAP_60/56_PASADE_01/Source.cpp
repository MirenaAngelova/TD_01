// Print all subarrays of an array
// having distinct elements

// Input:  A[] = { 5, 2, 3, 5, 4, 3 }
// 
// Output: The largest subarrays with all distinct elements are :
// 
// { 5, 2, 3 }
// { 2, 3, 5, 4 }
// { 5, 4, 3 }

// Time complexity is O(n)
// and requires O(n) extra space

#include <iostream>
#include <unordered_map>

using namespace std;

void printSubarray(int A[], int lenA, int leftIdx, int rightIdx)
{
	if (leftIdx < 0 || leftIdx > rightIdx || rightIdx >= lenA)
	{
		return;
	}

	cout << "[ ";
	for (int i = leftIdx; i <= rightIdx; i++)
	{
		cout << A[i] << " ";
	}
	cout << "]" << endl;
}
void findSubarrays(int A[], int lenA)
{
	unordered_map<int, bool> elemVisited;
	int leftIdx = 0;
	int rightIdx = 0;

	while (rightIdx < lenA)
	{
		while (rightIdx < lenA && !elemVisited[A[rightIdx]])
		{
			elemVisited[A[rightIdx]] = true;
			rightIdx++;
		}
		printSubarray(A, lenA, leftIdx, rightIdx - 1);

		while (rightIdx < lenA && elemVisited[A[rightIdx]])
		{
			elemVisited[A[leftIdx]] = false;
			leftIdx++;
		}
	}
}
int main()
{
	int A[] = { 5, 2, 3, 5, 4, 3 };
	int lenA = sizeof(A) / sizeof(A[0]);

	cout << "The largest subarrays with all distinct elements are :\n";
	findSubarrays(A, lenA);
}
