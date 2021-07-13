// Job sequencing problem with deadlines

// Tasks	Deadlines	Profit
//   1	       9	       15
//   2	       2	       2
//   3	       5	       18
//   4	       7	       1
//   5	       4	       25
//   6	       2	       20
//   7	       5	       8
//   8	       7	       10
//   9	       4	       12
//   10	       3	       5

// Tasks	Deadlines	Profit(Maximum first)
//   5	       4	           25
//   6	       2	           20
//   3	       5	           18
//   1	       9	           15
//   9	       4	           12
//   8	       7	           10
//   7	       5	           8
//   10	       3	           5
//   2	       2	           2
//   4	       7	           1

// Time complexity is O(n**2)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define T 15

struct Job
{
	int taskID;
	int deadline;
	int profit;
};

void scheduleJobs(vector<Job> jobs)
{
	// cout << "T is " << T << endl;
	int profit = 0;
	vector<int> slot(T, -1);
	/*for (auto s : slot)
	{
		cout << "slot s is " << s << endl;
	}*/

	sort(
		jobs.begin(), 
		jobs.end(), 
		[](Job& a, Job& b) 
		{
			return a.profit > b.profit; 
		});

	/*for (auto job : jobs)
	{
		cout << "jobs.profit is " 
			<< job.profit << endl;
	}*/

	for (Job job : jobs)
	{
		for (int d = job.deadline - 1; d >= 0; d--)
		{
			if (d < T && slot[d] == -1)
			{
				slot[d] = job.taskID;
				profit += job.profit;
				// cout << "slot[d] is " << slot[d] << endl;
				break;
			}
		}
	}
	// cout << "Type of T is " << typeid(T).name() << endl;

	/*for (auto it = slot.begin(); it != slot.end(); it++)
	{
		cout << "it is " << *it << endl;
	}*/
	cout << "The scheduled jobs are ";
	for (int i = 0; i < T; i++)
	{
		if (slot[i] != -1)
		{
			cout << slot[i] << " ";
		}
	}

	cout << "\nThe total profit earned is " << profit << endl;
}
int main()
{
	vector<Job> jobs =
	{
		{ 1, 9, 15 }, { 2, 2, 2 }, { 3, 5, 18 }, { 4, 7, 1 }, { 5, 4, 25 },
		{ 6, 2, 20 }, { 7, 5, 8 }, { 8, 7, 10 }, { 9, 4, 12 }, { 10, 3, 5 }
	};

	scheduleJobs(jobs);
}