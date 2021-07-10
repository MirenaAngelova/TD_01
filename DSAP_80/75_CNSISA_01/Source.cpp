// Find the number of strictly increasing subarrays in an array

// Input:  A[] = { 1, 2, 4, 4, 5 }
// 
// Output: The total number of strictly increasing subarrays is 4
// 
// { 1, 2 }, { 1, 2, 4 }, { 2, 4 }, { 4, 5 }
// 
// 
// Input:  A[] = { 1, 3, 2 }
// 
// Output: The total number of strictly increasing subarrays is 1
// 
// {1, 3}
// 
// 
// Input:  A[] = { 5, 4, 3, 2, 1 }
// 
// Output: The total number of strictly increasing subarrays is 0

// Time complexity is O(n**2)

#include <iostream>

using namespace std;

int getCount(int A[], int lenA)
{
	int count = 0;
	for (int i = 0; i < lenA; i++)
	{
		for (int j = i + 1; j < lenA; j++)
		{
			if (A[j - 1] >= A[j])
			{
				break;
			}
			++count;
		}
	}
	return count;
}
int main()
{
	int A[] = { 1, 2, 4, 5, 6 };
	int lenA = sizeof(A) / sizeof(A[0]);

	cout << "The total number of strictly increasing subarrays is "
		<< getCount(A, lenA) << endl;
}