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

void heapSort(int arr[], int size) {
    cout << "Name: Subhendu Dash\nReg No: 20BEE1004" << endl;
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }

    for (int i = size - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int main() {

    int array[] = {10, 2, 1, 5, 3, 8, 11, 24, 7};
    int size = sizeof(array) / sizeof(array[0]);

    heapSort(array, size);

    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }

    return 0;
}