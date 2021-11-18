//
// Created by amartya on 18/11/21.
//

#include "iostream"
using namespace std;

int binarySearch(int array[], int x, int n){
    int beg = 0;
    int end = n-1;
    while (end >= beg){
        int mid = (beg + end)/2;
        if (array[mid] == x)
            return mid;
        else if (array[mid] < x)
            beg = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}

int main(){
    cout << "It is a Program to Perform Binary Search\n";
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
    int res = binarySearch(array, x, n);

    if (res == -1)
        cout << x << " not found\n";
    else
        cout << x << " found at index " << res;
    return 0;
}