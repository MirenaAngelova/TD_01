// Printing Distinct Triplets

// Time complexity is O(n**2) and
// doesn't require any extra space

#include <iostream>
#include <algorithm>

using namespace std;

void printTriplets(int A[], int lenArr, int sum)
{
	sort(A, A + lenArr);
	for (int i = 0; i < lenArr - 2; i++)
	{
		int tempSum = sum - A[i];
		int firstIdx = i + 1;
		int lastIdx = lenArr - 1;
		while (firstIdx < lastIdx)
		{
			if (A[firstIdx] + A[lastIdx] < tempSum)
			{
				firstIdx++;
			}
			else if (A[firstIdx] + A[lastIdx] > tempSum)
			{
				lastIdx--;
			}
			else
			{
				cout << "Triplet: { " 
					<< A[i] << " "
					<< A[firstIdx] << " "
					<< A[lastIdx]
					<< " }\n";
				firstIdx++;
				lastIdx--;
			}
		}
	}
}
int main()
{
	int A[] = { 2, 7, 4, 0, 9, 5, 1, 3 };
	int lenArr = sizeof(A) / sizeof(A[0]);
	int sum = 6;
	printTriplets(A, lenArr, sum);
}