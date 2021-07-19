// Time complexity is O(n)

#include <iostream>
#include <climits>

using namespace std;

void findMinMax(int A[], int lenA, int& min, int& max)
{
	min = INT_MAX;
	max = INT_MIN;
	bool odd = lenA & 1;
	if (odd)
	{
		lenA--;
	}

	for (int i = 0; i < lenA; i += 2)
	{
		int minCurrent;
		int maxCurrent;
		if (A[i] > A[i+1]) 
		{
			minCurrent = A[i + 1];
			maxCurrent = A[i];
		}
		else
		{
			minCurrent = A[i];
			maxCurrent = A[i + 1];
		}

		if (min > minCurrent)
		{
			min = minCurrent;
		}
		if (max < maxCurrent)
		{
			max = maxCurrent;
		}
	}

	if (odd)
	{
		if (A[lenA] < min)
		{
			min = A[lenA];
		}

		if (A[lenA] > max)
		{
			max = A[lenA];
		}
	}
}
int main()
{
	int A[] = { 4, 7, 5, 1, 3 };
	int lenA = sizeof(A) / sizeof(A[0]);

	int min;
	int max;

	findMinMax(A, lenA, min, max);
	cout << "The minimum array element is " 
		<< min << endl;
	cout << " The maximum array element is " 
		<< max << endl;
}