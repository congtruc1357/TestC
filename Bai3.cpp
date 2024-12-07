#include <iostream>
#include <vector>
#include <list>
using namespace std;

struct Edge {
    int to;
    double weight;
};

int main() {
    const int V = 8; // Number of vertices
    vector<list<Edge>> adj(V);

    // Adding edges (example from tinyEWD.txt)
    adj[0].push_back({2, 0.26});
    adj[0].push_back({4, 0.38});
    adj[1].push_back({3, 0.29});
    adj[2].push_back({7, 0.34});
    adj[3].push_back({6, 0.52});
    adj[4].push_back({7, 0.37});
    adj[4].push_back({5, 0.35});
    adj[5].push_back({1, 0.32});
    adj[5].push_back({7, 0.28});
    adj[5].push_back({4, 0.35});
    adj[6].push_back({4, 0.93});
    adj[6].push_back({0, 0.58});
    adj[6].push_back({2, 0.40});
    adj[7].push_back({3, 0.39});
    adj[7].push_back({5, 0.28});

    // Print the adjacency list
    for (int i = 0; i < V; ++i) {
        cout << i << ": ";
        for (const auto& edge : adj[i]) {
            cout << "(" << edge.to << ", " << edge.weight << ") ";
        }
        cout << endl;
    }

    return 0;
}
