// Hybrid quicksort algorithm

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define N 100000
#define NUM 10

void insertionSort(int dup[], int p, int r)
{
    for (int j = p + 1; j <= r; j++)
    {
        int key = dup[j];
        int i = j - 1;

        while (i >= p && dup[i] > key)
        {
            dup[i + 1] = dup[i];
            i--;
        }
        dup[i + 1] = key;
    }
}

int partition(int Adup[], int p, int r)
{
	int pivot = Adup[r];
	int i = p;

	for (int j = p; j < r; j++)
	{
		if (Adup[j] <= pivot)
		{
			swap(Adup[i], Adup[j]);
			i++;
		}
	}
	swap(Adup[i], Adup[r]);
	return i;
}

void optimizedQuicksort(int dup[], int p, int r)
{
	while (p < r)
	{
		if (r - p < NUM)
		{
			insertionSort(dup, p, r);
			break;
		}
		else
		{
			int q = partition(dup, p, r);
			if (q - p < r - q)
			{
				optimizedQuicksort(dup, p, q - 1);
				p = q + 1;
			}
			else
			{
				optimizedQuicksort(dup, q + 1, r);
				r = q - 1;
			}
		}
	}
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
	int A[N];
	int dup[N];

	srand(time(NULL));

	clock_t begin;
	clock_t end;

	double t1 = 0.0;
	double t2 = 0.0;

	for (int i = 0; i < NUM; i++)
	{
		for (int j = 0; j < N; j++)
		{
			A[j] = dup[j] = rand() % N;
		}

		begin = clock();
		quicksort(A, 0, N - 1);
		end = clock();

		t1 += (double)(end - begin) / CLOCKS_PER_SEC;

		begin = clock();
		optimizedQuicksort(dup, 0, N - 1);
		end = clock();

		t2 += (double)(end - begin) / CLOCKS_PER_SEC;
	}

	cout << "The average time taken by non-optimized Quicksort is: " << t1 / NUM << endl;
	cout << "The average time taken by optimized Quicksort is: " << t2 / NUM << endl;

	/*for (int i = 0; i < NUM * NUM; i += NUM)
	{
		cout << "Non-optimized A[i] is " << A[i] << endl;
		cout << "Optimized dup[i] is " << dup[i] << endl;
	}*/
}





