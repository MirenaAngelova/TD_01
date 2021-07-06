// Time complexity is O(n*log(n))
// and requires O(n) extra space

#include <iostream>
#include <set>

using namespace std;

bool isConsecutive(int A[], int lenA)
{
	set<int> set;
	int prevElem;
	for (int currentElem : set)
	{	
		if (currentElem != *set.begin() && currentElem != prevElem + 1)
		{
			
			return false;
		}
		prevElem = currentElem;
	}
	return true;
}
int main()
{
	int A[] = { -1, 5, 4, 2, 0, 3, 1 };
	int lenA = sizeof(A) / sizeof(A[0]);
	
	isConsecutive(A, lenA) ?
		cout << "The array contains consecutive integers" :
		cout << "The array doesn't contain consecutive integers";
}