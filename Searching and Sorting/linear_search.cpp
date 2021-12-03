#include <iostream>

using namespace std;

int linear_search(int arr[], int len, int ele){

    for (int i = 0; i < len; i++){
        if (arr[i] == ele){
            return i;
        }
    }
    return -999;
}

int main(){
    cout << "Name: Subhendu Dash" << endl;
    cout << "Reg-No: 20BEE1004" << endl;
    cout << " " << endl;

    int arr[10];
    cout << "Enter 10 elements: " << endl;

    for (int i = 0; i < 10; i++){
        cin >> arr[i];
    }

    int element;
    cout << "Enter the element to be found: ";
    cin >> element;

    int findIt = linear_search(arr, 10, element);

    if (findIt == -999){
        cout << "Not found!" << endl;
    }
    else{
        cout << "Found at index " << findIt;
    }

    return 0;
}