#include <iostream>

using namespace std;

class Node {
    public:
    int row;
    int col;
    int val;
    Node* next;
};

void add(Node* a, Node* b){
    while (a != NULL && b != NULL){

        if ((a->row == b->row) && (a->col == b->col)){
            cout << a->row << " " << a-> col << " " << (a->val + b->val) << endl;
        }    
        else{
            cout << a->row << " " << a-> col << " " << a->val << endl;
            cout << b->row << " " << b-> col << " " << b->val << endl;
        }
        b = b->next;
        a = a->next;
    }
}

void transpose(Node* a){
    while (a != NULL){
        int temp = a->row;
        a->row = a->col;
        a->col = temp;
        cout << a->row << " " << a->col << " " << a->val << endl;
        a = a->next;
    }
}

void bubbleSort(Node *start)
{
    int swapped, i;
    Node *ptr1;
    Node *lptr = NULL;
  
    /* Checking for empty list */
    if (start == NULL)
        return;
  
    do
    {
        swapped = 0;
        ptr1 = start;
  
        while (ptr1->next != lptr)
        {
            if ((ptr1->row > ptr1->next->row) && (ptr1->col > ptr1->next->col))
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}
  
/* function to swap data of two nodes a and b*/
void swap(Node *a, Node *b)
{
    int temp = a->row;
    a->row = b->row;
    b->row = temp;

    temp = a->col;
    a->col = b->col;
    b->col = temp;

    temp = a->val;
    a->val = b->val;
    b->val = temp;
}

void show(Node* a){
    while (a != NULL){
        cout << a->row << " " << a->col << " " << a->val << endl;
        a = a->next;
    }
}

int main(){

    Node* f1 = NULL;
    Node* f2 = NULL;
    Node* f3 = NULL;

    Node* k1 = NULL;
    Node* k2 = NULL;
    Node* k3 = NULL;

    f1 = new Node();
    f2 = new Node();
    f3 = new Node();

    k1 = new Node();
    k2 = new Node();
    k3 = new Node();

    f1->row = 1;
    f1->col = 2;
    f1->val = 10;
    f1->next = f2;

    f2->row = 1;
    f2->col = 4;
    f2->val = 12;
    f2->next = f3;

    f3->row = 3;
    f3->col = 3;
    f3->val = 5;
    f3->next = NULL;

    k1->row = 1;
    k1->col = 3;
    k1->val = 8;
    k1->next = k2;

    k2->row = 2;
    k2->col = 4;
    k2->val = 23;
    k2->next = k3;

    k3->row = 3;
    k3->col = 3;
    k3->val = 9;
    k3->next = NULL;

    bubbleSort(f1);
    bubbleSort(k1);
    show(k1);

    //add(f1, k1);
    /*cout << endl;
    show(f1);
    cout << endl;
    transpose(f1);
    cout << endl;
    show(f1);*/

    return 0;
}