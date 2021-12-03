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

    cout << "Enter the number to be inserted: ";
    int k;
    cin >> k;

    insert(node, k);

    cout << "Tree after inserting " << k << ": ";
    inorder(node);

    return 0;
}