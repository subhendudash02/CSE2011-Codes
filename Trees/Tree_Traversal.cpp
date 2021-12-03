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

void preorder(Node *p){
    if (p != NULL){
        cout << p->data << " ";
        preorder(p->left);
        preorder(p->right);
    }
    else {
        return;
    }
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

void postorder(Node *p){
    if (p != NULL){
        preorder(p->left);
        preorder(p->right);
        cout << p->data << " ";
    }
    else {
        return;
    }
}

int main(){

    cout << "Name: Subhendu Dash\nReg No: 20BEE1004" << endl;
    
    Node *node = NULL;

    int count, k;
    cout << "Enter the number of nodes in the tree: ";
    cin >> count;

    cin >> k;
    node = insert(node, k);

    for (int i = 1; i < count; i++){
        cin >> k;
        insert(node, k);
    }

    cout << "Preorder: ";
    preorder(node);
    cout << '\n';
    cout << "Inorder: ";
    inorder(node);
    cout << '\n';
    cout << "Postorder: ";
    postorder(node);

    return 0;
}
