#include <iostream>
#include <vector>

using namespace std;

class Graph {
    int edges;
    int vertices;
    int ** adjacency;

    public:
    void create(int vertices, int edges) {
        this->edges = edges;
        this->vertices = vertices;
        adjacency = new int*[vertices];

        for (int i = 0; i < vertices; i++){
            adjacency[i] = new int[vertices];
            
            for (int j = 0; j < vertices; j++){
                adjacency[i][j] = 0;
            }
        }
    }

    void insert(int x, int y) {
        adjacency[x][y] = 1;
        adjacency[y][x] = 1;
    }

    void BFS(int x) {
        vector<bool> a(vertices, false);
        vector<int> b;
        b.push_back(x);

        a[x] = true;

        int c;
        while (!b.empty()){
            c = b[0];
            cout << c << " ";

            b.erase(b.begin());

            for (int i = 0; i < vertices; i++){
                if (adjacency[c][i] == 1 && !a[i]){
                    b.push_back(i);
                    a[i] = true;
                }
            }
        }
    }
};

int main(){

    cout << "Name: Subhendu Dash" << endl;
    cout << "Reg No: 20BEE1004" << endl;
    
    int vertices, edges;

    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;

    Graph gr;
    gr.create(vertices, edges);

    int decide = 1;

    while (decide == 1){
        int x, y;
        cin >> x >> y;
        gr.insert(x, y);
        cout << "continue? ";
        cin >> decide;
        if (decide == 0) {
            break;
        }
    }

    vector<bool> visit(vertices, false);

    int start;
    cout << "From which element you wanna start BFS? ";
    cin >> start;

    cout << "BFS" << endl;
    // gr.DFS(start, visit);
    gr.BFS(start);

    return 0;
}
