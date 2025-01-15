
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Edge {
public:
    int src, dest, weight;
    Edge(int s, int d, int w) : src(s), dest(d), weight(w) {}
};

// Disjoint Set
class DisjointSet {
    vector<int> parent, rank;

public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) parent[i] = i;
    }

    int find(int node) {
        if (parent[node] != node)
            parent[node] = find(parent[node]); // Path compression
        return parent[node];
    }

    void unite(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            if (rank[rootU] < rank[rootV])
                parent[rootU] = rootV;
            else if (rank[rootU] > rank[rootV])
                parent[rootV] = rootU;
            else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

// Kruskal's Algorithm
vector<Edge> kruskalMST(vector<Edge>& edges, int V) {
    sort(edges.begin(), edges.end(), [](Edge& e1, Edge& e2) {
        return e1.weight < e2.weight;
    });

    DisjointSet ds(V);
    vector<Edge> mst;

    for (Edge& edge : edges) {
        if (ds.find(edge.src) != ds.find(edge.dest)) {
            mst.push_back(edge);
            ds.unite(edge.src, edge.dest);
        }
    }

    return mst;
}

int main() {
    int V = 5; // Number of vertices
    vector<Edge> edges = {
        Edge(0, 1, 10),
        Edge(0, 2, 6),
        Edge(0, 3, 5),
        Edge(1, 3, 15),
        Edge(2, 3, 4),
    };

    vector<Edge> mst = kruskalMST(edges, V);

    cout << "Edges in Minimum Cost Spanning Tree:\n";
    int totalCost = 0;
    for (Edge& edge : mst) {
        cout << edge.src << " -- " << edge.dest << " == " << edge.weight << "\n";
        totalCost += edge.weight;
    }

    cout << "Total Minimum Cost: " << totalCost << endl;

    return 0;
}