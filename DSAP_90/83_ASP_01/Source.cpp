// Activity selection problem

// Input: Following set of activities
// 
// (1, 4), (3, 5), (0, 6), (5, 7), 
// (3, 8), (5, 9), (6, 10), (8, 11),
// (8, 12), (2, 13), (12, 14)
// 
// Output :
// 
// 	(1, 4), (5, 7), (8, 11), (12, 14)

// Time complexity O(n*log(n))
// and requires O(1) auxilary space

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

struct Interval
{
	int start;
	int end;
};

bool compareInterval(Interval i1, Interval i2)
{
	return i1.end < i2.end;
}

void selectActivity(vector<Interval> activities)
{
	int i = 0;
	unordered_set<int> unique;
	unique.insert(0);
	sort(activities.begin(), activities.end(), compareInterval);
	/*for (auto a : activities)
	{
		cout << "activities : " 
			<< a.start << a.end << endl;
	}*/

	for (int j = 1; j < activities.size(); j++)
	{
		if (activities[i].end <= activities[j].start)
		{
			unique.insert(j);
			i = j;
		}
	}

	for (int idx : unique)
	{
		cout << "{ "
			<< activities[idx].start
			<< ", "
			<< activities[idx].end
			<< " }"
			<< endl;
	}
}
int main()
{
	vector<Interval> activities =
	{
		{1, 4 }, { 3, 5 }, { 0, 6 }, { 5, 7 }, { 3, 8 },
		{ 5, 9 }, {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}
	};

	selectActivity(activities);
}