// select the maximum number of activities that can be performed by a single person or machine, 
// assuming that a person can only work on a single activity at a time.

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
#define for_each(x,y) for(auto &x : y)
#define pb push_back
#define ff first
#define ss second

// steps
// 1. Sort the activities according to their finishing time 
// 2. Select the first activity from the sorted array and print it 
// 3. Do the following for the remaining activities in the sorted array
//      -> If the start time of this activity is greater than or equal to the finish time of the previously selected activity
//      -> then select this activity and print it

struct Activity 
{
    char id;
    int start;
    int end;
};

bool compare(Activity a, Activity b) 
{
    return a.end < b.end;
}

int main()
{
    int n;
    cin>> n;
    vector<Activity> activities(n);

    rep(i,0,activities.size()) 
    {
        cin>> activities[i].id;
        cin>> activities[i].start;
        cin>> activities[i].end;
    }

    sort(activities.begin(), activities.end(), compare);    

    cout<< "Sorted activies according to finish time: \n";
    rep(i,0,activities.size()) 
    {
        cout<<activities[i].id<< " "<< activities[i].start<< " "<< activities[i].end<< endl; 
    }

    cout<< "Selected activities: "<< endl;
    cout<< activities[0].id<< " ";

    int prev_end = activities[0].end;

    for_each(activity, activities) 
    {
        if(activity.start >= prev_end) {
            cout<< activity.id<< " ";
            prev_end = activity.end;
        }
    }
    cout<< endl;

    return 0;
}