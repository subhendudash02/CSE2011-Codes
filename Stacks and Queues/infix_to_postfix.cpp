#include <iostream>
#define maxLength 100

using namespace std;

class Stack {
    private:
    int top;
    char array[maxLength];

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
        }
    }

    char pop(){
        if (isEmpty() == 1){
            return '@';
        }
        else{
            return array[top--];
        }
    }

    char peek(){
        if (isEmpty() == 0){
            return array[top];
        }
        else{
            return '@';
        }
    }
};

int prcd(char k){
    if (k == '*' || k == '/'){
        return 3;
    }
    else if (k == '+' || k == '-'){
        return 2;
    }
    else {
        return 1;
    }
}

int main(){

    cout << "Name: Subhendu Dash\nReg No: 20BEE1004" << endl;

    string exp = "6 * ( 5 + ( 2 + 3 ) * 8 + 3)";
    cout << "Infix: " << exp << endl;
    cout << "Postfix: "; 

    Stack st;

    for (int i = 0; i < exp.length(); i++){
        if ((exp[i] >= '0' && exp[i] <= '9') || (exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z')){
            cout << exp[i] << " ";
        }

        else if (exp[i] == '('){
            st.push(exp[i]);
        }

        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/'){
            if (prcd(exp[i]) <= prcd(st.peek())){
                cout << st.pop() << " ";
                cout << exp[i] << " ";
            }
            else {
                st.push(exp[i]);
            }
        }

        else if (exp[i] == ')'){
            while (st.peek() != '('){
                cout << st.pop() << " ";
            }
            st.pop();
        }
    }

    while (st.isEmpty() != 1){
        cout << st.pop() << " ";
    }

    return 0;
}