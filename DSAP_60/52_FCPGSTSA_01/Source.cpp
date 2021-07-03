// Find the closest pair to
// a given sum in two sorted arrays

// Input:
// 
// first[] = { 1, 8, 10, 12 }
// second[] = { 2, 4, 9, 15 }
// sum = 11
// 
// Output : The closest pair is[1, 9]
// 
// 
// Input :
// 
// first = { 10, 12, 15, 18, 20 }
// second = { 1, 4, 6, 8 }
// sum = 22
// 
// Output : The closest pair is[18, 4]

// Brute Force Approach
// Time complexity is O(n**2) and
// doesn't require any extra space

#include <stdio.h>
#include <stdlib.h>

void findClosestPair(int first[], int second[], int lenFirst, int lenSecond, int sum)
{
	int k = 0;
	int l = 0;
	for (int i = 0; i < lenFirst; i++)
	{
		
		for (int j = 0; j < lenSecond; j++)
		{
			if (abs(first[i] + second[j] - sum) < abs(first[k] + second[l] - sum))
			{
				k = i;
				l = j;
			}
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