#include <iostream>

using namespace std;

void heapify(int arr[], int size, int node) {
    int min = node;
    int left = node * 2 + 1;
    int right = node * 2 + 2;

    if (left < size and arr[left] < arr[node]) {
        min = left;
    }
    if (right < size and arr[right] < arr[min]) {
        min = right;
    }
    if (min != node) {
        int temp = arr[node];
        arr[node] = arr[min];
        arr[min] = temp;

        heapify(arr, size, min);
    }
}

int main() {
    cout << "Name: Subhendu Dash\nReg No: 20BEE1004" << endl;

    int array[] = {20, 18, 10, 12, 9, 9, 3, 5, 6, 8};
    int size = sizeof(array) / sizeof(array[0]);

    int i = (size - 2) / 2;
        while (i >= 0) {
            heapify(array, size, i--);
        }
        
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }

    return 0;
}