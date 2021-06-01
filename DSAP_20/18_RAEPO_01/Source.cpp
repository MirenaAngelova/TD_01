// Replace array elements with the product of others

// Input: { 1, 2, 3, 4, 5 }
// Output: { 120, 60, 40, 30, 24 }

// Input: { 5, 3, 4, 2, 6, 8 }
// Output: { 1152, 1920, 1440, 2880, 960, 720 }

// Time complexity is O(n)

#include <stdio.h>

void printArr(int A[], int lenArr)
{
	printf("Replaced array is: ");
	for (int i = 0; i < lenArr; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}
void replaceWithProduct(int A[], int lenArr)
{
	const int lenRight = 6;
	int rightElementsProduct[lenRight] = {1};
	for (int k = 0; k < lenRight; k++)
	{
		printf("rightElementsProduct[%d] is: %d", k, rightElementsProduct[k]);
		printf("\n");
	}

	for (int i = 1; i < lenRight; i++)
	{
		rightElementsProduct[i] = A[i - 1] * rightElementsProduct[i - 1];
	}

	for (int k = 0; k < lenRight; k++)
	{
		printf("rightElementsProduct[%d] is: %d", k, rightElementsProduct[k]);
		printf("\n");
	}

	const int lenLeft = 6;
	int leftElementsProduct[lenLeft];
	leftElementsProduct[lenLeft - 1] = { 1 };
	for (int l = 0; l < lenLeft; l++)
	{
		printf("leftElementsProduct[%d] is: %d", l, leftElementsProduct[l]);
		printf("\n");
	}

	for (int j = lenLeft - 2; j >= 0; j--)
	{
		leftElementsProduct[j] = A[j + 1] * leftElementsProduct[j + 1];
		printf("rightElementsProduct[%d] %d is: %d * %d", j, leftElementsProduct[j], A[j + 1], leftElementsProduct[j + 1]);
		printf("\n");
	}

	for (int l = 0; l < lenRight; l++)
	{
		printf("rightElementsProduct[%d] is: %d", l, leftElementsProduct[l]);
		printf("\n");
	}

	for (int m = 0; m < lenArr; m++)
	{
		A[m] = leftElementsProduct[m] * rightElementsProduct[m];
	}
}

int main()
{
	int A[] = { 5, 3, 4, 2, 6, 8 };
	int lenArr = sizeof(A) / sizeof(A[0]);
	
	replaceWithProduct(A, lenArr);
	printArr(A, lenArr);
}




