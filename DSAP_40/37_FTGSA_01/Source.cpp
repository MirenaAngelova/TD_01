// Find a triplet with a given sum in an array,
// using naive recursive aproach

// Input:
// arr = [2, 7, 4, 0, 9, 5, 1, 3]
// sum = 6
// 
// Output : Triplet exists.
// 
// The triplets with the given sum 6 are{ 0, 1, 5 }, { 0, 2, 4 }, { 1, 2, 3 }

#include <iostream>

using namespace std;

bool isTripletExists(int A[], int lenArr, int sum, int lenTriplet)
{
	if (lenTriplet == 3 && sum == 0)
	{
		return true;
	}

	if (lenTriplet == 3 || lenArr == 0 || sum < 0)
	{
		return false;
	}

	return isTripletExists(A, lenArr - 1, sum - A[lenArr - 1], lenTriplet + 1) ||
		isTripletExists(A, lenArr - 1, sum, lenTriplet);
}
int main()
{
	int A[] = { 2, 7, 4, 0, 9, 5, 1 };
	int lenArr = sizeof(A) / sizeof(A[0]);
	int sum = 6;
	isTripletExists(A, lenArr, sum, 0) ?
		cout << "Triplet exists" :
		cout << "Triplet doesn't exists";
}