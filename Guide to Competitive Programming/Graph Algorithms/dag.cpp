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

void dfs(const int& ver, vi& vis, vi& ts, const vvi& adj) {
    if (vis[ver]) return; vis[ver] = 1; for (int i : adj[ver]) dfs(i, vis, ts, adj); vis[ver] = 2; ts.pb(ver);
}

int main() {
    io

    int n, m; cin >> n >> m;

    vvi adj (n + 1); for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v; adj[u].pb(v);
    }

    vi vis (n + 1), ts; for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i, vis, ts, adj); reverse(ts.begin(), ts.end()); for (const int i : ts) cout << i << " "; cout << "\n";

    return 0;
}
