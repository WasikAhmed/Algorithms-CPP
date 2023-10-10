#include <iostream>
using namespace std;

int factorial(int x) {
    int fact;
    if(x<=1) {
        return 1;
    }
    fact = x * factorial(x-1);

    return fact;
}

int main() {

    int n;
    cout<< "Please enter a non-negative integer value: ";
    cin>> n;

    while(n<0) {
        cout<< "The value is negative.\nPlease enter a non-negative integer value: ";
        cin>> n;
    }

    int fact = factorial(n);

    cout<< "Factorial of "<< n<< ": "<< fact<< endl;

    return 0;
}