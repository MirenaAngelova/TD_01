// Determine whether an array 
// can be divided into pairs 
// with a sum divisible by k

// Input:
// arr[] = { 3, 1, 2, 6, 9, 4 }
// k = 5
// 
// Output : Pairs can be formed
// 
// Explanation : Array can be divided into pairs{ (3, 2), (1, 9), (4, 6) } where the sum of elements in each pair is divisible by 5.
// 
// 
// Input :
// arr[] = { 2, 9, 4, 1, 3, 5 }
// k = 6
// 
// Output : Pairs can be formed
// 
// Explanation : Array can be divided into pairs{ (2, 4), (9, 3), (1, 5) } where the sum of elements in each pair is divisible by 5.
// 
// 
// Input :
// arr[] = { 3, 1, 2, 6, 9, 4 }
// k = 6
// 
// Output : Pairs cannot be formed
// 
// Explanation : Array cannot be divided into pairs where the sum of elements in each pair is divisible by 6.

// Time complexity is O(n**2)
// and requires O(n) extra space

#include <stdio.h>

int findPairs(int A[], int lenA, int k)
{
	if (lenA & 1)
	{
		return 0;
	}

	int* visited = new int[lenA];
	for (int i = 0; i < lenA; i++)
	{
		visited[i] = 0;
		//printf("visited[%d] is %d\n", i, visited[i]);
	}
	
	for (int i = 0; i < lenA -1; i++)
	{
		if (visited[i])
		{
			continue;
		}
		int j = i + 1;
		while (j < lenA)
		{
			if (!visited[j] && (A[i] + A[j]) % k == 0)
			{
				visited[j] = 1;
				break;
			}
			j++;
		}
		if (j == lenA)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	int A[] = { 3, 1, 2, 6, 9, 4 };
	int lenA = sizeof(A) / sizeof(A[0]);

	int k = 6;
	if (findPairs(A, lenA, k))
	{
		printf("Pairs can be formed.\n");
	}
	else
	{
		printf("Pairs can't be formed.\n");
	}
}