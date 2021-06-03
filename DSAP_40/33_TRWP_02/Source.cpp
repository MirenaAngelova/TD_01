// Time complexity is O(n) and 
// doesn't require any extra space

#include <stdio.h>

int max(int x, int y)
{
	return x > y ? x : y;
}

int maxTrappedWater(int heightsArr[], int lenHeightsArr)
{
	int sumWater = 0;
	int leftIdx = 0;
	int rightIdx = lenHeightsArr - 1;
	int maxLeftValue = heightsArr[leftIdx];
	int maxRightValue = heightsArr[rightIdx];

	while (leftIdx < rightIdx)
	{
		if (heightsArr[leftIdx] <= heightsArr[rightIdx])
		{
			leftIdx++;
			maxLeftValue = max(maxLeftValue, heightsArr[leftIdx]);
			sumWater += maxLeftValue - heightsArr[leftIdx];
		}
		else
		{
			rightIdx--;
			maxRightValue = max(maxRightValue, heightsArr[rightIdx]);
			sumWater += maxRightValue - heightsArr[rightIdx];
		}
	}
	return sumWater;
}
int main()
{
	int heightsArr[] = { 7, 0, 4, 2, 5, 0, 6, 4, 0, 5 };
	int lenHeightsArr = sizeof(heightsArr) / sizeof(heightsArr[0]);

	printf("The maximum amount of water that can be trapped is %d",
		maxTrappedWater(heightsArr, lenHeightsArr));
}