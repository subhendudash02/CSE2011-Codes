#include <iostream>

using namespace std;

void swapIt(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void print(int arr[], int n){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

void bubble_sort(int arr[], int length){
    for (int i = 0; i < length - 1; i++){
        for (int j = 0; j < length - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                swapIt(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void insertion_sort(int arr[], int length){
    int key;
    for (int i = 0; i < length; i++){
        key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j --;
        }
        arr[j + 1] = key;
    }
}

void selection_sort(int arr[], int length){

    int minimum;

    for (int i = 0; i < length; i++){
        minimum = i;

        for (int j = i + 1; j < length; j++){
            if (arr[j] < arr[minimum]){
                minimum = j;
            }
        }
        swapIt(&arr[i], &arr[minimum]);
    }

}

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

    int count;

    cout << "Enter the number of stocks: ";
    cin >> count;

    int array[count];

    for (int i = 0; i < count; i++){
        cin >> array[i];
    }

    cout << "Unsorted prices: " << endl;
    print(array, count);
    cout << endl;

    int decide = 0;
    cout << "Press 1 for Bubble sort, 2 for insertion sort, 3 for selection sort: ";
    cin >> decide;

    if (decide == 1){
        bubble_sort(array, count);
    }
    else if (decide == 2){
        insertion_sort(array, count);
    }
    else if(decide == 3){
        selection_sort(array, count);
    }
    else{
        cout << "Invalid choice!!!" << endl;
        exit(0);
    }

    cout << "Sorted prices: " << endl;
    print(array, count);

    cout << endl;

    int price;
    cout << "Enter the price to be searched: ";
    cin >> price;

    int search = binary_search(array, price, 0, count - 1);

    if (search != -999){
        cout << "Found at index " << search << endl;
    }
    else {
        cout << "Price not found!" << endl;
    }

    return 0;
}
