// Find a pair with a given sum in an array

// Input:
// arr = [8, 7, 2, 5, 3, 1]
// sum = 10
// Output:
// Pair found (8, 2)
// or
// Pair found (7, 3)

// Input:
// arr = [5, 2, 6, 8, 1, 9]
// sum = 12
// Output:
// Pair not found

// 01.Using Brute-Force — in C

#include <stdio.h>

void findPair(int arr[], int n, int sum)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i] + arr[j] == sum)
			{
				printf("Pair found (%d, %d)", arr[i], arr[j]);
				return;
			}
		}
	}

	printf("Pair not found");
}

int main(void)
{
	int arr[] = { 8, 7, 2, 5, 3, 1 };
	int sum = 10;

	int n = sizeof(arr) / sizeof(arr[0]);
	findPair(arr, n, sum);
}

//Time complexity — O(n**2), n — input size
