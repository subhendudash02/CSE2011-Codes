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

Node *minVal(Node *p){
    Node *t = new Node();

    while (t->left != NULL && t){
        t = t->left;
    }
    return t;
}

Node *Delete(Node *p, int num){
    if (p == NULL){
        return p;
    }
    if (num < p->data){
        p->left = Delete(p->left, num);
    }
    else if (num > p->data){
        p->right = Delete(p->right, num);
    }
    else{
        if (p->left == NULL && p->right == NULL){
            return NULL;
        }
        else if (p->left == NULL){
            Node *t = p->right;
            free(p);
            return t;
        }
        else if (p->right == NULL){
            Node *t = p->left;
            free(p);
            return t;
        }

        Node *t = minVal(p->right);
        p->data = t->data;
        p->right = Delete(p->right, t->data);
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

    cout << "Enter the number to be delete: ";
    int k;
    cin >> k;

    node = Delete(node, k);

    cout << "Tree after deleting " << k << ": ";
    inorder(node);

    return 0;
}