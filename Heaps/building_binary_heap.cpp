#include <iostream>

using namespace std;

void heapify(int arr[], int size, int node) {
    int max = node;
    int left = node * 2 + 1;
    int right = node * 2 + 2;

    if (left < size and arr[left] > arr[max]) {
        max = left;
    }
    if (right < size and arr[right] > arr[max]) {
        max = right;
    }
    if (max != node) {
        int temp = arr[node];
        arr[node] = arr[max];
        arr[max] = temp;

        heapify(arr, size, max);
    }
}

int main() {
    cout << "Name: Subhendu Dash\nReg No: 20BEE1004" << endl;
    int array[] = {10, 2, 1, 5, 3, 8, 11, 24, 7};
    int size = sizeof(array) / sizeof(array[0]);


    for (int i = (size / 2) - 1; i >= 0; i--) {
        heapify(array, size, i);
    }

    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }

    return 0;
}