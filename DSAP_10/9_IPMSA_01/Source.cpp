// In-place merge two sorted arrays

// Input: { 1, 4, 7, 8, 10 } and { 2, 3, 9 }
// Output: { 1, 2, 3, 4, 7 } and { 8, 9, 10 }

#include <iostream>
#include <algorithm>

using namespace std;

void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void mergeArrays(int X[], int Y[], int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		if (X[i] > Y[0])
		{
			swap(X[i], Y[0]);
			int temp = Y[0];

			int j;
			for (j = 1; j < n && Y[j] < temp; j++)
			{
				Y[j - 1] = Y[j];
			}
			Y[j - 1] = temp;
		}
	}
}

int main()
{
	int X[] = { 1, 4, 7, 8, 10 };
	int Y[] = { 2, 3, 9 };

	int m = sizeof(X) / sizeof(X[0]);
	int n = sizeof(Y) / sizeof(Y[0]);

	mergeArrays(X, Y, m, n);
	cout << "X: ";
	printArray(X, m);
	cout << "Y: ";
	printArray(Y, n);
}