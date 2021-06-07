// Print all quadruplets with given sum

// Input:
// 
// A[] = [2, 7, 4, 0, 9, 5, 1, 3]
// sum = 20
// 
// Output : Below are the quadruplets with sum 20
// 
// (0, 4, 7, 9)
// (1, 3, 7, 9)
// (2, 4, 5, 9)

#include <iostream>
#include <algorithm>

using namespace std;

void printQuadruplets(int A[], int lenA, int sum)
{
	sort(A, A + lenA);
	for (int i = 0; i < lenA - 3; i++)
	{
		for (int j = i + 1; j < lenA - 2; j++)
		{
			int diff = sum - A[i] - A[j];
			int lowIdx = j + 1;
			int highIdx = lenA - 1;
			while (lowIdx < highIdx)
			{
				if (A[lowIdx] + A[highIdx] < diff)
				{
					lowIdx++;
				}
				else if (A[lowIdx] + A[highIdx] > diff)
				{
					highIdx--;
				}
				else
				{
					cout << "(" << A[i]
						<< ", " << A[j]
						<< ", " << A[lowIdx]
						<< ", " << A[highIdx]
						<< ")" << endl;
					lowIdx++;
					highIdx--;
				}
			}
		}
	}
}
int main()
{
	int A[] = { 2, 7, 4, 0, 9, 5, 1, 3 };
	int lenA = sizeof(A) / sizeof(A[0]);
	int sum = 20;

	printQuadruplets(A, lenA, sum);
}