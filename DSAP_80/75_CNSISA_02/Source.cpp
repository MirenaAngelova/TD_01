// Time complexity is O(n)

#include <iostream>

using namespace std;

int getCount(int A[], int lenA)
{
	int count = 0;
	int len = 1;
	for (int i = 1; i < lenA; i++)
	{
		if (A[i - 1] < A[i])
		{
			count += len++;
		}
		else
		{
			len = 1;
		}
	}
	return count;
}
int main()
{
	int A[] = { 1, 2, 3, 4, 5 };
	int lenA = sizeof(A) / sizeof(A[0]);

	cout << "The total number of strictly increasing subarrays is "
		<< getCount(A, lenA) << endl;
}