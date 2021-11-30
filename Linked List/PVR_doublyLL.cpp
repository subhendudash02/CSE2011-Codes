#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node *prev;
};

Node *head = NULL;

void insert(int no){
    Node *temp = new Node();
    temp->data = no;
    temp->prev = NULL;
    temp->next = head;

    if (head != NULL)
        head->prev = temp;
        head = temp;
}

void del(int p){
    while (head != NULL){
        if (head->data == p){
            head->next->prev = head->prev;
            head->prev->next = head->next;
        }
        head = head->next;
    }
}

void print(){
    cout << "Seats filled till now: " << endl;
    while (head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
    cout << "Remaining seats are free." << endl;
}


int main(){

    cout << "Name: Subhendu Dash\nName: 20BEE1004" << endl;

    int num, row;
    cout << "Enter the number of rows: ";
    cin >> row;
    cout << "Enter the number of seats per column: ";
    cin >> num;

    cout << "Total seats: " << num * row << endl;

    int decide = 1;

    while (decide == 1 || decide  == 2 || decide == 3){
        cout << "Enter 1 for booking, 2 for cancelling, 3 for showing the available seats: ";
        cin >> decide;

        if (decide == 1){
            int seat_no;
            cout << "Enter the seat number: ";
            cin >> seat_no;

            if (seat_no <= (num * row)){
                insert(seat_no);
                cout << "Seat number " << seat_no << " booked." << endl;
            }
            else{
                cout << "Invalid seat." << endl;
            }
        }

        else if (decide == 2){
            int seat_no;
            cout << "Enter the seat number: ";
            cin >> seat_no;

            if (seat_no <= (num * row)){
                del(seat_no);
                cout << "Seat number " << seat_no << " deleted." << endl;
            }
            else{
                cout << "Invalid seat." << endl;
            }
        }

        else if (decide == 3){
            print();
        }
        else{
            cout << "Program terminated." << endl;
        }
    }

    return 0;
}