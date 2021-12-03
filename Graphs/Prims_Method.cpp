#include <iostream>
#include <climits>
#define V 6

using namespace std;

int minimum(int x[], bool y[]) {
    int min = INT_MAX, ind;

    for (int i = 0; i < V; i++){
        if(x[i] < min && !y[i]){
            min = x[i];
            ind = i;
        }
    }
    
    return ind;
}

void primAlgo(int graph[][V]) {
    int x[V], y[V];
    bool z[V];

    for (int i = 0; i < V; i++){
        y[i] = INT_MAX;
        z[i] = false;
    }

    y[0] = 0;
    x[0] = -1;

    for (int i = 0; i < (V - 1); i++){
        int k = minimum(y, z);
        z[k] = true;

        for (int j = 0; j < V; j++){
            if (graph[k][j] && !z[j] && graph[k][j] < y[j]){
                x[j] = k;
                y[j] = graph[k][j];
            }
        }
    }

    cout << "Edge\tCost\n";
    int minimumCost = 0;
    for (int i = 1; i < V; i++){
        cout << x[i] << ", " << i << "\t" << graph[i][x[i]] << endl;
        minimumCost += graph[i][x[i]];
    }
    cout << "Minimum Cost: " << minimumCost << endl;
}

int main() {

    cout << "Name: Subhendu Dash" << endl;
    cout << "Reg No: 20BEE1004" << endl;

    int graph[][V] = {
        {INT_MAX, 4, INT_MAX, INT_MAX, INT_MAX, 2},
        {4, INT_MAX, 6, INT_MAX, INT_MAX, 3},
        {INT_MAX, 6, INT_MAX, 3, INT_MAX, 1},
        {INT_MAX, INT_MAX, 3, INT_MAX, 2, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, 2, INT_MAX, 4},
        {2, 3, 1, INT_MAX, 4, INT_MAX}
    };

    primAlgo(graph);

    return 0;
}
