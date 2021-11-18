//
// Created by amartya on 18/11/21.
//

#include "iostream"
#include "stack"
using namespace std;

int prefix(string expression){
    stack<int> myStack;

    for (int i = expression.size()-1; i >=0; i--) {
        if (isdigit(expression[i]))
        myStack.push(expression[i] - '0');
        else {
            int op1 = myStack.top();
            myStack.pop();
            int op2 = myStack.top();
            myStack.pop();

            if (expression[i] == '+')
                myStack.push(op1 + op2);
            if (expression[i] == '-')
                myStack.push(op1 - op2);
            if (expression[i] == '*')
                myStack.push(op1 * op2);
            if (expression[i] == '/')
                myStack.push(op1 / op2);
        }
    }
    return myStack.top();
}

int postfix(string expression){
    stack<int> myStack;

    for (int i = 0; i <= expression.size()-1; i++){
        if (isdigit(expression[i]))
            myStack.push(expression[i] - '0');
        else {
            int op1 = myStack.top();
            myStack.pop();
            int op2 = myStack.top();
            myStack.pop();

            if (expression[i] == '+')
                myStack.push(op2 + op1);
            if (expression[i] == '-')
                myStack.push(op2 - op1);
            if (expression[i] == '*')
                myStack.push(op2 * op1);
            if (expression[i] == '/')
                myStack.push(op2 / op1);
        }
    }
    return myStack.top();
}

int main(){
    cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    cout << "\tIt is a program to evaluate Prefix and Postfix expressions\n";
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";

    string expression;
    int result;
    cout << "Enter your expression: ";
    cin >>  expression;
    cout << "Select the type of your expression:\n\t1. PreFix\n\t2. PostFix\nChoice: ";
    int choice;
    cin >> choice;
    if (choice == 1) {
        result = prefix(expression);
        cout << "The value of your prefix expression is " <<result << endl;

    }
    else if (choice == 2) {
        result = postfix(expression);
        cout << "The value of your postfix expression is " <<result << endl;
    }
    else
        cout << "Wrong Option!";

    cout << "Do you want to repeat? Y/N: ";
    char repeat;
    cin >> repeat;
    if (repeat == 'y' || repeat == 'Y')
        main();
    return 0;
}