#include <iostream>
#include <vector>
using namespace std;

bool hasCycle(int u, int parent, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[u] = true;

    for (int v : adj[u]) {
        if (!visited[v]) {
            if (hasCycle(v, u, adj, visited))
                return true;
        } else if (v != parent) {
            return true;
        }
    }
    return false;
}

int main() {
    int n = 4;
    vector<vector<int>> adj(n);

    adj[0] = {1};
    adj[1] = {0,2};
    adj[2] = {1,3};
    adj[3] = {2,0}; // цикл

    vector<bool> visited(n, false);

    if (hasCycle(0, -1, adj, visited))
        cout << "Cycle detected\n";
    else
        cout << "No cycle\n";

    return 0;
}

