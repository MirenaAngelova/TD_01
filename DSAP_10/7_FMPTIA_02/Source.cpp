// Time complexity O(n*log(n))

#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
	return *(int*)a - *(int*)b;
}

void findMaxProduct(int arr[], int n)
{
	qsort(arr, n, sizeof(int), compare);

	if (arr[0] * arr[1] < arr[n - 1] * arr[n - 2])
	{
		printf("The max product is: %d \* %d \= %d", arr[n - 1], arr[n - 2], arr[n - 1] * arr[n - 2]);
	}
	else
	{
		printf("The max product is: %d \* %d \= %d", arr[0], arr[1], arr[0] * arr[1]);
	}
}

int main()
{
	int arr[] = { -3, -10, 2, 5, 3, 5, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);

	findMaxProduct(arr, n);
}