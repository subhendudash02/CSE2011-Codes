#include <iostream>

using namespace std;

int sum2darr(int array[][4], int a, int b){
    int sum = 0;
    for (int i = 0; i < a; i++){
        for (int j = 0; j < b; j++){
            sum += array[i][j];
        }
    }
    return sum;
}

int main(){

    // To sum the number of rows and columns in a 2d array

    cout << "Name: Subhendu Dash" << endl;
    cout << "Reg-No: 20BEE1004" << endl;
    cout << " " << endl;

    int arr[5][4] = {
        {19, 41, 29, 34},
        {30, 27, 42, 69},
        {34, 56, 12, 23},
        {41, 55, 23, 90}
    };

    cout << "Sum of 2d array: " << sum2darr(arr, 5, 4);

    return 0;
}