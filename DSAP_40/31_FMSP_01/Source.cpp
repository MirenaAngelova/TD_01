// Find maximum sum path involving elements
// of given arrays. We can switch between
// arrays only through it's common elements

// Input:
// 
// X = { 3, 6, 7, 8, 10, 12, 15, 18, 100 }
// Y = { 1, 2, 3, 5, 7, 9, 10, 11, 15, 16, 18, 25, 50 }
// 
// 
// The maximum sum path is :
// 
// 1 — > 2 — > 3 — > 6 — > 7 — > 9 — > 10 — > 12 — > 15 — > 16 — > 18 — > 100
// 
// The maximum sum is 199

#include <stdio.h>

int max(int x, int y)
{
	return x > y ? x : y;
}

int findMaxSum(int X[], int Y[], int lenX, int lenY)
{
	int sum = 0;
	int sumX = 0;
	int sumY = 0;
	int iX = 0;
	int iY = 0;

	while (iX < lenX && iY < lenY)
	{
		while (iX < lenX - 1 && X[iX] == X[iX + 1])
		{
			sumX += X[iX++];
		}

		while (iY < lenY - 1 && Y[iY] == Y[iY + 1])
		{
			sumY += Y[iY++];
		}

		if (X[iX] < Y[iY])
		{
			sumX += X[iX++];
		}
		else if (Y[iY] < X[iX])
		{
			sumY += Y[iY++];
		}
		else
		{
			sum += max(sumX, sumY) + X[iX];
			iX++;
			iY++;
			sumX = 0;
			sumY = 0;
		}
	}

	while (iX < lenX)
	{
		sumX += X[iX++];
	}

	while (iY < lenY)
	{
		sumY += Y[iY++];
	}

	sum += max(sumX, sumY);
	return sum;
}
int main()
{
	int X[] = { 3, 6, 7, 8, 10, 12, 15, 18, 100 };
	int Y[] = { 1, 2, 3, 5, 7, 9, 10, 11, 15, 16, 18, 25, 50 };
	int lenX = sizeof(X) / sizeof(X[0]);
	int lenY = sizeof(Y) / sizeof(Y[0]);

	printf("Maximum sum is %d", findMaxSum(X, Y, lenX, lenY));
}
// Time complexity is O(2*n) and runs in constant space