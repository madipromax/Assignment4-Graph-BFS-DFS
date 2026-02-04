#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 5; // количество вершин
    vector<vector<int>> adj(n);

    // рёбра
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(3);
    adj[2].push_back(3);
    adj[3].push_back(4);

    cout << "Adjacency List:\n";
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (int v : adj[i])
            cout << v << " ";
        cout << endl;
    }

    return 0;
}
