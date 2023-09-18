#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {

    for(int i=1; i<n; i++) {
        int key = arr[i];
        int j = i-1;

        while(j>=0 && arr[j]>key) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        
        arr[j+1] = key;
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

    insertionSort(arr, n);
    cout<< "Sorted array: ";
    displayArray(arr, n);

    return 0;
}