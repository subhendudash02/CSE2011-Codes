#include <iostream>
#include <stack>

using namespace std;

int main(){

    cout << "Name: Subhendu Dash\nReg No: 20BEE1004" << endl;

    string exp = "[]{}{[()()]()}";
    cout << "Expression: " << exp << endl;

    stack<int> st;
    int k = 1;

    for (int i = 0; i < exp.length(); i++){
        if (exp[i] == 40 || exp[i] == 91 || exp[i] == 123){
            st.push(exp[i]);
        }
        else if (exp[i] == 41){
            if (st.top() == 40){
                st.pop();
            }
            else{
                cout << "Unbalanced" << endl;
                k = 0;
                break;
            }
        }
        else if (exp[i] == 93){
            if (st.top() == 91){
                st.pop();
            }
            else{
                cout << "Unbalanced" << endl;
                k = 0;
                break;
            }
        }
        else if (exp[i] == 125){
            if (st.top() == 123){
                st.pop();
            }
            else{
                cout << "Unbalanced" << endl;
                k = 0;
                break;
            }
        }
    }

    if (k == 1){
        cout << "Balanced" << endl;
    }

    return 0;
}