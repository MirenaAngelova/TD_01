// Quicksort algorithm - O(n**2)

#include <iostream>
#include <algorithm>

using namespace std;

int partition(int A[], int p, int r)
{
	int pivot = A[r];
	int i = p;

	for (int j = p; j < r; j++)
	{
		if (A[j] <= pivot)
		{
			swap(A[i], A[j]);
			i++;
		}
	}
	swap (A[i], A[r]);
	return i;
}
void quicksort(int A[], int p, int r)
{
	if (p >= r)
	{
		return;
	}

	int q = partition(A, p, r);
	quicksort(A, p, q - 1);
	quicksort(A, q + 1, r);
}
int main()
{
	int A[] = { 2, 5, 6, 4, 1, 3, 0 };
	int N = sizeof(A) / sizeof(A[0]);

	quicksort(A, 0, N - 1);

	for (int i = 0; i < N; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
}