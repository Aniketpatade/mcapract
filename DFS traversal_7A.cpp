#include <iostream>
#include <vector>
using namespace std;

// Function for DFS traversal
void DFS(int node, vector<bool>& visited, vector<vector<int>>& adjList) {
    cout << node << " ";
    visited[node] = true;

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, visited, adjList);
        }
    }
}

int main() {
    int vertices, edges;
    cout << "Enter number of vertices and edges: ";
    cin >> vertices >> edges;

    // Adjacency List representation
    vector<vector<int>> adjList(vertices);
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u); // Uncomment for undirected graph
    }

    // Performing DFS
    vector<bool> visited(vertices, false);
    cout << "DFS Traversal: ";
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            DFS(i, visited, adjList);
        }
    }

    return 0;
}
