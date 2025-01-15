#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Function for BFS traversal
void BFS(int start, vector<vector<int>>& graph, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int vertices, edges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;

    // Graph representation as adjacency list
    vector<vector<int>> graph(vertices);

    cout << "Enter edges (u v): " << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // For undirected graph
    }

    vector<bool> visited(vertices, false);

    cout << "BFS Traversal starting from node 0: ";
    BFS(0, graph, visited);

    return 0;
}
