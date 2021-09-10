//
// Created by amartya on 10/09/21.
//

#include <iostream>
using namespace std;

int main() {

    int n;

    cout << "It is a Program to Preform Bubble Sort\n\n";
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
    int count = 0;

    for (int i = 0; i<n; i++){
        for (int j = i+1; j<n; j++){
            if (array[i]>array[j]){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    cout << "\n\nAll elements after Bubble Sort are ";
    for (int i = 0; i<n; i++){
        if (i!=0) {
            cout << ", ";
        }
        cout << array[i];
    }
    cout << endl;
}
