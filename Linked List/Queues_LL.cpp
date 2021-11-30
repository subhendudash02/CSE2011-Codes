#include <iostream>

using namespace std;

class Node {
    public:
    int number;
    Node* next;
};

Node *front, *rear = NULL;

void enqueue(int num) {
    Node* current = new Node();
    current->number = num;
    current->next = NULL;
    
    if (front == NULL){
        front = current;
        rear = current;
    }
    else{
        rear->next = current;
        rear = current;
    }
    cout << num << " enqueued" << endl;
}

void dequeue(){
    Node *newNode;

    if (front == NULL){
        cout << "Queue Underflow" << endl;
    }
    else {
        newNode = front;
        front = front->next;
        newNode->next = NULL;
        cout << newNode->number << " dequeued" << endl;
        free(newNode);
    }
}

void display(Node * n){
    if (n == NULL){
        cout << "Queue Empty" << endl;
    }
    else{
        cout << "Queue elements: ";
        while (n != NULL){
            cout << n->number << " ";
            n = n->next;
        }
        cout << endl;
    }
}

int main(){

    cout << "Subhendu Dash\n20BEE1004" << endl;

    enqueue(12);
    enqueue(13);
    enqueue(14);
    enqueue(15);
    display(front);
    dequeue();
    display(front);
    dequeue();
    dequeue();
    display(front);
    enqueue(18);
    display(front);

    return 0;
}