// Maximum product subarray problem

// Input: { -6, 4, -5, 8, -10, 0, 8 }
// Output: The maximum product subarray is{ 4, -5, 8, -10 } having product 1600
// 
// Input : { 40, 0, -20, -10 }
// Output: The maximum product subarray is{ -20, -10 } having product 200

#include <stdio.h>

int max(int x, int y)
{
	return x > y ? x : y;
}

int min(int x, int y)
{
	return x < y ? x : y;
}

int findMaxSubarrayProduct(int A[], int lenArr)
{
	int maxCurrentProduct = 0;
	int minCurrentProduct = 0;
	int maxProduct = 0;
	for (int i = 0; i < lenArr; i++)
	{
		int temp = maxCurrentProduct;
		maxCurrentProduct = max(A[i], max(A[i] * maxCurrentProduct, A[i] * minCurrentProduct));
		minCurrentProduct = min(A[i], min(A[i] * temp, A[i] * minCurrentProduct));
		maxProduct = max(maxProduct, maxCurrentProduct);
	}
	return maxProduct;
}
int main()
{
	int A[] = { -6, 4, -5, 8, -10, 0, 8 };
	int lenArr = sizeof(A) / sizeof(A[0]);
	printf("The maximum product of a subarray is %d",
		 findMaxSubarrayProduct(A, lenArr) );
}

// Time complexity is O(n) and doesn't require any extra space