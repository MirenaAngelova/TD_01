// Find the largest subarray formed by consecutive unordered distinct integers

// Input: { 2, 0, 2, 1, 4, 3, 1, 0 }
// Output: { 0, 2, 1, 4, 3 }

#include <iostream>
#include <vector>

using namespace std;

void printSubarray(int A[], int firstIdx, int lastIdx)
{
	cout << "The largest subarray is: { ";
	for (int i = firstIdx; i < lastIdx + 1; i++)
	{
		cout << A[i] << " ";
	}
	cout << "}, started from " << firstIdx
		<< " position and ended at " << lastIdx
		<< " position.\n";
}

bool isConsecutive(int A[], int i, int j, int minValue, int maxValue)
{
	if (maxValue - minValue != j - i)
	{
		return false;
	}

	int lenVector = j - i + 1;
	vector<bool> visitedVector(lenVector);

	for (int k = i; k < j + 1; k++)
	{
		if (visitedVector[A[k] - minValue])
		{


			return false;
		}

		visitedVector[A[k] - minValue] = true;
	}

	return true;
}



void findLargestSubarray(int A[], int lenArr)
{
	int lenSubarray = 0;
	int firstIdx = 0;
	int lastIdx = 0;

	for (int i = 0; i < lenArr - 1; i++)
	{
		int minValue = A[i];
		int maxValue = A[i];
		for (int j = i + 1; j < lenArr; j++)
		{
			minValue = min(minValue, A[j]);
			maxValue = max(maxValue, A[j]);

			cout << "\nmaxValue - minValue != j - i: "
				<< maxValue << " - "
				<< minValue << " != "
				<< j << " - "
				<< i;
			if (isConsecutive(A, i, j, minValue, maxValue))
			{
				cout << "\nisConsecutive - i, j, minValue, maxValue: "
					<< i << " "
					<< j << " "
					<< minValue << " "
					<< maxValue;

				if (lenSubarray < maxValue - minValue + 1)
				{
					lenSubarray = maxValue - minValue + 1;
					firstIdx = i;
					lastIdx = j;
					cout << "\nlenSubarray, firstIdx, lastIdx: "
						<< lenSubarray << " "
						<< firstIdx << " "
						<< lastIdx;
				}
			}
		}
	}

	printSubarray(A, firstIdx, lastIdx);
}

int main()
{
	int A[] = { 2, 0, 2, 1, 4, 3, 1, 0 };
	int lenArr = sizeof(A) / sizeof(A[0]);

	findLargestSubarray(A, lenArr);
}

// Complexity time is O(n**3) and requires O(n) extra space