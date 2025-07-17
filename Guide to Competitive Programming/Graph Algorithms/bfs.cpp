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

int main() {
    io

    int n, m; cin >> n >> m;

    vvi adj (n); for (int i {0}; i < m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }

    vb vis (n); vi dist (n);

    queue<int> q; q.push(0); vis[0] = true;

    while (!q.empty()) {
        const int u = q.front(); q.pop();

        for (auto v : adj[u]) {
            if (!vis[v]) {
                q.push(v); vis[v] = true, dist[v] = dist[u] + 1;
            }
        }
    }

    return 0;
}