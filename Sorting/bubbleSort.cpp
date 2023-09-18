#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    bool swapped;
    for(int i=0; i<n-1; i++) {
        swapped = false;
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if(swapped == false) 
            break;
    }
}

int main() {

    int n;
    cout<< "Please enter array size: ";
    cin>> n;

    int arr[n];
    cout<< "Please enter array elements: ";
    for(int i=0; i<n; i++) {
        cin>> arr[i];
    }

    bubbleSort(arr, n);

    cout<< "Sorted array: ";
    for(int i=0; i<n; i++) {
        cout<< arr[i]<< " ";
    }
    cout<< endl;

    return 0;
}