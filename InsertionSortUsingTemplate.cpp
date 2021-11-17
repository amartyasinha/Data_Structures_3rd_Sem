//
// Created by amartya on 26/08/21.
//

#include<iostream>
using namespace std;

template <class T>
T array[50];
int n;

template <class T>
void input(){
    cout << "Enter the size of the Integer Array: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter element no. " << (i+1) << " in the Array: ";
        cin >> array<T>[i];
    }
}

template <class T>
//printing the array
void output() {
    for (int i = 0; i < n; ++i) {
        cout << array<T>[i] << ' ';
    }
    cout << endl;
}
template <class T>
void InsertionSort() {
    input<T>();
    cout << "Array Before Insertion Sort: ";
    output<T>();

    int j;
    T temp;
    for (int i = 1; i < n; ++i) {
        //storing the ith element in the temp variable and then assigning j as i-1 (so that we can compare the previous element of the array with ith element)
        temp = array<T>[i];
        j = i - 1;
        //while loop for interchanging elements
        while (j >= 0 && array<T>[j] > temp) {
            array<T>[j + 1] = array<T>[j];   //storing the previous element in the next position if it is less than the previous one
            j = j - 1;         //decreasing the value of j to run the loop for all elements
        }

        array<T>[j + 1] = temp;    //storing the temp variable in the next position if the while loop condition is not satisfied
    }
    cout << "Array After Insertion Sort: ";
    output<T>();
}


int main() {
    cout << "Insertion Sort Program for Integer and Character using common Template\nSelect your choice:\n";
    cout << "1. For Integer\n2. For Character\n3. For Float\nOption: ";
    int choice;
    cin >> choice;

        if (choice == 1) {
            InsertionSort<int>();
        }
        else if (choice == 2) {
            InsertionSort<char>();
        }
        else if (choice == 3) {
            InsertionSort<float>();
        }
        else
            cout << "Wrong Choice!\n";
}