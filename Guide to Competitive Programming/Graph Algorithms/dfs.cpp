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
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpii;
typedef vector<bool> vb;
typedef set<int> si;
typedef map<int, int> mi;
typedef map<int, vector<int>> mvi;
typedef map<int, pair<int, int>> mpii;
typedef map<int, bool> mb;

void dfs(int ver, const vvi& adj, vb& vis) {
    if (vis[ver]) return;

    vis[ver] = true;
    for (int i : adj[ver]) dfs(i, adj, vis);
}

int main() {
    io

    int n {}, m {}; cin >> n >> m;

    vvi adj (n); for (int i {0}; i < m; ++i) {
        int u {}, v {}; cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }

    vb vis (n); dfs(0, adj, vis);

    return 0;
}