#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int value) {

    int low = 0, high = n-1;
    while(low<high) {
        int mid = low + (high - low) / 2;

        if(arr[mid] == value) {
            return mid;
        }

        if(arr[mid] > value) {
            high = mid - 1;
        }

        if(value > arr[mid]) {
            low = mid + 1;
        }
    }

    return -1;
}

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

void insertElements(int arr[], int n) {

    for(int i=0; i<n; i++) {
        cin>> arr[i];
    }
}

void displayArray(int arr[], int n) {
    
    for(int i=0; i<n; i++) {
        cout<< arr[i]<< " ";
    }
    cout<< endl;
}

int main() {
    
    int n;
    cout<< "Enter array size: ";
    cin>> n;

    int arr[n];
    cout<< "Enter array elements: ";
    insertElements(arr, n);

    int value;
    cout<< "Enter a value to search: ";
    cin>> value;

    bubbleSort(arr, n);
    cout<< "Sorted array: ";
    displayArray(arr, n);

    int foundIndex = binarySearch(arr, n, value);
    if(foundIndex == -1) {
        cout<< "Element not found!"<< endl;
    } else {
        cout<< "Element found at index "<< foundIndex<< "!"<< endl;
    }

    return 0;
}