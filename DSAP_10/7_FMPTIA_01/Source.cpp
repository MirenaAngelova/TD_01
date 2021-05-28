// Find max product of two integers in array

// Input: { -10, -3, 5, 6, -2 } Output: (-10, -3), (5, 6)

#include <stdio.h>
#include <limits.h>

void findMaxProduct(int arr[], int n)
{
	int maxProduct = INT_MIN;
	int maxi;
	int maxj;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int product = arr[i] * arr[j];
			if (maxProduct < product)
			{
				maxProduct = product;
				maxi = i;
				maxj = j;
			}
		}
	}

	printf("The max product is: %d \* %d \= %d", arr[maxi], arr[maxj], maxProduct);
}

int main()
{
	int arr[] = { -10, -3, 5, 6, -2 };
	int n = sizeof(arr) / sizeof(arr[0]);

	findMaxProduct(arr, n);
}

// Time complexity - O(n*2)