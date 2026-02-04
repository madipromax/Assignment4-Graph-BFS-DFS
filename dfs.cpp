#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n = 6;
    vector<vector<int>> adj(n);

    adj[0] = {1,2};
    adj[1] = {3};
    adj[2] = {3,5};
    adj[3] = {4};
    adj[4] = {5};

    vector<bool> visited(n, false);
    vector<int> dist(n, -1), parent(n, -1);
    queue<int> q;

    int start = 0;
    visited[start] = true;
    dist[start] = 0;
    q.push(start);

    cout << "BFS order: ";

    while (!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                parent[v] = u;
                q.push(v);
            }
        }
    }

    cout << "\nShortest path 0 -> 5: ";
    int t = 5;
    if (!visited[t]) {
        cout << "No path";
    } else {
        vector<int> path;
        for (int v = t; v != -1; v = parent[v])
            path.push_back(v);

        for (int i = path.size()-1; i >= 0; i--)
            cout << path[i] << " ";
    }

    return 0;
}
