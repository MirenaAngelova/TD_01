// Merging two arays satisfied some constrains

// Input: { 0, 2, 0, 3, 0, 5, 6, 0, 0 } and { 1, 8, 9, 10, 15 }
// Output: { 1, 2, 3, 5, 6, 8, 9, 10, 15 }

#include <stdio.h>

void mergeSortedXY(int X[], int Y[], int lastIdxX, int lastIdxY)
{
	int lastIdxMergedX = lastIdxX + lastIdxY + 1;
	while (lastIdxX >= 0 && lastIdxY >= 0)
	{
		if (X[lastIdxX] > Y[lastIdxY])
		{
			X[lastIdxMergedX--] = X[lastIdxX--];
		}
		else
		{
			X[lastIdxMergedX--] = Y[lastIdxY--];
		}
	}

	while (lastIdxY >= 0)
	{
		X[lastIdxMergedX--] = Y[lastIdxY--];
	}

	for (int i = 0; i < lastIdxY; i++)
	{
		Y[i] = 0;
	}
}

void rearangeZeros(int X[], int Y[], int lenX, int lenY)
{
	int idxRearangedX = 0;
	for (int i = 0; i < lenX; i++)
	{
		if (X[i] != 0)
		{
			X[idxRearangedX++] = X[i];
		}
	}

	int lastIdxRearangedX = idxRearangedX - 1;
	int lastIdxY = lenY - 1;

	printf("RearangedZeros X is: ");
	for (int k = 0; k < idxRearangedX; k++)
	{
		printf("%d ", X[k]);
	}
	printf("\n");

	mergeSortedXY(X, Y, lastIdxRearangedX, lastIdxY);
}

int main()
{
	int X[] = { 0, 2, 0, 3, 0, 5, 6, 0, 0 };
	int Y[] = { 1, 8, 9, 10, 15 };
	int lenX = sizeof(X) / sizeof(X[0]);
	int lenY = sizeof(Y) / sizeof(Y[0]);

	

	rearangeZeros(X, Y, lenX, lenY);

	printf("\nMerging X array is: ");
	for (int i = 0; i < lenX; i++)
	{
		printf("%d ", X[i]);
	}
	printf("\n");
}

// Time complexity is O(2*n)
