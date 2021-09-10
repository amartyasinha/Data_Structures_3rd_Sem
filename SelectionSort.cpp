//
// Created by amartya on 10/09/21.
//

#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "It is a Program to Preform Selection Sort\n\n";
    cout << "Enter number of elements: ";
    cin >> n;
    int array[n];

    for (int i = 0; i<n; i++){
        cout << "Enter element ["<<i<<"]: ";
        cin >> array[i];
    }

    cout << "\nArray you have entered is ";
    for (int i = 0; i<n; i++){
        if (i!=0) {
            cout << ", ";
        }
        cout << array[i];
    }

    int temp;

    for (int i = 0; i<n-1; i++){
        for (int j = i+1; j<n; j++){
            if (array[j]<array[i]){
                temp = array[j];
                array[j] = array[i];
                array[i] = temp;
            }
        }
    }

    cout << "\n\nAll elements after Selection Sort are ";
    for (int i = 0; i<n; i++){
        if (i!=0) {
            cout << ", ";
        }
        cout << array[i];
    }
    cout << endl;
    return 0;
}