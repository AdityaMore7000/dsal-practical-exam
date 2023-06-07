#include <iostream>
#include <climits>

using namespace std;

#define INF INT_MAX

class Graph {
private:
    int** graph;
    int vertices;

public:
    Graph(int v) {
        vertices = v;
        graph = new int*[vertices];
        for (int i = 0; i < vertices; i++) {
            graph[i] = new int[vertices];
            for (int j = 0; j < vertices; j++) {
                graph[i][j] = 0;
            }
        }
    }

    void addEdge(int src, int dest, int weight) {
        graph[src][dest] = weight;
        graph[dest][src] = weight;
    }

    void primMST() {
        int* parent = new int[vertices]; // Array to store the parent of each vertex in the MST
        int* key = new int[vertices]; // Array to store the key value (minimum weight edge) for each vertex
        bool* visited = new bool[vertices]; // Array to track visited vertices
        for (int i = 0; i < vertices; i++) {
            parent[i] = -1;
            key[i] = INF;
            visited[i] = false;
        }

        key[0] = 0; // Start with the first vertex

        for (int count = 0; count < vertices - 1; count++) {
            // Find the vertex with the minimum key value among the vertices not yet included in the MST
            int u = minKey(key, visited);

            visited[u] = true;

            // Update the key value and parent for adjacent vertices of the chosen vertex
            for (int v = 0; v < vertices; v++) {
                if (graph[u][v] != 0 && !visited[v] && graph[u][v] < key[v]) {
                    parent[v] = u;
                    key[v] = graph[u][v];
                }
            }
        }

        // Print the MST
        cout << "Edge \tWeight" << endl;
        for (int i = 1; i < vertices; i++) {
            cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
        }
    }

private:
    int minKey(int* key, bool* visited) {
        int min = INT_MAX;
        int minIndex;

        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && key[v] < min) {
                min = key[v];
                minIndex = v;
            }
        }

        return minIndex;
    }
};

int main() {
    int v, e;
    cout << "Enter the total number of vertices: ";
    cin >> v;
    cout << "Enter the total number of edges: ";
    cin >> e;

    Graph g(v);

    for (int i = 0; i < e; i++) {
        int src, dest, weight;
        cout << "Enter the source, destination, and weight of edge " << i + 1 << ": ";
        cin >> src >> dest >> weight;
        g.addEdge(src, dest, weight);
    }

    cout << "Minimum Spanning Tree (MST) using Prim's algorithm:" << endl;
    g.primMST();

    return 0;
}
