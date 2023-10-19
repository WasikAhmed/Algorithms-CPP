#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
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

bool binarySearch(vi v, int val, int l, int r)
{
    if(r >= l) {
        // int mid = l + (r - l) / 2;
        int mid = ( l + r) / 2;

        if(v[mid] == val) {
            return true;
        }

        if(v[mid] > val) {
            return binarySearch(v, val, l, mid - 1);
        }

        if(v[mid] < val) {
            return binarySearch(v, val, mid + 1, r);
        }
    }
    
    return false;
}

int main()
{
    cout<< "Input array size: ";
    int n; cin>> n;

    vi v(n);
    cout<< "Input array elements: ";
    rep(i,0,v.size()) 
    {
        cin>> v[i];
    }

    cout<< "Enter value to search: ";
    int val; cin>> val;

    cout<< "Sorted array: ";
    sort(v.begin(), v.end());
    for_each(element, v)
    {
        cout<< element<< " ";
    }
    cout<< endl;

    bool result = binarySearch(v, val, 0, v.size()-1);

    cout<< "Element found: "<< result<< endl;

    return 0;
}