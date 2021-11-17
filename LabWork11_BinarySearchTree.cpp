//
// Created by amartya on 14/11/21.
//

#include <iostream>
#include<queue>

using namespace std;

template<class t>
class BinSearchTree {
public:
    BinSearchTree<t> *left;
    BinSearchTree<t> *right;
    t ele;
};

template<class t>
class tree {
private:
    BinSearchTree<t> *root;

public:
    tree(){
        root = 0;
    }

    BinSearchTree<t> *createNode(){
        cout << "Enter the value of the new node: " << endl;
        t data;
        cin >> data;
        auto *p = new BinSearchTree<t>;
        p->ele = data;
        p->left = 0;
        p->right = 0;

        return p;
    }

    void insert(BinSearchTree<t> *n) {
        BinSearchTree<t> *p = root;
        BinSearchTree<t> *prev = 0;
        while (p != 0) {
            prev = p;
            if (n->ele < p->ele)
                p = p->left;
            else
                p = p->right;
        }
        if (root == 0)
            root = n;
        else if (n->ele < prev->ele)
            prev->left = n;
        else if (n->ele >= prev->ele)
            prev->right = n;
    }

    void preorder(BinSearchTree<t> *p) {
        if (p != 0) {
            cout << p->ele << " ";
            preorder(p->left);
            preorder(p->right);
        }
    }

    void levelByLevel(BinSearchTree<t> *p) {
        cout << " Level By Level :- ";
        queue<BinSearchTree<t> *> a;
        if (p != 0) { // If tree is not empty
            a.push(p);
            while (!a.empty()) {
                BinSearchTree<t> *curr = a.front();
                a.pop();
                cout << curr->ele << " ";
                if (curr->left != 0) {
                    a.push(curr->left);
                }
                if (curr->right != 0) {
                    a.push(curr->right);
                }
            }
        } else
            cout << "Tree is empty\n";
    }

    void postOrder(BinSearchTree<t> *p) {

        if (p != 0) {
            postOrder(p->left);
            postOrder(p->right);
            cout << p->ele << " ";
        }
    }

    void inOrder(BinSearchTree<t> *p) {
        if (p != 0) {
            inOrder(p->left);
            cout << p->ele << " ";
            inOrder(p->right);
        }
    }

    void deleteNode(BinSearchTree<t> *&p) {
        BinSearchTree<t> *tmp = p;
        if (p->right == 0) {
            p = p->left;
        } else if (p->left == 0) {
            p = p->right;
        } else {
            tmp = p->left;
            while (tmp->right != 0) {
                tmp = tmp->right;
            }
            tmp->right = p->right;
            tmp = p;
            p = p->left;
        }
        delete tmp;
    }

    void deleteElement() {
        bool flag = false;
        BinSearchTree<t> *p = root, *prev = 0;
        if (root == 0)
            cout << "Tree is empty. " << endl;
        else {
            cout << "Enter the value to delete. " << endl;
            t data;
            cin >> data;

            while (p != 0) {
                if (p->ele == data) {
                    flag = true;
                    break;
                }
                prev = p;
                if (p->ele < data)
                    p = p->right;
                else
                    p = p->left;
            }

            if (p != 0 && p->ele == data) {
                if (p == root)
                    deleteNode(root);

                else if (prev->left == p)
                    deleteNode(prev->left);
                else
                    deleteNode(prev->right);
            } else
                cout << "Element not found ." << endl;
        }
    }

    void searchElement() {
        bool flag = false;
        BinSearchTree<t> *p = root, *prev = 0;
        if (root == 0)
            cout << "Tree is empty. " << endl;
        else {
            cout << "Enter the value to searchElement. " << endl;
            t data;
            cin >> data;

            while (p != 0) {
                if (p->ele == data) {
                    flag = true;
                    break;
                }
                prev = p;
                if (p->ele < data)
                    p = p->right;
                else
                    p = p->left;
            }
            if (flag)
                cout << "Element found\n";
            else cout << "Element not found\n";
        }
    }

    int height(BinSearchTree<t> *root) {
        if (root == 0)
            return 0;

        int left_height = height(root->left);
        int right_height = height(root->right);
        return max(left_height, right_height) + 1;
    }

    void usrSelection() {
        int choice;
        char repeat;
        do {
            cout << "1. Insert an element x\n2. Delete an element x\n3. Search for an element x and change its value to y\n";
            cout << "4. Display in preorder, postorder, inorder\n5. Display in level-by-level traversal\n6. Height of BST\n";
            cin >> choice;
            switch (choice) {
                case 1:
                    insert(createNode());
                    break;
                case 2:
                    deleteElement();
                    break;
                case 3:
                    searchElement();
                    break;
                case 4:
                    if (root != 0) {
                        cout << "PreOrder: ";
                        preorder(root);
                        cout << "\nPostOrder: ";
                        postOrder(root);
                        cout << "\nInOrder: ";
                        inOrder(root);
                    } else
                        cout << "Tree is empty\b";
                    break;
                case 5:
                    levelByLevel(root);
                    break;
                case 6:
                    if (root == 0)
                        cout << "Tree is empty\n";
                    else {
                        int n = height(root);
                        cout << "Height of the tree is " << n << endl;
                    }
                    break;
                default:
                    cout << "Wrong Choice!\n";
                    break;
            }
            cout << "\nDo you want to repeat? Y/N: ";
            cin >> repeat;
        } while (repeat == 'y' || repeat == 'Y');
    }
};


int main() {
    int type;
    cout << "1. Integer Operations. " << endl;
    cout << "2. String Operations. " << endl;
    cout << "3. Char Operations. " << endl;
    cout << "4. Float operations. " << endl;

    cin >> type;
    if (type == 1) {
        tree<int> myIntObj;
        myIntObj.usrSelection();
    } else if (type == 2) {
        tree<string> myStrObj;
        myStrObj.usrSelection();
    } else if (type == 3) {
        tree<char> myCharObj;
        myCharObj.usrSelection();
    } else if (type == 4) {
        tree<float> myFloatObj;
        myFloatObj.usrSelection();
    } else
        cout << "Wrong Choice!\n";

    return 0;
}