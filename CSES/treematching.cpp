#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, int parent, const vector<vector<int>>& adj, vector<pair<int, int>>& matching) {
    vector<int> children {};

    for (int i : adj[node]) {
        if (i == parent) continue;

        dfs(i, node, adj, matching);
        children.push_back(i);
    }

    if (children.empty()) return;

    int tot {0}; for (int i : children) tot += matching[i].first;

    matching[node].second = tot;

    int a {0};
    for (int i : children) {
        a = max(a, tot + matching[i].second + 1 - matching[i].first);
    }
    matching[node].first = a;
}

int main() {
    int n {}; cin >> n;

    vector<vector<int>> adj (n + 1); for (int i {1}; i < n; ++i) {
        int a {}, b {}; cin >> a >> b;
        adj[a].push_back(b); adj[b].push_back(a);
    }

    vector<pair<int, int>> matching (n + 1);

    dfs(1, 0, adj, matching);

    cout << max(matching[1].first, matching[1].second);
}