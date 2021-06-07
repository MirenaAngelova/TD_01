// Group elements of an array based
// on their first occurrence

// Input: { 1, 2, 3, 1, 2, 1 }
// 
// Output: { 1, 1, 1, 2, 2, 3 }
// 
// 
// Input: { 5, 4, 5, 5, 3, 1, 2, 2, 4 }
// 
// Output: { 5, 5, 5, 4, 4, 3, 1, 2, 2 }

#include <iostream>
#include <unordered_map>

using namespace std;

void groupElems(int A[], int lenA)
{
	unordered_map<int, int> elemFreq;
	for (int i = 0; i < lenA; i++)
	{
		elemFreq[A[i]]++;
	}

	for (int i = 0; i < lenA; i++)
	{
		if (elemFreq.find(A[i]) != elemFreq.end())
		{
			int freq = elemFreq[A[i]];
			while (freq--)
			{
				cout << A[i] << " ";
			}
			elemFreq.erase(A[i]);
		}
	}
}

int main()
{
	int A[] = { 5, 4, 5, 5, 3, 1, 2, 2, 4 };
	size_t lenA = sizeof(A) / sizeof(*A);
	groupElems(A, lenA);
}

// Time complexity is O(n)
// and requires O(n) extra space