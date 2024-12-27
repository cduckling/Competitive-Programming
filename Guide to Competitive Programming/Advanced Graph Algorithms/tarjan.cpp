#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb(i) push_back(i);
#define inf 1e18;

typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpii;
typedef vector<tuple<int, int, int>> vtiii;
typedef vector<bool> vb;
typedef set<int> si;
typedef map<int, int> mi;
typedef map<int, vector<int>> mvi;
typedef map<int, pair<int, int>> mpii;
typedef map<int, bool> mb;

void dfs(const int& v, const int& p, const vvi& adj, vi& vis, vector<mi>& tree) {
    vis[v] = true;

    for (ll i : adj[v]) {
        if (i == p || !vis[i]) {
            tree[v][i] = 1;
            if (!vis[i]) dfs(i, v, adj, vis, tree);
        } else {
            if (!tree[i][v]) {
                tree[v][i] = -2;
            } else {
                tree[v][i] = -1;
            }
        }
    }
}

void dp(const int& v, const int& p, vector<mi>& tree, vi& b) {
    vi c {}; for (auto i : tree[v]) if (i.first != p && i.second == 1) {
        c.pb(i.first);
        dp(i.first, v, tree, b);
    }

    for (auto i : tree[v]) b[v] += (i.second == -2);
    for (auto i : tree[v]) b[v] -= (i.second == -1);

    if (!c.empty()) for (ll i : c) b[v] += b[i];
}

int main() {
    io

    int n {}, m {}; cin >> n >> m;

    vvi adj (n); for (int i {0}; i < m; ++i) {
        int u {}, v {}; cin >> u >> v;

        adj[u].pb(v); adj[v].pb(u);
    }

    vector<mi> tree (n); vi vis (n); dfs(0, -1, adj, vis, tree);

    vi b (n); dp(0, -1, tree, b);

    for (int i {0}; i < n; ++i) if (!b[i]) cout << i << " ";

    return 0;
}