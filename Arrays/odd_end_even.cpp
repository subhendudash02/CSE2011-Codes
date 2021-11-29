#include <iostream>

using namespace std;

struct oddEven{
    int odd_count; 
    int even_count;
};

struct oddEven get(int array[], int number_of_elements){
    struct oddEven x;
    x.even_count = 0;
    x.odd_count = 0;

    for (int i = 0; i < number_of_elements; i++){
        if (array[i] % 2 == 0){
            x.even_count++;
        }
        else{
            x.odd_count++;
        }
    }

    return x;
}

int main(){

    //To count the number of odd and even elements in an array 

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

    struct oddEven oe= get(array, n);

    cout << "Number of odd elements: " << oe.odd_count << endl;
    cout << "Number of even elements: " << oe.even_count << endl;

    return 0;
}