// Find minimum platforms needed to
// avoid delay in train arrival,
// using merging of two sorted arrays

// Trains arrival = { 2.00, 2.10, 3.00, 3.20, 3.50, 5.00 }
// Trains departure = { 2.30, 3.40, 3.20, 4.30, 4.00, 5.20 }
// 
// The minimum platforms needed is 2
// 
// The train arrived at 2.00 on platform 1
// The train arrived at 2.10 on platform 2
// The train departed at 2.30 from platform 1
// The train arrived at 3.00 on platform 1
// The train departed at 3.20 from platform 1
// The train arrived at 3.20 on platform 1
// The train departed at 3.40 from platform 2
// The train arrived at 3.50 on platform 2
// The train departed at 4.00 from platform 2
// The train departed at 4.30 from platform 1
// The train arrived at 5.00 on platform 1
// The train departed at 5.20 from platform 1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<double> Trains;

int findMinPlatforms(Trains arrivalVec, Trains departureVec)
{
	sort(arrivalVec.begin(), arrivalVec.end());
	sort(departureVec.begin(), departureVec.end());

	int countTrains = 0;
	int minPlatformsNeeded = 0;
	int idxArrival = 0;
	int idxDeparture = 0;

	while (idxArrival < arrivalVec.size())
	{
		if (arrivalVec[idxArrival] < departureVec[idxDeparture])
		{
			minPlatformsNeeded = max(minPlatformsNeeded, ++countTrains);
			idxArrival++;
		}
		else
		{
			countTrains--;
			idxDeparture++;
		}
	}
	return minPlatformsNeeded;
}

int main()
{
	Trains arrivalVec = { 2.00, 2.10, 3.00, 3.20, 3.50, 5.00 };
	Trains departureVec = { 2.30, 3.40, 3.20, 4.30, 4.00, 5.20 };

	cout << "The minimum platforms needed is "
		<< findMinPlatforms(arrivalVec, departureVec);
}

// Time complexity is O(n*log(n)) and
// doesn't require any extra space