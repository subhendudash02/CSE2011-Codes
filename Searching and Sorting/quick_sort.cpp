#include <iostream>

using namespace std;

void swapIt(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int A[], int p, int r){
    int a = A[r];
    int b = p - 1;

    for (int i = p; i <= (r - 1); i++){
        if (A[i] < a){
            b++;
            swapIt(&A[b], &A[i]);
        }
    }

    swapIt(&A[b + 1], &A[r]);
    return (b + 1);

}

void QuickSort(int A[], int p, int r){
    if (p < r){
        int k = Partition(A, p, r);
        QuickSort(A, p, k - 1);
        QuickSort(A, k + 1, r);
    }
}

void print(int A[], int count){
    for (int i = 0; i < count; i++){
        cout << A[i] << " ";
    }
    cout << endl;
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

    QuickSort(array, 0, count - 1);
    print(array, count);

    return 0;
}