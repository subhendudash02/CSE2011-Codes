#include <iostream>
#include <climits>
#define V 6

using namespace std;

class GraphAlgo {
    int x[V];

    int search(int i) {
        while (x[i] != i){
            i = x[i];
        }
        return i;
    }

    void merge(int a, int b) {
        int k = search(a);
        int l = search(b);

        x[k] = l;
    }

    public:
    void kruskalAlgo(int graph[][V]) {
        int z = 0;
        int c = 0;

        for (int i = 0; i < V; i++){
            x[i] = i;
        }

        while (c < V - 1){
            int min = INT_MAX, a = -1, b = -1;

            for (int i = 0; i < V; i++){
                for (int j = 0; j < V; j++){
                    if (search(i) != search(j) && graph[i][j] < min){
                        min = graph[i][j];
                        a = i;
                        b = j;
                    }
                } 
            }

            merge(a, b);
            cout << "Edge " << c++ << " : " << a << ", " <<  b << " Cost: " << min << endl;
            z += min;
        }
        
        cout << "Minimum cost: " << z << endl;
    }
};

int main() {

    cout << "Name: Subhendu Dash" << endl;
    cout << "Reg No: 20BEE1004" << endl;

    GraphAlgo g;

    int graph[][V] = {
        {INT_MAX, 4, INT_MAX, INT_MAX, INT_MAX, 2},
        {4, INT_MAX, 6, INT_MAX, INT_MAX, 3},
        {INT_MAX, 6, INT_MAX, 3, INT_MAX, 1},
        {INT_MAX, INT_MAX, 3, INT_MAX, 2, INT_MAX},
        {INT_MAX, INT_MAX, INT_MAX, 2, INT_MAX, 4},
        {2, 3, 1, INT_MAX, 4, INT_MAX}
    };

    g.kruskalAlgo(graph);

    return 0;
}
