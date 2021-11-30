#include <iostream>

using namespace std;

class Node{
public:
    int data;
    int index;
    Node* next = NULL;
    Node* prev = NULL;
    Node(int x){
        data = x;
    }
};

void insert(Node* &head, int data){
    int index;
    Node* n = new Node(data);
    if(head == NULL){
        head = n;
        head->prev = NULL;
        head->index = 1;
    }
    else{
        Node*temp = head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = n;
        n->prev = temp;
        n->index = n->prev->index + 1;
    }
}

void display(Node* head, Node*&man){
    cout << "Linked list is: ";
    Node* temp = head;
    cout << endl;
    while(temp != NULL){
        if(temp->data == 1){
            cout << "Man ";
            man = temp;
        }
        else if(temp->data == 2){
            cout<<"Iron_box ";
        }
        else if(temp->data == 3){
            cout << "Table ";
        }
        else if(temp->data == 4){
            cout << "Clothes ";
        }
        else{
            cout << "0 ";
        }
        temp = temp->next;
    }  
    cout << endl;
}

void IndexCheck(Node* temp){
    if(temp->data==2){
        cout<<"Iron box at index: "<< temp->index << endl;
    }
    else if(temp->data==3){
        cout<<"Iron table at index: "<< temp->index << endl;
    }
    else if(temp->data==4){
        cout<<"Clothes at index: "<< temp->index << endl;
    }
}

void replace(Node*&head,int data){
    int i;
    cin >> i;
    Node* temp = head;
    while(--i != 0){
        temp = temp->next;
    }
    temp->data = data;

}

void traverse(Node* man){
    Node* temp = man;
    cout<<"Forward direction." << endl;
    while(temp->next != NULL){
        IndexCheck(temp);
        temp = temp->next;
    }
    IndexCheck(temp);
    cout<<"Backward direction." << endl;
    temp = man;
    while(temp->prev!= NULL){
        IndexCheck(temp);
        temp = temp->prev;
    }
    IndexCheck(temp);

}

int main(){

    cout << "Name: Subhendu Dash\nName: 20BEE1004" << endl;

    Node* head = NULL;
    Node* man = NULL;
    cout<<"Enter the number of nodes: ";
    int num,i=0;
    cin>>num;
    while(i++<num){
        insert(head,0);
    }

    cout<<"Enter the index of man: ";
    replace(head,1);

    cout<<"Enter the index of iron box: ";
    replace(head,2);

    cout<<"Enter the index of iron table: ";
    replace(head,3);

    cout<<"Enter the index of clothes: ";
    replace(head,4);

    display(head,man);
    traverse(man);
    
    return 0;
}