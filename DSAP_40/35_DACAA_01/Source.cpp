// Decode an array constructed from another array

// Input: { 3, 4, 5, 5, 6, 7 }
// Output: { 1, 2, 3, 4 }
// 
// Input: { 3, 4, 5, 6, 5, 6, 7, 7, 8, 9 }
// Output: { 1, 2, 3, 4, 5 }
// 
// Input: { 3 }
// Output: { 1, 2 } or { 2, 1 }
// 
// Input: { 3, 4, 5 }
// Output: { 1, 2, 3 }

// Size of input array is m
// Size of output array is n
// m = n*(n-1)/2 or n**2-n-2*m = 0
// n = (sqrt(8*m+1)+1)/2

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void decodeInputArr(int inputArr[], int lenInputArr)
{
	int lenOutputArr = (sqrt(8 * lenInputArr + 1) + 1) / 2;
	cout << "lenOutputArr is " << lenOutputArr
		<< endl;

	int outputArr[5];
	if (lenOutputArr == 1)
	{
		outputArr[0] = inputArr[0];
	}
	else if (lenOutputArr == 2)
	{
		outputArr[0] = inputArr[0] - inputArr[1];
	}
	else
	{
		outputArr[0] = (inputArr[0] + inputArr[1] - inputArr[lenOutputArr - 1]) / 2;
	}

	for (int i = 1; i < lenOutputArr; i++)
	{
		outputArr[i] = inputArr[i - 1] - outputArr[0];
	}

	for (int j = 0; j < lenOutputArr; j++)
	{
		cout << outputArr[j] << " ";
	}
	cout << "\n";
}
int main()
{
	int inputArr[] = { 3, 4, 5, 6, 5, 6, 7, 7, 8, 9 };
	int lenInputArr = sizeof(inputArr) / sizeof(inputArr[0]);

	decodeInputArr(inputArr, lenInputArr);
}

// Time complexity is O(n) and
// requires O(n) extra space