//
// Created by amartya on 5/10/21.
//

#include <iostream>
using namespace std;

template<class t>
class Node {
public:
    t elem;
    Node *next;
    Node *prev;
};

template<class t>
class List {
public:
    List<t>();

    bool empty();         // Checks if First list is empty
    void addFirst();      //Add element/ at the first position of first list
    void addith();        // Add element at the ith position of first list
    void addEnd();        //Add element at the last position of first list
    void removeFirst();   // Remove first element of the first list
    void removeIth();     // Remove ith element of the first list
    void removeLast();    // Remove last element of the first list
    void searchElement(); //Search for an element
    void concatenate();   //Concatenate two list
    void display();       // Display elements of the first list

    void secondListData();    // Takes data of the second List
    bool secondEmpty();       // Checks if Second list is empty
    void addSecondFirst();    //Add element/ at the first position of second list
    void addSecondIth();      // Add element at the ith position of second list
    void addSecondEnd();      //Add element at the last position of second list
    void removeSecondFirst(); // Remove first element of the second list
    void removeSecondIth();   // Remove ith element of the  second list
    void removeSecondLast();  // Remove last element of the  second list
    void displaySecond();     // Display elements of the second list

private:
    Node<t> *header;
    Node<t> *tailer;
    Node<t> *header2;
    Node<t> *tailer2;
};

template<class t>
List<t>::List() {
    header = new Node<t>;
    tailer = new Node<t>;
    header->next = tailer;
    tailer->prev = header;
    header2 = new Node<t>;
    tailer2 = new Node<t>;
    header2->next = tailer2;
    tailer2->prev = header2;
}

template<class t>
bool List<t>::secondEmpty() {
    if (header2->next == tailer2) {
        return true;
    } else
        return false;
}

template<class t>
void List<t>::displaySecond() {
    if (secondEmpty() != true) {
        cout << "Element in the list are :- " << endl;
        Node<t> *p = new Node<t>;
        p = header2->next;
        while (p != tailer2) {

            cout << p->elem << " ";
            p = p->next;
        }
    } else {
        cout << "List is empty ." << endl;
    }
    cout << endl;
}

template<class t>
void List<t>::addSecondFirst() {

    cout << "Enter the value in the node." << endl;
    t ele;
    cin >> ele;

    if (secondEmpty() == true) {
        Node<t> *n = new Node<t>;
        n->elem = ele;
        n->next = tailer2;
        n->prev = tailer2->prev;
        tailer2->prev = n;
        header2->next = n;
    } else {
        Node<t> *n = new Node<t>;

        n->next = header2->next;
        header2->next->prev = n;
        n->prev = header2;
        n->elem = ele;
        header2->next = n;
    }
}

template<class t>
void List<t>::addSecondIth() {
    displaySecond();
    int i;
    int count = 0;
    t ele;
    cout << "Enter the position to add the element . " << endl;
    cin >> i;
    cout << "Enter the element ." << endl;
    cin >> ele;
    Node<t> *p = new Node<t>;
    Node<t> *n = new Node<t>;
    p = header2->next;
    while (p != tailer2) {

        if (count == i - 1) {
            p->prev->next = n;
            n->next = p;
            n->elem = ele;
            n->prev = p->prev;
            p->prev = n;
        }
        p = p->next;
        count++;
    }
}

template<class t>
void List<t>::addSecondEnd() {
    t ele;
    Node<t> *n = new Node<t>;
    cout << "Enter the element :" << endl;
    cin >> ele;
    if (secondEmpty() == true) {
        n->next = header2->next;
        n->prev = header2;
        header2->next = n;
        tailer2->prev = n;
        n->elem = ele;
    } else {
        n->next = tailer2;
        n->prev = tailer2->prev;
        tailer2->prev->next = n;
        tailer2->prev = n;
        n->elem = ele;
    }
}

template<class t>
void List<t>::removeSecondFirst() {
    if (secondEmpty() == true) {
        cout << "List is empty ." << endl;
    } else {
        Node<t> *p = new Node<t>;
        p = header2->next;

        header2->next = p->next;
        p->next->prev = header2;
        cout << "Element " << p->elem << " deleted . " << endl;
        delete p;
    }
}

template<class t>
void List<t>::removeSecondIth() {
    displaySecond();
    if (empty() != true) {
        cout << "Enter the position of the element you want to delete ." << endl;
        int i;
        cin >> i;
        Node<t> *p = new Node<t>;
        p = header2->next;
        int counter = 1;
        while (p != tailer2) {
            if (counter == i) {
                p->prev->next = p->next;
                p->next->prev = p->prev;
                cout << "Element " << p->elem << " deleted . " << endl;
                delete p;

                break;
            }
            counter++;
            p = p->next;
        }
    }
}

template<class t>
void List<t>::removeSecondLast() {
    if (secondEmpty() == true) {
        cout << "List is empty " << endl;
    } else {
        Node<t> *p = new Node<t>;
        p = tailer2->prev;
        p->prev->next = tailer2;
        tailer2->prev = p->prev;
        cout << "Element " << p->elem << " deleted . " << endl;
        delete p;
    }
}

template<class t>
bool List<t>::empty() {
    if (header->next == tailer) {
        return true;
    } else
        return false;
}

template<class t>
void List<t>::addFirst() {
    cout << "Enter the value in the node." << endl;
    t ele;
    cin >> ele;

    if (empty() == true) {
        Node<t> *n = new Node<t>;
        n->elem = ele;
        n->next = tailer;
        n->prev = tailer->prev;
        tailer->prev = n;
        header->next = n;
    } else {
        Node<t> *n = new Node<t>;

        n->next = header->next;
        header->next->prev = n;
        n->prev = header;
        n->elem = ele;
        header->next = n;
    }
}

template<class t>
void List<t>::addith() {
    display();
    int i;
    int count = 0;
    t ele;
    cout << "Enter the position to add the element . " << endl;
    cin >> i;
    cout << "Enter the element ." << endl;
    cin >> ele;
    Node<t> *p = new Node<t>;
    Node<t> *n = new Node<t>;
    p = header->next;
    while (p != tailer) {

        if (count == i - 1) {
            p->prev->next = n;
            n->next = p;
            n->elem = ele;
            n->prev = p->prev;
            p->prev = n;
        }
        p = p->next;
        count++;
    }
}

template<class t>
void List<t>::addEnd() {
    t ele;
    Node<t> *n = new Node<t>;
    cout << "Enter the element :" << endl;
    cin >> ele;
    if (empty() == true) {
        n->next = header->next;
        n->prev = header;
        header->next = n;
        tailer->prev = n;
        n->elem = ele;
    } else {
        n->next = tailer;
        n->prev = tailer->prev;
        tailer->prev->next = n;
        tailer->prev = n;
        n->elem = ele;
    }
}

template<class t>
void List<t>::removeFirst() {
    if (empty() == true) {
        cout << "List is empty ." << endl;
    } else {
        Node<t> *p = new Node<t>;
        p = header->next;

        header->next = p->next;
        p->next->prev = header;
        cout << "Element " << p->elem << " deleted . " << endl;
        delete p;
    }
}

template<class t>
void List<t>::removeIth() {
    display();
    if (empty() != true) {
        cout << "Enter the position of the element you want to delete ." << endl;
        int i;
        cin >> i;
        Node<t> *p = new Node<t>;
        p = header->next;
        int counter = 1;
        while (p != tailer) {
            if (counter == i) {
                p->prev->next = p->next;
                p->next->prev = p->prev;
                cout << "Element " << p->elem << " deleted . " << endl;
                delete p;

                break;
            }
            counter++;
            p = p->next;
        }
    }
}

template<class t>
void List<t>::removeLast() {
    if (empty() == true) {
        cout << "List is empty " << endl;
    } else {
        Node<t> *p = new Node<t>;
        p = tailer->prev;
        p->prev->next = tailer;
        tailer->prev = p->prev;
        cout << "Element " << p->elem << " deleted . " << endl;
        delete p;
    }
}

template<class t>
void List<t>::searchElement() {
    t x;
    bool flag = false;
    int counter = 1;
    cout << "Enter the X element to searchElement . " << endl;
    cin >> x;
    Node<t> *p = new Node<t>;

    p = header->next;
    while (p != tailer) {
        if (p->elem == x) {
            cout << "Element is found at the position " << counter << endl;
            cout << "It's pointer is " << p->prev << endl;
            flag = true;
            break;
        }
        counter++;
        p = p->next;
    }
    if (flag == false) {
        cout << "Element is not found in the list :" << endl;
    }
}

template<class t>
void List<t>::secondListData() {

    int choice;
    char repeat;
    do {
        cout << "Enter 1: To add at the first of the second List . " << endl;
        cout << "Enter 2: TO add at the  ith position of the second List . " << endl;
        cout << "Enter 3: To display  the second List." << endl;
        cout << "Enter 4: To add at the end of the second List ." << endl;
        cout << "Enter 5: To delete from first of the second List ." << endl;
        cout << "Enter 6: To delete at ith position of the second List ." << endl;
        cout << "Enter 7: TO delete from last of the second List . " << endl;
        cout << "************************" << endl << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                addSecondFirst();

                break;
            case 2:
                addSecondIth();
                break;
            case 3:
                displaySecond();
                break;
            case 4:
                addSecondEnd();
                break;
            case 5:
                removeSecondFirst();
                break;
            case 6:
                removeSecondIth();
                break;
            case 7:
                removeSecondLast();
                break;

            default:
                cout << "INvalid choice ." << endl;
                break;
        }
        cout << "Want to repeat in the second List  ? Y / N ?" << endl;
        cin >> repeat;
        cout << "**********************" << endl;
    } while (repeat == 'y' || repeat == 'Y');
}

template<class t>
void List<t>::concatenate() {
    cout << "Elements in the both list are :- " << endl;
    Node<t> *p = new Node<t>;
    p = header->next;
    while (p != tailer2) {
        cout << p->elem;
        p = p->next;
        if (p->next == tailer) {
            p->next = header2->next;
        }
    }
}

template<class t>
void List<t>::display() {

    if (empty() != true) {
        cout << "Element in the list are :- " << endl;
        Node<t> *p = new Node<t>;
        p = header->next;
        while (p != tailer) {

            cout << p->elem << " ";
            p = p->next;
        }
    } else {
        cout << "List is empty ." << endl;
    }
    cout << endl;
}

int main() {

    cout << "Enter 1: To enter integer values " << endl;
    cout << "Enter 2: To enter string values . " << endl;
    int type;
    cin >> type;
    if (type == 1) {
        List<int> l;
        char choice;
        int enter;
        do {
            cout << "Enter 1: To add at the first . " << endl;
            cout << "Enter 2: TO add at the  ith position . " << endl;
            cout << "Enter 3: To display ." << endl;
            cout << "Enter 4: To add at the end ." << endl;
            cout << "Enter 5: To delete from first ." << endl;
            cout << "Enter 6: To delete at ith position ." << endl;
            cout << "Enter 7: To delete from last . " << endl;
            cout << "Enter 8 : To searchElement an element in the list :" << endl;
            cout << "Enter 9 : To add Data in the second List . " << endl;
            cout << "Enter 10 : To concatenate both list and print the elements ." << endl;
            cout << "************************" << endl << endl;
            cin >> enter;
            switch (enter) {
                case 1:

                    l.addFirst();
                    break;
                case 2:
                    l.addith();
                    break;
                case 3:
                    l.display();
                    break;
                case 4:
                    l.addEnd();
                    break;
                case 5:
                    l.removeFirst();
                    break;
                case 6:
                    l.removeIth();
                    break;
                case 7:
                    l.removeLast();
                    break;
                case 8:
                    l.searchElement();
                    break;
                case 9:
                    l.secondListData();
                    break;
                case 10:
                    l.concatenate();
                    break;

                default:
                    cout << "INVALID CHOICE ." << endl;
                    break;
            }
            cout << "\nDo you want to repeat in the First List  ? Y or N " << endl;
            cin >> choice;
        } while (choice == 'y' || choice == 'Y');
    } else if (type == 2) {
        List<string> l;
        char choice;
        int enter;
        do {
            cout << "Enter 1: To add at the first . " << endl;
            cout << "Enter 2: TO add at the  ith position . " << endl;
            cout << "Enter 3: To display ." << endl;
            cout << "Enter 4: To add at the end ." << endl;
            cout << "Enter 5: To delete from first ." << endl;
            cout << "Enter 6: To delete at ith position ." << endl;
            cout << "Enter 7: TO delete from last . " << endl;
            cout << "Enter 8 : To searchElement an element in the list :" << endl;
            cout << "Enter 9 : To add Data in the second List . " << endl;
            cout << "Enter 10 : To concatenate both list and print the elements ." << endl;
            cout << "**********************" << endl << endl;
            cin >> enter;
            switch (enter) {
                case 1:

                    l.addFirst();
                    break;
                case 2:
                    l.addith();
                    break;
                case 3:
                    l.display();
                    break;
                case 4:
                    l.addEnd();
                    break;
                case 5:
                    l.removeFirst();
                    break;
                case 6:
                    l.removeIth();
                    break;
                case 7:
                    l.removeLast();
                    break;
                case 8:
                    l.searchElement();
                    break;
                case 9:
                    l.secondListData();
                    break;
                case 10:
                    l.concatenate();
                    break;

                default:
                    cout << "INVALID CHOICE ." << endl;
                    break;
            }
            cout << "\nDo you want to repeat in the First List  ? Y or N " << endl;
            cin >> choice;
        } while (choice == 'y' || choice == 'Y');
    }

    return 0;
}