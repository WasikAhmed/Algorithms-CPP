#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int element) {
    for(int i=0; i<n; i++) {
        if(arr[i] == element) {
            return i;
        }
    }
    return -1;
}

int main() {

    int n;
    cout<< "Enter array size: ";
    cin>> n;

    int arr[n];
    cout<< "Enter array elements: ";
    for(int i=0; i<n; i++) {
        cin>> arr[i];
    }

    int value;
    cout<< "Enter a value to search: ";
    cin>> value;

    int foundIndex = linearSearch(arr, n, value);
    if(foundIndex == -1) {
        cout<< "Element not found!"<< endl;
    } else {
        cout<< "Element found at index "<< foundIndex<< "!"<< endl;
    }

    return 0;
}