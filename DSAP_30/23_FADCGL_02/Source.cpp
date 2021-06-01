// Time complexity is exponential and 
// requires aditional space for recursion

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void findCombinations(int A[], string out, int lenArr, int lenCombinations)
{
	if (lenCombinations > lenArr)
	{
		return;
	}

	if (lenCombinations == 0)
	{
		cout << out << endl;
		return;
	}

	for (int i = lenArr - 1; i >= 0; i--)
	{
		while ( i > 0 && A[i] == A[i - 1])
		{
			i--;
		}

		findCombinations(A, to_string(A[i]) + " " + out, i, lenCombinations - 1);
	}
}
int main()
{
	int A[] = { 1, 1, 2, 2, 2, 3, 3, 3 };
	int lenArr = sizeof(A) / sizeof(A[0]);
	int lenCombinations = 2;

	sort(A, A + lenArr);
	findCombinations(A, "", lenArr, lenCombinations);
}