#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

vector<int> adj[100001];
int dp[100001];

void dfs(int vertice, int parent) {
    vector<int> children {}; for (int i : adj[vertice]) {
        if (i == parent) continue;

        dfs(i, vertice);
        children.push_back(i);
    }

    if (children.empty()) {
        dp[vertice] = 0;
    } else {
        dp[vertice] = ceil(log2(children.size() + 1)) + children.size();

        for (int c : children) dp[vertice] += dp[c];
    }
}

int main() {
    io

    int n {}; cin >> n;

    for (int i {0}; i < n - 1; ++i) {
        int u {}, v {}; cin >> u >> v; --u; --v;
        adj[u].push_back(v); adj[v].push_back(u);
    }

    dfs(0, 0); cout << dp[0];

    return 0;
}