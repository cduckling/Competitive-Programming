#include <iostream>
#include <vector>
#include <map>
using namespace std;

void dfs(int v, int p, const vector<vector<int>>& adj, vector<int>& visited, vector<map<int, int>>& tree) {
    visited[v] = true;

    for (int i : adj[v]) {
        if (i == p || !visited[i]) {
            tree[v][i] = 1;
            if (!visited[i]) dfs(i, v, adj, visited, tree);
        } else {
            if (!tree[i][v]) {
                tree[v][i] = -2;
            } else {
                tree[v][i] = -1;
            }
        }
    }
}

void dp(int v, int p, vector<map<int, int>>& tree, vector<int>& bridge) {
    vector<int> c {}; for (auto i : tree[v]) if (i.first != p && i.second == 1) {
            c.push_back(i.first);
            dp(i.first, v, tree, bridge);
        }

    for (auto i : tree[v]) bridge[v] += (i.second == -2);
    for (auto i : tree[v]) bridge[v] -= (i.second == -1);

    if (!c.empty()) for (int i : c) bridge[v] += bridge[i];
}

int main() {
    int n {}, m {}; cin >> n >> m;

    vector<vector<int>> adj (n); for (int i {0}; i < m; ++i) {
        int u {}, v {}; cin >> u >> v; --u; --v;
        adj[u].push_back(v); adj[v].push_back(u);
    }

    vector<map<int, int>> tree (n); vector<int> visited (n); dfs(0, -1, adj, visited, tree);

    vector<int> bridge (n); dp(0, -1, tree, bridge);

    for (int i {0}; i < n; ++i) if (!bridge[i]) cout << i << " ";
}
