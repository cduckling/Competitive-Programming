#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<int, int> pii;

void bfs(const vector<vector<int>>& adj, vector<int>& d, const int& n) {
    vector<bool> v (n);

    d[0] = 0; v[0] = true;

    queue<int> q {}; q.push(0);

    while (!q.empty()) {
        int ver = q.front(); q.pop();

        for (int i : adj[ver]) {
            if (!v[i]) {
                d[i] = d[ver] + 1; v[i] = true; q.push(i);
            }
        }
    }
}

void solve() {
    int n {}, m {}; cin >> n >> m;

    vector<vector<int>> adj (n); for (int i {0}; i < m; ++i) {
        int u {}, v {}; cin >> u >> v; --u; --v;
        adj[u].push_back(v);
    }

    vector<int> d (n); bfs(adj, d, n);
    vector<pii> dist (n); for (int i {0}; i < n; ++i) dist[i] = {d[i], i}; sort(dist.begin(), dist.end(), greater<pii>()); // (D[v], v)

    vector<int> dp (n); for (const pii& i: dist) dp[i.second] = i.first; for (const pii& i : dist) for (int j : adj[i.second]) dp[i.second] = min(dp[i.second], (d[j] > i.first ? dp : d)[j]);

    for (int i : dp) cout << i << " "; cout << "\n";
}

int main() {
    io
    tc

    return 0;
}