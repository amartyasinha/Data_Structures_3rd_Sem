//
// Created by amartya on 26/08/21.
//

#include<iostream>

using namespace std;

template<class T>
T array[50];
int n;

template<class T>
void input() {
    cout << "\nEnter the size of the Array: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\tEnter element no. " << (i + 1) << " in the Array: ";
        cin >> array<T>[i];
    }
}

template<class T>
//printing the array
void output() {
    for (int i = 0; i < n; ++i) {
        if (i != 0)
            cout << ", ";
        cout << array<T>[i];
    }
    cout << endl;
}

template<class T>
void InsertionSort() {
    int j;
    T temp;
    for (int i = 1; i < n; ++i) {
        //storing the ith element in the temp variable and then assigning j as i-1 (so that we can compare the previous element of the array with ith element)
        temp = array<T>[i];
        j = i - 1;
        //while loop for interchanging elements
        while (j >= 0 && array<T>[j] > temp) {
            array<T>[j +
                     1] = array<T>[j];   //storing the previous element in the next position if it is less than the previous one
            j = j - 1;         //decreasing the value of j to run the loop for all elements
        }

        array<T>[j +
                 1] = temp;    //storing the temp variable in the next position if the while loop condition is not satisfied
    }
}

template<class T>
void BubbleSort() {
    T temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (array<T>[j] > array<T>[j + 1]) {
                temp = array<T>[j];
                array<T>[j] = array<T>[j + 1];
                array<T>[j + 1] = temp;
            }
        }
    }
}

template<class T>
void SelectionSort() {
    T temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (array<T>[j] < array<T>[i]) {
                temp = array<T>[j];
                array<T>[j] = array<T>[i];
                array<T>[i] = temp;
            }
        }
    }
}

template<class T>
void usrSelection() {
    cout << "--------------------------------------";
    cout << "\nSelect from the followings:\n\t1. Insertion Sort\n\t2. Bubble Sort\n\t3. Selection Sort\nChoice: ";
    int choice;
    cin >> choice;
    cout << "--------------------------------------";

    input<T>();
    cout << "--------------------------------------\n";
    cout << "Array Before Sort: ";
    output<T>();

    switch (choice) {
        case 1:
            InsertionSort<T>();
            cout << "Array After Insertion Sort: ";
            output<T>();
            break;
        case 2:
            BubbleSort<T>();
            cout << "Array After Bubble Sort: ";
            output<T>();
            break;
        case 3:
            SelectionSort<T>();
            cout << "Array After Selection Sort: ";
            output<T>();
            break;
        default:
            cout << "Wrong Choice!";
    }
}

int main() {
    cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    cout << "\tSorting Program using Template\n";
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    cout << "1. For Integer\n2. For Character\n3. For Float\nSelect your DataType: ";
    int dataType;
    cin >> dataType;

    if (dataType == 1) {
        usrSelection<int>();
    } else if (dataType == 2) {
        usrSelection<char>();
    } else if (dataType == 3) {
        usrSelection<float>();
    } else
        cout << "Wrong Choice!\n";

    cout << "\nDo You want to repeat? Y/N: ";
    char repeat;
    cin >> repeat;
    if (repeat == 'Y' || repeat == 'y')
        main();
    else
        exit(0);
    return 0;
}