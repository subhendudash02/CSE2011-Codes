#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
    int coeff;
    int pow;
    Node* next;
};

Node *head1, *tail1 = NULL;
Node *head2, *tail2 = NULL;

void insert1(int c, int p) {
    Node* current = new Node();
    current->coeff = c;
    current->pow = p;
    current->next = NULL;
    
    if (head1 == NULL){
        head1 = current;
        tail1 = current;
    }
    else{
        tail1->next = current;
        tail1 = current;
    }
}

void insert2(int c, int p){
    Node* current = new Node();
    current->coeff = c;
    current->pow = p;
    current->next = NULL;
    
    if (head2 == NULL){
        head2 = current;
        tail2 = current;
    }
    else{
        tail2->next = current;
        tail2 = current;
    }
}

void print(Node *n){
    while (n != NULL){
        cout << n->coeff << "x^" << n->pow << " + ";
        n = n->next;
    }
    cout << endl;
}

void add(){
    while (head1 != 0){
        while (head2 != 0){
            if (head1->pow == head2->pow){
                cout << (head1->coeff + head2->coeff) << "x^" << head1->pow << "+ ";
                head1 = head1->next;
                head2 = head2->next;
            }
            else if (head1->pow < head2->pow){
                cout << head2->coeff << "x^" << head2->pow << " + ";
                head2 = head2->next;
            }
            else if (head1->pow > head2->pow){
                cout << head1->coeff << "x^" << head1->pow << " + ";
                head1 = head1->next;
            }
        }
    }
}

int main(){

    cout << "Name: Subhendu Dash\nName: 20BEE1004" << endl;

    int terms1;
    cout << "Enter the number of terms in polynomial-1: ";
    cin >> terms1;

    for (int i = 0; i < terms1; i++){
        int coeff, pow;
        cin >> coeff >> pow;
        insert1(coeff, pow);
    }

    int terms2;
    cout << "Enter the number of terms in polynomial-2: ";
    cin >> terms2;

    for (int i = 0; i < terms2; i++){
        int coeff, pow;
        cin >> coeff >> pow;
        insert2(coeff, pow);
    }

    cout << "Polynomial-1: " << endl;
    print(head1);
    cout << "Polynomial-2: " << endl;
    print(head2);

    cout << "On addition: " << endl;
    add();

    return 0;
}