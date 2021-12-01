#include <iostream>
#define maxLength 7

using namespace std;

class circular_queue{
    private:
    int front = -1;
    int rear = -1;
    int queue[maxLength];

    public:
    int enqueue(int ele){
        if (front == 0 && (rear == (maxLength - 1)) || (rear == (front - 1) % (maxLength - 1))){
            return -999;
        }
        else if (front != 0 && rear == (maxLength - 1)) {
            rear = 0;
            queue[rear] = ele;
            return 999;
        }
        else if (front == -1){
            front = 0;
            rear = 0;
            queue[rear] = ele;
        }
        else{
            rear += 1;
            queue[rear] = ele;
        }
        return 1;
    }

    int dequeue(){
        if (front == -1){
            return -999;
        }

        int p = queue[front];

        if (front == (maxLength - 1)){
            front = 0;
        }
        else if (rear == front){
            front = -1;
            rear = -1;
        }
        else {
            front += 1;
        }

        return p;
        
    }

    void display(){
        if (front == -1){
            cout << "Queue Empty." << endl;

        }
        if (rear < front){
            for (int i = front; i < maxLength; i++){
                cout << queue[i] << " ";
            }
            for (int i = 0; i <= rear; i++){
                cout << queue[i] << " ";
            }
            cout << endl;
        }
        else {
            for (int i = front; i <= rear; i++){
                cout << queue[i] << " ";
            }
            cout << endl;
        }
    }

    int frontSpace(){
        if (front != 0 && rear == (maxLength - 1)){
            return 1;
        }
        else {
            return 0;
        }
    }
};

int main(){

    cout << "Name: Subhendu Dash\nReg No: 20BEE1004" << endl;

    cout << "Total " << maxLength << " E-pass can be generated at a particular moment of time." << endl;
    cout << "Press 1 for registering the E-pass.\nPress 2 for deleting the E-pass application.\n";

    int ask;
    int token_no = 1;
    circular_queue q;

    while (true) {
        cout << "Enter 1 or 2: ";
        cin >> ask;

        if (ask == 1){
            int p = q.frontSpace();
            if (p == 0){
                int p = q.enqueue(token_no);
                if (p == -999){
                    cout << "All tokens registered." << endl;
                }
                else{
                    cout << "Token " << token_no << " registered." << endl;
                    token_no++;
                }
            }
            else if (p == 1){
                token_no = 1;
                q.enqueue(token_no);
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