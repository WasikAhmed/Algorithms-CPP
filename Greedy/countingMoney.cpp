// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
// Return the fewest number of coins that you need to make up that amount.
// If that amount of money cannot be made up by any combination of the coins, return -1.
// You may assume that you have an infinite number of each kind of coin.

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

#define vi vector<int>
#define pii pair<int,int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define pb push_back
#define ff first
#define ss second

// Steps
// 1. Sort the array of coins in decreasing order
// 2. Initialize ans vector as empty
// 3. Find the largest denomination that is smaller than remaining amount and while it is smaller than the remaining amount: 
//        Add found denomination to ans. Subtract value of found denomination from amount.
// 4. If amount becomes 0, then print ans.

int main()
{
    int n;
    cout<< "Input coins: ";
    cin>> n;
    vi coins(n);

    rep(i, 0, coins.size())
    {
        cin>> coins[i];
    }
    int amount;
    cout<< "Enter amount: ";
    cin>> amount;

    sort(coins.begin(), coins.end(), greater<int>());

    cout<< "Sorted coins: ";
    rep(i, 0, coins.size())
    {
        cout<< coins[i]<< " ";
    }
    cout<< endl;
    
    vi ans;
    rep(i, 0, coins.size()) 
    {
        while(amount >= coins[i]) {
            amount -= coins[i];
            ans.pb(coins[i]);
        }
    }

    cout<< "Minimum Coins needed: ";
    if(ans.size() != 0 && amount == 0) {
        rep(i, 0, ans.size()) 
        {
            cout<< ans[i]<< " ";
        }
    cout<< endl;
    } else {
        cout<< -1<< endl;
    }

    return 0;
}