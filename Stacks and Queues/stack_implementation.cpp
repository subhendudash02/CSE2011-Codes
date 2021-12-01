#include <iostream>
#define maxLength 100

using namespace std;

class Stack {
    private:
    int top;
    int array[maxLength];

    public:

    Stack() {
        top = -1;
    }

    int isEmpty(){
        if (top >= 0){
            return 0;
        }
        else{
            return 1;
        }
    }

    void push(int ele){
        if (top >= (maxLength - 1)){
            cout << "Stack Overflow" << endl;
        }
        else{
            top++;
            array[top] = ele;
            cout << "Element " << ele << " pushed." << endl;
        }
    }

    void pop(){
        if (isEmpty() == 1){
            cout << "Stack Underflow" << endl;
        }
        else{
            cout << "Popped element is " << array[top] << endl;
            top--;
        }
    }

    void peek(){
        if (isEmpty() == 0){
            cout << "Topmost element: " << array[top] << endl;
        }
        else{
            cout << "Stack empty." << endl;
        }
    }

    void show(){
        for (int i = 0; i < (top + 1); i++){
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int main(){

    cout << "Name: Subhendu Dash\nReg No: 20BEE1004" << endl;

    Stack st;

    st.pop();
    st.push(3);
    st.push(4);
    st.push(5);
    st.show();
    st.peek();
    st.pop();
    st.show();
    st.push(8);
    st.show();
    st.peek();

    return 0;
}