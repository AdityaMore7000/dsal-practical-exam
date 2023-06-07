#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

class Graph {
    int numVertices;
    vector<vector<int>> adjList;

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjList.resize(numVertices);
    }

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
        adjList[dest].push_back(src);
    }

    void BFS(int startVertex) {
        vector<bool> visited(numVertices, false);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        cout << "BFS Traversal: ";
        while (!q.empty()) {
            int currVertex = q.front();
            q.pop();
            cout << currVertex << " ";

            for (int adjacent : adjList[currVertex]) {
                if (!visited[adjacent]) {
                    visited[adjacent] = true;
                    q.push(adjacent);
                }
            }
        }
        cout << endl;
    }

    void DFS(int startVertex) {
        vector<bool> visited(numVertices, false);
        stack<int> st;

        visited[startVertex] = true;
        st.push(startVertex);

        cout << "DFS Traversal: ";
        while (!st.empty()) {
            int currVertex = st.top();
            st.pop();
            cout << currVertex << " ";

            for (int adjacent : adjList[currVertex]) {
                if (!visited[adjacent]) {
                    visited[adjacent] = true;
                    st.push(adjacent);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int numVertices, numEdges;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    Graph graph(numVertices);

    cout << "Enter the edges (source and destination):" << endl;
    for (int i = 0; i < numEdges; i++) {
        int src, dest;
        cin >> src >> dest;
        graph.addEdge(src, dest);
    }

    int startVertex;
    cout << "Enter the starting vertex for traversal: ";
    cin >> startVertex;

    graph.BFS(startVertex);
    graph.DFS(startVertex);

    return 0;
}
