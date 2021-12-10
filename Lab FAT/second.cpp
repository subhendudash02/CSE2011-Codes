#include <iostream>
#include <string>

using namespace std;

void sortNames(string arr[], int length) {
    // Selection Sort

    int mini;

    for (int i = 0; i < length - 1; i++) {
        mini = i;
        for (int j = i + 1; j < length; j++) {
            if (arr[j] < arr[mini]) {
                mini = j;
            }
        }
        arr[mini].swap(arr[i]);
    }
}

void printNames(string arr[], int length) {
    for (int i = 0; i < length; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

int main() {
    cout << "Name: Subhendu Dash\nReg No: 20BEE1004\nDate: 10 December 2021\nCSE2011 Lab FAT Examinations" << endl;
    cout << endl;

    string names[8] = {"Phil Doe", "Jane Doe", "Fred Doe", "Bill Jones", "Jane Jones", "Mary Smith", "Fred Smith", "Jane Smith"};

    cout << "Names sorted by last name: " << endl;

    printNames(names, 8);    

    cout << "Sorting the elements..." << endl;
    sortNames(names, 8);

    cout << "Now, names sorted by first name: " << endl;

    printNames(names, 8); 

    return 0;
}