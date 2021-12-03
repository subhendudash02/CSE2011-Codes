#include <bits/stdc++.h>

using namespace std;

struct photo_info{
    int id;  // should be unique
    string tag_name;
    int size;  // all the sizes are in kB
};

void swapIt(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selection_sort(struct photo_info arr[], int n){
    for (int i = 0; i < n; i++){
        int minimum = i;

        for (int j = i + 1; j < n; j++){
            if (arr[j].size < arr[minimum].size){
                minimum = j;
            }
        }
        swapIt(&arr[i].size, &arr[minimum].size);
        swapIt(&arr[i].id, &arr[minimum].id);
        arr[i].tag_name.swap(arr[minimum].tag_name);
    }
}

void photo_desc_print(struct photo_info arr[], int from, int to){
    for (int i = from; i < to; i++){
        cout << "Photo " << i + 1 << " : " << endl;
        cout << "Photo ID: " << arr[i].id << endl;
        cout << "Photo Size: " << arr[i].size << endl;
        cout << "Photo Tag: " << arr[i].tag_name << endl;
        cout << endl;
    }
}

void linear_search(struct photo_info arr[], int n, string tag){
    int c = 0;
    for (int i = 0; i < n; i++){
        if (arr[i].tag_name == tag){
            photo_desc_print(arr, i, i + 1);
            c = 1;
        }
    }
    if (c == 0){
        cout << "Photo Not Found!" << endl;
    }
}


int main(){

    cout << "Name: Subhendu Dash" << endl;
    cout << "Reg-No: 20BEE1004" << endl;
    cout << " " << endl;

    struct photo_info arr[5] = {{562723, "Birthday Party", 738}, 
                                {654354, "College Farewell", 865}, 
                                {224541, "Personal", 633},
                                {107456, "Brother's Wedding", 864},
                                {541032, "Personal", 750}};

    cout << "Sorting the list of photos on the basis of size..." << endl;
    selection_sort(arr, 5);

    cout << "List of Photos" << endl;
    photo_desc_print(arr, 0, 5);

    
    int decide = 1;
    string get_tag;

    while (decide != 0){
        cout << "Search the photo you want by using tag name: ";
        getline(cin, get_tag);
        cin.ignore();
        linear_search(arr, 5, get_tag);
        cout << "Want to search more photos? (0 / 1) " << endl;
        cin >> decide;
        cin.ignore();
    }

    return 0;
}