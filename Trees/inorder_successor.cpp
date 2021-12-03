#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int num){
    Node *k = new Node();
    k->data = num;
    k->left = NULL;
    k->right = NULL;

    return k;
}

void inorder(Node *p){
    if (p != NULL){
        inorder(p->left);
        if (p->data != 0){
            cout << p->data << " ";
        }
        inorder(p->right);
    }
    else{
        return;
    }
}

Node *insert(Node *p, int num){
    if (p == NULL){
        return newNode(num);
    }
    if (num < p->data){
        p->left = insert(p->left, num);
    }
    else{
        p->right = insert(p->right, num);
    }
    return p;
}

Node *leftMost(Node *p){
    while (p != NULL && p->left != NULL){
        p = p->left;
    }
    return p;
}

void inorderSuccessor(Node *p, Node* &z, int num){
    if (p == NULL){
        z = NULL;
        return;
    }

    if (p->data == num){
        if (p->right){
            z = leftMost(p->right);
        }
    }
    else if (num < p->data){
        z = p;
        inorderSuccessor(p->left, z, num);
    }
    else {
        inorderSuccessor(p->right, z, num);
    }
}

int main() {

    cout << "Name: Subhendu Dash\nReg No: 20BEE1004" << endl;

    int arr[9] = {15, 10, 20, 8, 25, 18, 12, 19, 30};

    Node *node = NULL;
    node = insert(node, arr[0]);

    for (int i = 1; i < 9; i++){
        insert(node, arr[i]);
    }

    cout << "Existing tree: ";
    inorder(node);
    cout << '\n';

    cout << "Enter the number to find inorder successor: ";
    int k;
    cin >> k;

    
    Node *node2 = NULL;

    inorderSuccessor(node, node2, k);

    if (node2 != NULL){
        cout << "Successor of " << k << ": " << node2->data << endl;
    }

    else {
        cout << "No successor for " << k << endl;
    }

    return 0;
}