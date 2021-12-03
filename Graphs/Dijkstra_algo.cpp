#include <iostream>
#include <climits>
#define k 6

using namespace std;

void print(int arr[]) {
    cout << "Vertex \t Distance\n";
    for (int i = 0; i < k; i++) {
        cout << i + 1 << "\t" << arr[i] << "\n"; 
    }
}

int minimum(int arr[], bool boolset[]) {
    int a = INT_MAX;
    int min;

    for (int i = 0; i < k; i++) {
        if (arr[i] <= a && boolset[i] == false) {
            a = arr[i];
            min = i;
        }
    }

    return min;
}

void dijkstraAlgo(int g[k][k], int x) {
    int dist[k];
    bool set[k];

    for (int i = 0; i < k; i++) {
        dist[i] = INT_MAX;
        set[i] = false;
    }

    dist[x] = 0;

    for (int i = 0; i < k - 1; i++) {
        int r = minimum(dist, set);
        set[i] = true;

        for (int j = 0; j < k; j++) {
            if (!set[j] && dist[i] != INT_MAX && dist[i] + g[i][j] < dist[j] && g[i][j]) {
                dist[j] = dist[i] + g[i][j];
            }
        }
    }

    print(dist);
}

int main() {

    cout << "Name: Subhendu Dash" << endl;
    cout << "Reg No: 20BEE1004" << endl;

    int graph[k][k] = {
        {0, 7, 9, 0, 0, 14},
        {7, 0, 10, 15, 0, 0},
        {9, 10, 0, 11, 0, 2},
        {0, 15, 11, 0, 6, 0},
        {0, 0, 0, 6, 0, 9},
        {14, 0, 2, 0, 9, 0}
    };
 
    dijkstraAlgo(graph, 0);

    return 0;
}
