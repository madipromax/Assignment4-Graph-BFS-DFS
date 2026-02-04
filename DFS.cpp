#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void DFSrec(int u, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[u] = true;
    cout << u << " ";
    for (int v : adj[u]) {
        if (!visited[v])
            DFSrec(v, adj, visited);
    }
}

int main() {
    int n = 5;
    vector<vector<int>> adj(n);

    adj[0] = {1,2};
    adj[1] = {3};
    adj[2] = {};
    adj[3] = {4};

    vector<bool> visited(n, false);

    cout << "DFS recursive: ";
    DFSrec(0, adj, visited);

    cout << "\nDFS iterative: ";
    vector<bool> vis(n, false);
    stack<int> st;
    st.push(0);

    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (vis[u]) continue;
        vis[u] = true;
        cout << u << " ";
        for (int v : adj[u])
            st.push(v);
    }

    return 0;
}
