// Quicksort using Dutch national fleg algorithm

// We have three colors in specific order and balls
// that must be arranged by color in that specific order

#include <iostream>

using namespace std;

pair<int, int> partition(int A[], int p, int r)
{
	int q = p;
	int pivot = A[r];
	while (q <= r)
	{
		if (A[q] < pivot)
		{
			swap(A[p], A[q]);
			++p;
			++q;
		}
		else if (A[q] > pivot)
		{
			swap(A[q], A[r]);
			--r;
		}
		else
		{
			++q;
		}
	}
	return make_pair(p - 1, q);
}
void quicksort(int A[], int p, int r)
{
	if (p >= r)
	{
		return;
	}

	if (p - r == 1)
	{
		if (A[p] < A[r])
		{
			swap(A[p], A[r]);
			return;
		}
	}

	pair<int, int> pQ= partition(A, p, r);
	quicksort(A, p, pQ.first);
	quicksort(A, pQ.second, r);
}
int main()
{
	int A[] = { 2, 6, 5, 2, 6, 8, 6, 1, 2, 6 };
	int N = sizeof(A) / sizeof(A[0]);

	quicksort(A, 0, N - 1);

	for (int i = 0; i < N; i++)
	{
		cout << A[i] << " ";
	}
}