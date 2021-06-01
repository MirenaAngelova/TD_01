// Using recursion to solve problem in linear time and constant space

#include <stdio.h>

void printArray(int A[], int lenArr)
{
	printf("Replaced with product array is: ");
	for (int i = 0; i < lenArr; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
}

int replaceWithProduct(int A[], int lenArr, int leftElementsProduct, int currentIndex)
{
	if (currentIndex == lenArr)
	{
		return 1;
	}

	
	int currentElement = A[currentIndex];
	int rightElementsProduct = replaceWithProduct(A, lenArr, A[currentIndex] * leftElementsProduct, currentIndex + 1);
	A[currentIndex] = leftElementsProduct * rightElementsProduct;

	return rightElementsProduct * currentElement;
}

int main()
{
	int A[] = { 5, 3, 4, 2, 6, 8 };
	int lenArr = sizeof(A) / sizeof(A[0]);

	replaceWithProduct(A, lenArr, 1, 0);
	printArray(A, lenArr);
}

// Time complexity is O(n) with O(n) implicit space for the call stack