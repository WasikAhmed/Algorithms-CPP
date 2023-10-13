// If a set of items are given, each with a weight and a value, 
// the goal is to select a subset of the items that maximises the value while keeping the total weight below or equal to a given limit.

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define ff first
#define ss second

// Steps
// 1. Calculate the ratio (value/weight) for each item.
// 2. Sort the items in decreasing order of the ratio.
// 3. Initialize res = 0, curr_cap = given capacity
// 4. If the weight of the current item is less than or equal to the remaining capacity, 
//      then add the value of the item into the result
// 5. Else add the current item as much as we can and break out of the loop

bool compare(pii v1, pii v2) 
{
    double r1 = v1.ff / v1.ss;
    double r2 = v2.ff / v2.ss;

    return r1 > r2;
}

int main()
{
    int n; 
    cin>>n;
    vii v(n);

    rep(i, 0, v.size()) {
        cin>> v[i].ff;
        cin>> v[i].ss;
    }

    int w; 
    cin>> w;

    sort(v.begin(), v.end(), compare);

    cout<< "Sorted (value/weight): "<< endl;
    rep(i, 0, v.size()) {
        cout<< v[i].ff<< " "<< v[i].ss<< endl;
    }
    cout<< endl;

    int curr_cap = w, res = 0;

    rep(i, 0, v.size()) 
    {
        if(v[i].ss <= curr_cap) {
            res += v[i].ff;
            curr_cap -= v[i].ss;
            continue;
        }
        double vw = (double) v[i].ff / v[i].ss;
        res += vw * curr_cap;
        break; 
    }

    cout<< "Result: "<< res<< endl;

    return 0;
}