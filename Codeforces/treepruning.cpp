#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define tc int t {}; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void dfs(int v, int p, const vector<vector<int>>& adj, vector<int>& par) {
    par[v] = p; for (int i : adj[v]) if (i != p) dfs(i, v, adj, par);
}

void solve() {
    int n {}; cin >> n;

    vector<vector<int>> adj (n); for (int i {1}; i < n; ++i) {
        int u {}, v {}; cin >> u >> v;
        --u; --v;
        adj[u].push_back(v); adj[v].push_back(u);
    }

    vector<int> dp (n), par (n); dfs(0, -1, adj, par);

    queue<int> q {}; q.push(0);

    int u {1}, v {1};

    for (int i {1}; i < n; ++i) {
        int t = q.size(); if (!t) break;

        for (int j {0}; j < t; ++j) {
            int l = q.front(); q.pop();

            int c {0}; for (int k : adj[l]) if (k != par[l]) {
                ++c; q.push(k);
            }

            if (c) {
                dp[l] = c; v += c;
            } else {
                while (l != 0 && !dp[l]) {
                    --v;
                    l = par[l];
                    --dp[l];
                }

                if (!dp[0]) break;
            }
        }

        u = max(u, v);
    }

    cout << n - u << "\n";
}

int main() {
    io
    tc

    return 0;
}