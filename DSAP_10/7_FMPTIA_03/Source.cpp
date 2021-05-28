// Time complexity - O(n)

#include <stdio.h>
#include <limits.h>

void findMaxProduct(int arr[], int n)
{
	int maxMax = arr[0];
	int maxMin = INT_MIN;
	int minMin = arr[0];
	int minMax = INT_MAX;

	for (int i = 1; i < n; i++)
	{
		if (arr[i] > maxMax)
		{
			maxMin = maxMax;
			maxMax = arr[i];
		}
		else if (arr[i] > maxMin)
		{
			maxMin = arr[i];
		}

		if (arr[i] < minMin)
		{
			minMax = minMin;
			minMin = arr[i];
		}
		else if (arr[i] < minMax)
		{
			minMax = arr[i];
		}
	}

	if (minMin * minMax >= maxMin * maxMax)
	{
		printf("The product is: %d \* %d \= %d", minMin, minMax, minMin * minMax);
	}
	else
	{
		printf("The product is: %d \* %d \= %d", maxMin, maxMax, maxMin * maxMax);
	}
}

int main()
{
	int arr[] = { -3, -10, 2, 3, 1, 5, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);

	findMaxProduct(arr, n);
}