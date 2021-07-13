// 3-partition problem extending,
// printing all partitions

// S = { 7, 3, 2, 1, 5, 4, 8 }

// S1 = {7, 3}
// S2 = {5, 4, 1}
// S3 = {8, 2}
// We can partition S into 
// 3 non-overlapping partitions with sum 10

#include <iostream>
#include <numeric>

using namespace std;

bool isSubsetExists(int A[], int lastIdx, int s1, int s2, int s3, int indices[])
{
	if (s1 == 0 && s2 == 0 && s3 == 0)
	{
		return true;
	}

	if (lastIdx < 0)
	{
		return false;
	}

	bool isS1 = false;
	if (s1 - A[lastIdx] >= 0)
	{
		indices[lastIdx] = 1;
		isS1 = isSubsetExists(A, lastIdx - 1, s1 - A[lastIdx], s2, s3, indices);
	}

	bool isS2 = false;
	if (!isS1 && s2 - A[lastIdx] >= 0)
	{
		indices[lastIdx] = 2;
		isS2 = isSubsetExists(A, lastIdx - 1, s1, s2 - A[lastIdx], s3, indices);
	}

	bool isS3 = false;
	if (!isS1 && !isS2 && s3 - A[lastIdx] >= 0)
	{
		indices[lastIdx] = 3;
		isS3 = isSubsetExists(A, lastIdx - 1, s1, s2, s3 - A[lastIdx], indices);
	}
	return isS1 || isS2 || isS3;
}
void partition(int A[], int lenA)
{
	int sum = accumulate(A, A + lenA, 0);
	int* indices = new int[lenA];

	bool result = lenA >= 3 && !(sum % 3) &&
		isSubsetExists(
			A, 
			lenA - 1, 
			sum / 3, 
			sum / 3, 
			sum / 3, 
			indices
		);

	if (!result)
	{
		cout << "3-partitioon set is not posible.";
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		cout << "Partition " << i << " is ";
		for (int j = 0; j < lenA; j++)
		{
			if (indices[j] == i + 1) 
			{
				cout << A[j] << " ";
			}
		}
		cout << endl;
	}
}
int main()
{
	int A[] = { 7, 3, 2, 1, 5, 4, 8 };
	int lenA = sizeof(A) / sizeof(A[0]);

	partition(A, lenA);
}

// Time complexity is exponential
// and occupies space in the call stack