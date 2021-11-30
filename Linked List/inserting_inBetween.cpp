#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
    int number;
    Node* next;
};

Node *head, *tail = NULL;

void insert(int num) {
    Node* current = new Node();
    current->number = num;
    current->next = NULL;
    
    if (head == NULL){
        head = current;
        tail = current;
    }
    else{
        tail->next = current;
        tail = current;
    }
}

void print(Node * n){
    while (n != NULL){
        cout << "Data: " << n->number << endl;
        n = n->next;
    }
}

void insert_between(int data, int index, Node *LL){
    int count = 0;
    Node *newNode = new Node();
    newNode->number = data;
    newNode->next = NULL;
    while (LL != NULL){
        count++;
        if (count == (index - 1)){
            newNode->next = LL->next;
            LL->next = newNode;
        }
        LL = LL->next;
    }
}

int main(){

    cout << "Subhendu Dash\n20BEE1004" << endl;

    int tot;
    cout <<  "Input the number of nodes: ";
    cin >> tot;

    for (int i = 1; i <= tot; i++){
        int n;
        cout << "Input data for node " << i << ": ";
        cin >> n;
        insert(n);
    } 

    int data, pos;
    cout << "Enter the number to be inserted: ";
    cin >> data;
    cout << "Enter the position to insert new node(index starts from 1): ";
    cin >> pos;

    cout << "Linked list before inserting: " << endl;
    print(head);

    cout << "Linked list after inserting: " << endl;
    insert_between(data, pos, head);
    print(head);

    return 0;
}