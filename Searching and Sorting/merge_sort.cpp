#include <iostream>

using namespace std;

void merge(int A[], int l, int m, int r){
    int A1 = m - l + 1;
    int A2 = r - m;

    int *leftArr = new int[A1];
    int *rightArr = new int[A2];

    for (int i = 0; i < A1; i++){
        leftArr[i] = A[l + i];
    }
    for (int i = 0; i < A2; i++){
        rightArr[i] = A[m + 1 + i];
    }

    int i1 = 0, i2 = 0, i3 = l;

    while (i1 < A1 && i2 < A2){
        if (leftArr[i1] <= rightArr[i2]){
            A[i3] = leftArr[i1];
            i1++;
        }
        else{
            A[i3] = rightArr[i2];
            i2++;
        }
        i3++;
    }

    while (i1 < A1){
        A[i3] = leftArr[i1];
        i1++;
        i3++;
    }

    while (i2 < A2){
        A[i3] = rightArr[i2];
        i2++;
        i3++;
    }
}

void merge_sort(int A[], int p, int r){
    if (p >= r) {
        return;
    }
    else{
        int m = p + (r - p) / 2;
        merge_sort(A, p, m);
        merge_sort(A, m + 1, r);
        merge(A, p, m, r);
    }
}

int main(){

    cout << "Name: Subhendu Dash" << endl;
    cout << "Reg-No: 20BEE1004" << endl;
    cout << " " << endl;

    int count;
    cout << "Enter the number of elements: ";
    cin >> count;

    int array[count];

    for (int i = 0; i < count; i++){
        cin >> array[i];
    }

    merge_sort(array, 0, count - 1);

    for (int i = 0; i < count; i++){
        cout << array[i] << " ";
    }

    return 0;
}
