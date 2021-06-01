// Find all distinct combinations of a given length

// Input: {1, 2, 3}, k = 2
// Output : {1, 2}, { 1, 3 }, { 2, 3 }
// 
// Input: {1, 2, 1}, k = 2
// Output : {1, 1}, { 1, 2 }

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printOutputCombVec(vector<int> const &outputCombVec)
{
	for (int i : outputCombVec)
	{
		cout << i << " ";
	}
	cout << endl;
}
void findCombinations(int A[], vector<int> &outputCombVec, int currentIdx, int lenArr, int lenCombinations)
{
	if (lenCombinations == 0)
	{
		printOutputCombVec(outputCombVec);
		return;
	}

	if (currentIdx == lenArr)
	{
		return;
	}

	while (currentIdx < lenArr - 1 && A[currentIdx] == A[currentIdx + 1])
	{
		currentIdx++;
	}
	outputCombVec.push_back(A[currentIdx]);
	findCombinations(A, outputCombVec, currentIdx + 1, lenArr, lenCombinations - 1);

	outputCombVec.pop_back();
	findCombinations(A, outputCombVec, currentIdx + 1, lenArr, lenCombinations);
}
int main()
{
	int A[] = { 1, 1, 2, 2, 2, 3, 3 };
	int lenArr = sizeof(A) / sizeof(A[0]);
	int lenCombinations = 2;
	vector<int> outputCombVec;

	sort(A, A + lenArr);
	findCombinations(A, outputCombVec, 0, lenArr, lenCombinations);
}

// Time complexity is exponential and 
// requires aditional space for recursion