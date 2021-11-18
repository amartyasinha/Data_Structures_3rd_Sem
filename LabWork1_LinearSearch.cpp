//
// Created by amartya on 18/11/21.
//

#include "iostream"
using namespace std;

int linearSearch(int array[], int x, int n){
    int i;
    for (i=0; i<n; i++){
        if (array[i] == x)
            return i;
    }
    return -1;
}

int main(){
    cout << "It is a Program to Perform Linear Search\n";
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int array[n];
    for (int i=0; i<n; i++){
        cout << "Enter element [" << i << "]: ";
        cin >> array[i];
    }
    int x;
    cout << "Enter the element that you want to search: ";
    cin >> x;
    int res = linearSearch(array, x, n);

    if (res == -1)
        cout << x << " not found\n";
    else
        cout << x << " found at index " << res;
    return 0;
}