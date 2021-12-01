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
        }
    }

    int pop(){
        if (isEmpty() == 1){
            cout << "Stack Underflow" << endl;
        }
        else{
            return array[top--];
        }
    }

    void peek(){
        if (isEmpty() == 0){
            cout << "Final Answer: " << array[top] << endl;
        }
        else{
            cout << "Stack empty." << endl;
        }
    }
};

int main(){

    cout << "Name: Subhendu Dash\nReg No: 20BEE1004" << endl;

    Stack eval;

    string exp = "6 5 2 3 + 8 * + 3 + *";
    
    for (int i = 0; i < exp.length(); i++){
        if (exp[i] >= 48 && exp[i] <= 57){
            int intVal = 9 - (57 - (int)exp[i]);
            eval.push(intVal);
        }
        else if (exp[i] == 42 || exp[i] == 43 || exp[i] == 45 || exp[i] == 47){
            int a = eval.pop();
            int b = eval.pop();
            if (exp[i] == 42){
                int f = a * b;
                eval.push(f);
            }
            else if (exp[i] == 43){
                int f = a + b;
                eval.push(f);
            }
            else if (exp[i] == 45){
                int f = b - a;
                eval.push(f);
            }
            else if (exp[i] == 47){
                int f = a / b;
                eval.push(f);
            }
        }
    }

    cout << "Postfix Expression: " << exp << endl;
    eval.peek();

    return 0;
}