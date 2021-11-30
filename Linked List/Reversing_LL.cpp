#include <iostream>
#include <stack>

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

Node * reverse(Node * head) {
    Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while (current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

void print(Node * n){
    while (n != NULL){
        cout << "Data: " << n->number << endl;
        n = n->next;
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

    cout << "Data in the linked list are: " << endl;
    print(head);

    cout << "\n";

    head = reverse(head);
    cout << "The linked list in reverse form is: " << endl;
    print(head);

    return 0;
}