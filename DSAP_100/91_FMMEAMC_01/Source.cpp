// Find the minimum and maximum element
// in an array using minimum comparisons

// Input:  A[] = [5, 7, 2, 4, 9, 6]
// 
// Output :
// 
// The minimum array element is 2
// The maximum array element is 9

#include <iostream>

using namespace std;

void findMinMax(int A[], int lenA, int& min, int& max)
{
	min = A[0];
	max = A[0];
	for (int i = 1; i < lenA; i++)
	{
		if (A[i] < min)
		{
			min = A[i];
		}

		if (A[i] > max)
		{
			max = A[i];
		}
	}
}
int main()
{
	int A[] = { 5, 7, 2, 4, 9, 6 };
	int lenA = sizeof(A) / sizeof(A[0]);

	int min;
	int max;
	findMinMax(A, lenA, min, max);
	cout << "The minimum array element is "
		<< min << endl;
	cout << "The maximum array element is "
		<< max << endl;
}