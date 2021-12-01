#include<iostream>
using namespace std;

class queue{
private:
    int front=-1;
    int rear=-1;
    int size;
    int* arr;
public:
    queue(int size1){
        size = size1;
        arr = new int[size];
    }
    void enqueue(int i);
    int dequeue();
    void display();
};

void queue::display(){
    for (int i=front; i<=rear; i++){
        cout<<arr[i]<<" ";
    }
}
void queue::enqueue(int i){
    if(front==-1 && rear==-1){
        front++;
        rear++;
        arr[rear] = i;
        
    }
    else if(rear==size-1){
        cout<<"Queue Overflow"<<endl;
    }
    else{
        rear++;
        arr[rear] = i;
        
    }
}

int queue::dequeue(){
    if(front==-1 && rear==-1){
        return -1;
    }
    else if(front==rear){
        int k = arr[front];
        front=-1;
        rear=-1;
        return k;
    }
    else{
        int k = arr[front];
        front++;
        return k;
    }
}
class stack{
private:
    int t=-1;
    int* arr;
    int size;
public:
    stack(int size1){
        size = size1;
        arr = new int[size];
    }
    void push(int i);
    int pop();
    void display();
};
void stack::display(){
    for (int i = t; i>-1; i--){
        cout<<endl<<arr[i];
    }
    
    cout<<endl;
}
void stack::push(int i){
        t++;
        arr[t]=i;
    }
int stack::pop(){
    if (t==-1){
        return -1;
    }
    else{
        int k = arr[t];
        t--;
        return k;
    }

}

int main(){
    int n = 5;
    cout << "Name: Subhendu Dash\nReg No: 20BEE1004" << endl;
    
    queue q1(n);
    queue q2(n*n);
    stack s(50);
    cout<<"Enter 5 unsorted elements."<<endl;
    for (int i = 0; i < n; i++){
        int k;
        cin>>k;
        q1.enqueue(k);
        q2.enqueue(k);
    }
    int k,j;
    while(1){
        k = q2.dequeue();
        
        if (k==-1){break;}
        j = s.pop(); 
        
        while(k>j && j!=-1){
            q2.enqueue(j);
        
            j = s.pop();
        }
        if(k<j && j!=-1){
            s.push(j);
            
            
        }
        s.push(k);
        
    }
    while(1){
        j = s.pop();
        if (j==-1){break;}
        q2.enqueue(j);
    }
    
    q2.display();
    return 0;
}