// Quicksort algorithm using Hoare's
// partitioning scheme

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define N 15

int partitionHoares(int A[], int p, int r)
{
	int x = A[p];
	int i = p - 1;
	int j = r + 1;
	while (true)
	{
		do
		{
			i++;
		} while (A[i] < x);

		do
		{
			j--;
		} while (A[j] > x);

		if (i < j)
		{
			swap(A[i], A[j]);
		}
		else
		{
			return j;
		}
	}
}
void quicksort(int A[], int p, int r)
{
	if (p >= r)
	{
		return;
	}
	int q = partitionHoares(A, p, r);
	quicksort(A, p, q);
	quicksort(A, q + 1, r);
}
int main()
{
	int A[N];
	srand(time(NULL));
	for (int i = 0; i < N; i++)
	{
		A[i] = rand() % 100 - 50;
	}
	quicksort(A, 0, N - 1);

	for (int i = 0; i < N; i++)
	{
		cout << A[i] << " ";
	}
}