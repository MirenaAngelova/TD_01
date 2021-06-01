// Find all distinct combinations of a given length

// Input: {1, 2, 3}, k = 2
// Output : {1, 2}, { 1, 3 }, { 2, 3 }
// 
// Input: {1, 2, 1}, k = 2
// Output : {1, 1}, { 1, 2 }

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void findDistinctCombinations(int A[], string outMessage, int startIdx, int lenArr, int lenCombinations)
{
	if (lenCombinations > lenArr)
	{
		return;
	}

	if (lenCombinations == 0)
	{
		cout << outMessage << endl;
		return;
	}

	for (int i = startIdx; i < lenArr; i++)
	{
		// to handle duplicates
		while (i < lenArr - 1 && A[i] == A[i + 1])
		{
			i++;
		}

		findDistinctCombinations(A, outMessage + " " + to_string(A[i]), i + 1, lenArr, lenCombinations - 1);
	}
}
int main()
{
	int A[] = { 1, 2, 2, 3, 3 };
	int lenArr = sizeof(A) / sizeof(A[0]);
	int lenCombinations = 2;

	// to handle duplicates
	sort(A, A + lenArr);
	findDistinctCombinations(A, "", 0, lenArr, lenCombinations);
}

// Time complexity is exponential and 
// requires aditional space for recursion
