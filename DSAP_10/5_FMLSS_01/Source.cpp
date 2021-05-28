// Find maximum length subarray having a given sum

// A[] = {5, 6, -5, 5, 3, 5, 3, -2, 0}
// sum = 8
// The longest subarray with sum 8 is:
// {-5, 5, 3, 5} having length 4

// Naive solution, complexity time is O(n**2) for constant time, otherwise O(n**3)

#include <stdio.h>

void findMaxSubarray(int arr[], int n, int S)
{
	int maxLen = 0;
	int lastIndex = 0;
	for (int i = 0; i < n; i++)
	{
		int sum = 0;
		for (int j = i; j < n; j++)
		{
			
			sum += arr[j];
			if (sum == S)
			{
				if (maxLen < j - i + 1)
				{
					maxLen = j - i + 1;
					lastIndex = j;
				}
			}
		}
	}
	printf("Max length: %d\n", maxLen);
	printf("Last index: %d\n", lastIndex);

	int startIndex = lastIndex - maxLen + 1;
	printf("The longest subarray [%d...%d] with sum %d is:",startIndex, lastIndex, S);
	printf("{ ");

	int len = lastIndex + 1;
	for (int i = startIndex; i < len ; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("}\n\n");
}

int main()
{
	int arr[] = { 5, 6, -5, 5, 3, 5, 3, -2, 0 };
	int S = 8;
	int n = sizeof(arr) / sizeof(arr[0]);
	findMaxSubarray(arr, n, S);
}