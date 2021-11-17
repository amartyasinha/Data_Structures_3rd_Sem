//
// Created by amartya on 16/10/21.
//

#include<iostream>
#include<exception>

using namespace std;

template<class T>
class Node {
public:
    T data;
    Node<T> *next;

    Node<T>(T data) {
        this->data = data;
        this->next = nullptr;
    }
};

class StackException : public exception {
    const char *message;
public:
    StackException(const char *message) {
        this->message = message;
    }

    const char *what() {
        return message;
    }
};

template<class T>
class Stack {
    Node<T> *head;
    Node<T> *tail;
    int nodes;
    int capacity;
public:
    Stack() {
        nodes = 0;
        head = nullptr;
        tail = nullptr;
        cout << "Enter capacity of Stack: ";
        cin >> capacity;
    }

    bool isEmpty() {
        return (nodes == 0) ? true : false;
    }

    bool isFull() {
        return (nodes == capacity) ? true : false;
    }

    void push() throw();

    void pop() throw();

    void printList();
};

template<class T>
void Stack<T>::push() throw() {
    try {
        if (isFull()) {
            throw StackException("Stack overFlow!");
        }
        T data;
        cout << "Enter data: ";
        cin >> data;
        Node<T> *newNode = new Node<T>(data);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = tail->next;
        }
        nodes++;
    }
    catch (StackException &e) {
        cout << e.what() << endl;
    }
}

template<class T>
void Stack<T>::pop() throw() {
    try {
        if (isEmpty()) {
            throw StackException("Stack underFlow!");
        }
        if (head->next == nullptr) {
            cout << "Popped Data: " << (head)->data << endl;
            delete head;
            head = tail = nullptr;
        } else {
            Node<T> *temp = head;
            while ((temp->next)->next != nullptr) {
                temp = temp->next;
            }
            Node<T> *deleteNode = temp->next;
            cout << "Popped Data: " << (temp->next)->data << endl;
            delete deleteNode;
            temp->next = nullptr;
            tail = temp;
        }
        nodes--;
    }
    catch (StackException &e) {
        cout << e.what() << endl;
    }
}

template<class T>
void Stack<T>::printList() {
    Node<T> *temp = head;
    cout << "Stack is: [";
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) {
            cout << ",";
        }
        temp = temp->next;
    }
    cout << "]\n";
}

int main() {
    Stack<int> ob;
    bool flag = true;
    int choice;

    while (flag) {
        cout << "1.Push\n";
        cout << "2.Pop\n";
        cout << "3.output Stack\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                ob.push();
                ob.printList();
                break;
            case 2:
                ob.pop();
                ob.printList();
                break;
            case 3:
                ob.printList();
                break;
            default:
                cout << "Wrong option entered!\n";
                break;
        }
        char ch;
        cout << "Press Y/y to continue: ";
        cin >> ch;
        if (ch != 'Y' and ch != 'y') {
            flag = false;
            break;
        }
    }
    return 0;
}