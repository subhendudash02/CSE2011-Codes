#include <iostream>

using namespace std;

void returnArray(int arr[][2], int len){
    cout << "Brand-C\tBrand-P" << endl;

    for (int i = 0; i < len; i++){
        for (int j = 0; j < 2; j++){
            cout << arr[i][j] << '\t';
        }
        cout << '\n';
    }
}

int main(){

    cout << "Name: Subhendu Dash" << endl;
    cout << "Reg-No: 20BEE1004" << endl;
    cout << " " << endl;

    int start[3][2] = {{42, 54}, {36, 27}, {34, 30}};
    int end[3][2] = {{27, 31}, {28, 15}, {28, 22}};

    cout << "Stock at the beginning of the day: " << endl;
    returnArray(start, 3); 

    cout << "Stock at the end of the day: " << endl;
    returnArray(end, 3); 

    float ind_profits[3] = {0.75, 0.55, 1.20};

    cout << "Profit by each item: " << endl;
    cout << "Small: $" << ind_profits[0] << endl;
    cout << "Medium: $" << ind_profits[1] << endl;
    cout << "Large: $" << ind_profits[2] << endl;

    float total_profit = 0;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 1; j++){
            total_profit += ((start[i][j] + start[i][j + 1]) - (end[i][j] + end[i][j + 1])) * ind_profits[i];
        }
    }

    cout << "Total Profit: $" << total_profit;

    return 0;
}