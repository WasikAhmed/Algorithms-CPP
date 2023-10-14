// Given an array of jobs where every job has a deadline and associated profit 
// if the job is finished before the deadline. 
// It is also given that every job takes a single unit of time, 
// so the minimum possible deadline for any job is 1. 
// Maximize the total profit if only one job can be scheduled at a time.

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define rrep(i,a,b) for(int i=a-1; i>=b; i--)
#define pb push_back
#define ff first
#define ss second

// Steps
// 1. Sort all jobs in decreasing order of profit. 
// 2. Iterate on jobs in decreasing order of profit.For each job , do the following : 
//      -> Find a time slot i, such that slot is empty and i < deadline and i is greatest.
//        Put the job in this slot and mark this slot filled. 
//      -> If no such i exists, then ignore the job.

struct Job
{
    char id;
    int deadline;
    int profit;
};

bool compare(Job j1, Job j2)
{
    return j1.profit > j2.profit;
}

int main()
{
    cout<< "Input jobs: ";
    int n; cin>> n;
    vector<Job> jobs(n);

    rep(i, 0, jobs.size()) 
    {
        cin>> jobs[i].id;
        cin>> jobs[i].deadline;
        cin>> jobs[i].profit;
    }

    sort(jobs.begin(), jobs.end(), compare);

    cout<< "Sorted jobs (decreasing order by profit)\n";
    rep(i, 0, jobs.size()) 
    {
        cout<< jobs[i].id<< " "<< jobs[i].deadline<< " "<< jobs[i].profit<< endl;
    }

    int maxDeadLine=0;
    rep(i, 0, jobs.size()) 
    {
        maxDeadLine = max(maxDeadLine, jobs[i].deadline);
    } 
    cout<< "Maximum deadline: "<< maxDeadLine<< endl;

    vector<bool> slot(maxDeadLine, 0);
    vector<Job> schedule;

    rep(i, 0, jobs.size()) 
    {
        rrep(j, jobs[i].deadline-1, 0)
        {
            if(slot[j]==false) {
                slot[j] = true;
                schedule.pb(jobs[i]);
                break;
            }
        }
    }

    cout<< "Scheduled jobs: "<< endl;
    rep(i,0,schedule.size()) 
    {
        cout<< schedule[i].id<< " ";
    }


    return 0;
}