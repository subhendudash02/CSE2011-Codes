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

Node *minVal(Node *p){
    Node *t = new Node();

    while (t->left != NULL && t){
        t = t->left;
    }
    return t;
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

void Search(Node *p, int num){
    if (p == NULL){
        cout << "Not found!" << endl;
    }
    if (num < p->data){
        return Search(p->left, num);
    }
    else if (num > p->data){
        return Search(p->right, num);
    }
    else {
        cout << num << " found" << endl;
    }
}

int main(){

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

    int num;
    cout << "Enter the number you want to enter: ";
    cin >> num;
    insert(node, num);    

    // preorder(node);
    // cout << endl;
    inorder(node);
    cout << endl;
    // postorder(node);
    // cout << endl;

    node = Delete(node, 20);
    inorder(node);

    Search(node, 16);

    return 0;
}