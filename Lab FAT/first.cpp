#include <iostream>
#define LENGTH 7

using namespace std;

class MinDeque {
    private:
    int arr[LENGTH];
    int front;
    int rear;
    int len;

    public:
    MinDeque(int len) {
        front = -1;
        rear = 0;
        this->len = len;
    }

    bool isEmpty() {
        if (front == -1) {
            return true;
        }
        else {
            return false;
        }
    }

    bool isFull() {
        if ((rear == len - 1 && front == 0) || front == rear + 1) {
            return true;
        }
        else {
            return false;
        }
    }

    void add_first(int key) {
        if (isFull()) {
            cout << "Deque Overflow" << endl;
            return;
        }

        if (front == -1) {
            front = 0;
            rear = 0;
        }

        else if (front == 0) {
            front = len - 1;
        }

        else {
            front = front - 1;
        }

        arr[front] = key;
    }

    void add_last(int key) {
        if (isFull()) {
            cout << "Deque Overflow" << endl;
            return;
        }

        if (front == -1) {
            front = 0;
            rear = 0;
        }

        else if (rear == len - 1) {
            rear = 0;
        }

        else {
            rear = rear + 1;
        }

        arr[rear] = key;
    }

    void remove_first() {
        if (isEmpty()) {
            cout << "Deque Underflow\n" << endl;
            return;
        }

        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else if (front == len - 1) {
            front = 0;
        }
        else {
            front = front + 1;
        }
    }

    void remove_last() {
        if (isEmpty()) {
            cout << "Deque Underflow" << endl;
            return;
        }

        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else if (rear == 0) {
            rear = len - 1;
        }
        else {
            rear = rear - 1;
        }
    }

    int size() {
        return len;
    }

    int minimum() {
        return arr[front];
    }
};

int main() {
    cout << "Name: Subhendu Dash\nReg No: 20BEE1004\nDate: 10 December 2021\nCSE2011 Lab FAT Examinations" << endl;
    cout << endl;

    MinDeque d(5);

    d.add_first(3);
    d.add_last(5);
    d.add_last(7);
    d.add_last(9);
    d.add_first(1);
    d.remove_last();
    d.remove_first();


    cout << "Minimum element is: " << d.minimum() << endl;
    cout << "Size: " << d.size() << endl;
}