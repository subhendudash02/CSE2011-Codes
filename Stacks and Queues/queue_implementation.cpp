#include <iostream>
#define maxLength 100

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

    void enqueue(int ele){
        if (maxLength == rear){
            cout << "Queue Overflow" << endl;
        }
        else{
            queue[rear] = ele;
            rear++;
        }
    }

    void dequeue(){
        if (isEmpty() == 1){
            cout << "Queue Underflow" << endl;
        }
        else{
            for (int i = 0; i < (rear - 1); i++){
                queue[i] = queue[i + 1];
            }
            rear--;
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

    queue q;
    q.dequeue();
    q.enqueue(4);
    q.enqueue(8);
    q.enqueue(12);
    q.display();
    q.dequeue();
    q.display();
    q.enqueue(16);
    q.display();
    q.dequeue();
    q.display();

    return 0;
}