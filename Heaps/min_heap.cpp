#include <iostream>
#include <cmath>

using namespace std;

void checkMinHeap(int arr[], int len) {
    for (int i = 0; i < len / 2; i++) {
        int parent = i;
        int left_child = 2 * parent + 1;
        int right_child = 2 * parent + 2;
        if (arr[parent] > left_child && arr[parent] > right_child) {
            cout << "Not a min-heap" << endl;
            return;
        }
    }
    cout << "It's a min-heap" <<endl;
}

int main() {

    cout << "Name: Subhendu Dash\nReg No: 20BEE1004" << endl;

    int len = 0;
    cout << "Enter the length: ";
    cin >> len;

    int arr[len];

    for (int i = 0; i < len; i++) {
        cout << "Enter " << i << " element: ";
        cin >> arr[i];
    }

    checkMinHeap(arr, len);

    return 0;
}