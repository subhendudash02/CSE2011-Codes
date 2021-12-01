#include <iostream>
#define maxLength 10

using namespace std;

class circular_queue{
    private:
    int front = -1;
    int rear = -1;
    int queue[maxLength];

    public:
    void enqueue(int ele){
        int c = 0;
        if (front == 0 && (rear == (maxLength - 1)) || (rear == (front - 1) % (maxLength - 1))){
            cout << "No more orders allowed. Out of orders." << endl;
            c = 0;
        }
        else if (front != 0 && rear == (maxLength - 1)) {
            rear = 0;
            queue[rear] = ele;
            c = 1;
        }
        else if (front == -1){
            front = 0;
            rear = 0;
            queue[rear] = ele;
            c = 1;
        }
        else{
            rear += 1;
            queue[rear] = ele;
            c = 1;
        }

        if (c == 1){
            cout << "Order " << ele << " placed" << endl;
        }
    }

    int dequeue(){
        if (front == -1){
            cout << "No more orders. Pizza delivered." << endl;
            return 0;
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

        cout << "Pizza delivered to order number " << p << endl;
        return 0;
        
    }

    void display(){
        if (front == -1){
            cout << "No orders left" << endl;

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

};

int main(){

    cout << "Name: Subhendu Dash\nReg No: 20BEE1004" << endl;
    
    circular_queue cq;

    cout << "Total " << maxLength << " orders can be made.\n";

    cq.dequeue();
    for (int i = 1; i <= 5; i++){
        // Placing 5 orders one at a time
        cq.enqueue(i);
    }
    cq.display();
    cq.dequeue();
    cq.display();
    cq.dequeue();
    cq.dequeue();
    cq.display();

    return 0;
}