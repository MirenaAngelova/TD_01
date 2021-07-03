// Two Pointer Approach

#include <stdio.h>
#include <stdlib.h>

void findClosestPair(int first[], int second[], int lenFirst, int lenSecond, int sum)
{
	int k = 0;
	int l = lenSecond - 1;

	for (int i = 0, j = lenSecond - 1; i < lenFirst && j >= 0;)
	{
		if (abs(first[i] + second[j] - sum) < abs(first[k] + second[l] - sum))
		{
			k = i;
			l = j;
		}

		if (first[i] + second[j] < sum)
		{
			i++;
		}
		else if (first[i] + second[j] > sum)
		{
			j--;
		}
		else
		{
			i++;
			j--;
		}
	}

	printf("The closest pair is [%d, %d]", first[k], second[l]);
}
int main()
{
	int first[] = { 1, 8, 10, 12 };
	int second[] = { 2, 4, 9, 15 };
	int sum = 11;

	int lenFirst = sizeof(first) / sizeof(first[0]);
	int lenSecond = sizeof(second) / sizeof(second[0]);

	findClosestPair(first, second, lenFirst, lenSecond, sum);
}