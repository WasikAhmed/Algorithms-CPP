// counting sort
// non comparison-based sorting algorithm
// works well when there is limited number of input values
// efficient when the range of input values is small compared to the number of elements to be sorted

// steps ->
// step 1 : find out the maximum element from given array
// step 2 : initialize a count array of length max+1 with all elements as 0
// step 3 : store the count of each unique element of the input array at their respective indices in count array
// step 4 : store the commulative sum of the elements of the count array
// step 5 : iterate from the end of input array. update output array 
//          outputArray[countArray[inputArray[i]]-1] = inputArray[i]
//          update count array
//          countArray[inputArray[i]] = countArray[inputArray[i]] - 1

#include <iostream>
using namespace std;

void inputArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cin>> arr[i];
    }
}

void inputArray(int arr[], int n, int value) {
    for(int i=0; i<n; i++) {
        arr[i] = value;
    }
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout<< arr[i]<< " ";
    }
    cout<< endl;
}

int findMax(int arr[], int n) {
    int maxValue = arr[0];
    for(int i=1; i<n; i++ ) {
        if(arr[i] > maxValue) {
            maxValue = arr[i];
        }
    }

    return maxValue;
}

int* countingSort(int arr[], int n, int maxValue) {
    int* sortedArray = new int[n];
    int countArray[maxValue+1];
    inputArray(countArray, maxValue+1, 0);

    for(int i=0; i<n; i++) {
        countArray[arr[i]] = countArray[arr[i]] + 1;
    }

    for(int i=1; i<maxValue+1; i++) {
        countArray[i] = countArray[i] + countArray[i-1];
    }

    for(int i=n-1; i>=0; i--) {
        sortedArray[countArray[arr[i]]-1] = arr[i];
        countArray[arr[i]] = countArray[arr[i]] - 1;
    }

    return sortedArray;
}

int main() {

    int n;
    cout<< "Please enter array size: ";
    cin>> n;

    int A[n];
    cout<< "Please input array elements: ";
    inputArray(A, n);

    cout<< "Input array: ";
    printArray(A, n);

    int max = findMax(A, n);

    int* sortedArray = countingSort(A, n, max);
    cout<< "Sorted array: ";
    printArray(sortedArray, n);

    return 0;
}