// Trapping rain water problem

// Input: {7, 0, 4, 2, 5, 0, 6, 4, 0, 5}

// T W W W W W W W W W
// T W W W W W T W W W
// T W W W W W T W W W
// T W W W T W T W W T
// T W W W T W T T W T
// T W T W T W T T W T
// T W T W T W T T W T
// T W T T T W T T W T
// T W T T T W T T W T
// 
// 7 0 4 2 5 0 6 4 0 5

#include <stdio.h>
#include <limits.h>

int min(int x, int y)
{
	return x < y ? x : y;
}

int max(int x, int y)
{
	return x > y ? x : y;
}

int trappingRainWater(int heightsArr[], int lenHeightsArr)
{
	int sumWater = 0;
	int leftHeightArr[10 - 1];
	leftHeightArr[0] = INT_MIN;
	for (int i = 1; i < lenHeightsArr - 1; i++)
	{
		leftHeightArr[i] = max(leftHeightArr[i - 1], heightsArr[i - 1]);
	}

	int rightHeight = INT_MIN;
	for (int j = lenHeightsArr - 2; j >= 1; j--)
	{
		rightHeight = max(rightHeight, heightsArr[j + 1]);
		if (min(leftHeightArr[j], rightHeight) > heightsArr[j])
		{
			sumWater += min(leftHeightArr[j], rightHeight) - heightsArr[j];
		}
	}
	return sumWater;
}
int main()
{
	int heightsArr[] = { 7, 0, 4, 2, 5, 0, 6, 4, 0, 5 };
	int lenHeightsArr = sizeof(heightsArr) / sizeof(heightsArr[0]);

	printf("The maximum amount of water that can be trapped is %d",
		trappingRainWater(heightsArr, lenHeightsArr));
}

// Time complexity is O(n) and requires O(n) extra space