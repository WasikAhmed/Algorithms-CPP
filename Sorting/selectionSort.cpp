#include <iostream>
using namespace std;

void selectionSort(int arr[], int n)
{
	int i, j, minIndex;

	for (i = 0; i < n - 1; i++) {

		minIndex = i;
		for (j=i+1; j<n; j++) {
			if (arr[j] < arr[minIndex])
				minIndex = j;
		}

		if (minIndex != i){
			swap(arr[minIndex], arr[i]);
		}		
	}
}

void printArray(int arr[], int n)
{
	for(int i=0; i<n; i++) {
		cout<< arr[i]<< " ";
	}
	cout<< endl;
}

int main()
{
	int arr[] = { 64, 25, 12, 22, 11 };
	int n = sizeof(arr) / sizeof(arr[0]);

	cout<< "Input array: ";
	printArray(arr, n);

	selectionSort(arr, n);
	cout << "Sorted array: ";
	printArray(arr, n);

	return 0;
}

