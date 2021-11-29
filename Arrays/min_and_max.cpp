#include <iostream>

using namespace std;

struct minmax{
    int maximum;
    int minimum;
};

struct minmax get(int array[], int number_of_elements){
    struct minmax k;

    k.minimum = array[0]; 
    k.maximum = array[0];

    for (int i = 0; i < number_of_elements; i++){
        if (array[i] < k.minimum){
            k.minimum = array[i];
        }
        if (array[i] > k.maximum){
            k.maximum = array[i];
        }
    }

    return k;

}

int main(){

    //To find the Maximum and Minimum Element in an array.

    cout << "Name: Subhendu Dash" << endl;
    cout << "Reg-No: 20BEE1004" << endl;
    cout << " " << endl;

    int n;
    cout << "Enter number of elements in an array: ";
    cin >> n;

    int array[n];
    
    for (int i = 0; i < n; i++){
        cout << "Enter " << (i + 1) << " element: ";
        cin >> array[i];
    }

    struct minmax x = get(array, n);

    cout << "Minimum element is " << x.minimum << endl;
    cout << "Maximum element is " << x.maximum << endl;

    return 0;
}