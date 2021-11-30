#include <iostream>

using namespace std;

class Node{
    public:
    int number;
    Node *next;
};

Node *stack;

void push(int num){
    Node *newNode;
    newNode = new Node();

    newNode->number = num;
    newNode->next = stack;
    stack = newNode;
    cout << num << " pushed" << endl;
}

int empty(){
    return stack == NULL;
}

void peek(){
    if (!empty()){
        cout << "Topmost element: " << stack->number << endl;
    }
    else{
        cout << "Stack Empty" << endl;
    }
}

void pop(){
    Node *newNode;

    if (stack == NULL){
        cout << "Stack Underflow" << endl;
    }
    else {
        newNode = stack;
        stack = stack->next;
        newNode->next = NULL;
        cout << newNode->number << " popped" << endl;
        free(newNode);
    }
}

void display(){
    Node *newNode;
    if (stack == NULL){
        cout << "Stack Empty" << endl;
    }
    else{
        cout << "Stack elements: ";
        newNode = stack;
        while (newNode != NULL){
            cout << newNode->number << " ";
            newNode = newNode->next;
        }
        cout << endl;
    }
}

int main(){

    cout << "Subhendu Dash\n20BEE1004" << endl;

    push(1);
    push(2);
    display();
    push(3);
    peek();
    pop();
    display();
    push(4);
    display();

    return 0;
}