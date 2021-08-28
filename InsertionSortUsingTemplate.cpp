//
// Created by amartya on 26/08/21.
//

#include<iostream>
using namespace std;

template <class T>
        void InsertionSort(T array[], int n) {
            int j;
            T temp;    //template will help us creating the temp variable of the required type (int or char)

            for (int i = 1; i < n; ++i) {
                //storing the ith element in the temp variable and then assigning j as i-1 (so that we can compare the previous element of the array with ith element)
                temp = array[i];
                j = i - 1;

                //while loop for interchanging elements
                while (j >= 0 && array[j] > temp) {
                    array[j + 1] = array[j];   //storing the previous element in the next position if it is less than the previous one
                    j = j - 1;         //decreasing the value of j to run the loop for all elements
                }

                array[j + 1] = temp;    //storing the temp variable in the next position if the while loop condition is not satisfied
            }
        }

template <class T>
        //printing the array
        void Print(T array[], int n) {
            for (int i = 0; i < n; ++i) {
                cout << array[i] << ' ';
            }
            cout << endl;
        }

int main() {
    cout << "Insertion Sort Program for Integer and Character using common Template\nSelect your choice:\n";
    cout << "1. For Integer\n2. For Character\nOption: ";
    int choice;
    cin >> choice;

    switch (choice) {
        case 1: {
            int intArray[50];
            cout << "Enter the size of the Integer Array: ";
            int n;
            cin >> n;

            for (int i = 0; i < n; i++) {
                cout << "Enter element no. " << (i+1) << " in the Integer Array: ";
                cin >> intArray[i];
            }
            cout << "Integer Array Before Sort: ";
            Print(intArray, n);

            InsertionSort(intArray, n);

            cout << "Integer Array After Sort: ";
            Print(intArray, n);

            break;
        }
        case 2: {
            char charArray[50];
            cout << "Enter the size of the Character Array: ";
            int n;
            cin >> n;

            for (int i = 0; i < n; i++) {
                cout << "Enter element no. " << (i+1) << " in the Character Array: ";
                cin >> charArray[i];
            }

            cout << "Char Array Before Sort: ";
            Print(charArray, n);

            InsertionSort(charArray, n);

            cout << "Char Array After Sort: ";
            Print(charArray, n);

            break;
        }
        default: "Wrong Choice!";
    }
}