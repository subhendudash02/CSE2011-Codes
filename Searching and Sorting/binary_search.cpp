#include <iostream>

using namespace std;

int binary_search(int arr[], int ele , int low, int high){
    
    while (low <= high){
        int mid = low + (high - low) / 2;

        if (ele == arr[mid]){
            return mid;
        }
        else if (arr[mid] > ele){
            high = mid - 1;
        }
        else{
            low = mid + 1;
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

    int findIt = binary_search(arr, element, 0, 9);

    if (findIt == -999){
        cout << "Not Found!";
    }    

    else{
        cout << "Element found at index: " << findIt;
    }

    return 0;
}