#include <iostream>
#define maxLength 7

using namespace std;

class queue {
    private:
    int front = 0;
    int rear = 0;
    int queue[maxLength];

    public:
    int isEmpty(){
        if (front == rear){
            return 1;
        }
        return 0;
    }

    int enqueue(int ele){
        if (maxLength == rear){
            return -999;
        }
        else{
            queue[rear] = ele;
            rear++;
            return 1;
        }
    }

    int dequeue(){
        if (isEmpty() == 1){
            return -999;
        }
        else{
            int q = queue[front];
            for (int i = 0; i < (rear - 1); i++){
                queue[i] = queue[i + 1];
            }
            rear--;
            return q;
        }
    }

    void display(){
        if (isEmpty() == 1){
            cout << "Queue Empty." << endl;
        }
        else {
            for (int i = 0; i < rear; i++){
                cout << queue[i] << " <- ";
            }
            cout << endl;
        }
    }
};

int main(){

    cout << "Name: Subhendu Dash\nReg No: 20BEE1004" << endl;

    cout << "Total " << maxLength << " E-pass can be generated at a particular moment of time." << endl;
    cout << "Press 1 for registering the E-pass.\nPress 2 for deleting the E-pass application.\n";

    int ask;
    int token_no = 1;
    queue q;

    while (true) {
        cout << "Enter 1 or 2: ";
        cin >> ask;

        if (ask == 1){
            int p = q.enqueue(token_no);
            if (p == -999){
                cout << "All tokens registered." << endl;
            }
            else{
                cout << "Token " << token_no << " registered." << endl;
                token_no++;
            }
        }
        else if (ask == 2){
            int p = q.dequeue();
            if (p == -999){
                cout << "No tokens registered yet." << endl;
            }
            else{
                cout << "Token " << p << " deleted." << endl;
            }
        }
        else {
            cout << -1 << endl;
            break;
        }
        q.display();
    }

    return 0;
}