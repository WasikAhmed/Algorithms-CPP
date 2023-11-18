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

int main() {
    int row1, col1;
    cin >> row1 >> col1;

    int A[row1][col1];
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col1; j++) {
            cin >> A[i][j];
        }
    }

    int row2, col2;
    cin >> row2 >> col2;

    int B[row2][col2];
    for (int i = 0; i < row2; i++) {
        for (int j = 0; j < col2; j++) {
            cin >> B[i][j];
        }
    }

    if (col1 != row2) {
        cout << "Matrix multiplication not possible" << endl;
        return 0;
    }

    int C[row1][col2]; // Resultant matrix

    // Multiplying matrices A and B
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < col1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Displaying the resultant matrix C
    cout << "Resultant matrix C:" << endl;
    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
