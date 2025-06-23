#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
using namespace std;

#define tc int t; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(a) (a).begin(), (a).end()
#define pb(i) push_back(i)
#define eb(a, b) emplace_back(a, b)
#define ceil(a, b) ((a + b - 1) / b)
#define inf (ll) 1e18

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<vector<vector<double>>> vvvd;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<pair<int, int>>> vvpii;
typedef vector<vector<vector<pair<int, int>>>> vvvpii;
typedef tuple<int, int, int> tii;
typedef vector<tuple<int, int, int>> vtii;
typedef vector<vector<tuple<int, int, int>>> vvtii;
typedef vector<vector<vector<tuple<int, int, int>>>> vvvtii;
typedef set<int> si;
typedef vector<set<int>> vsi;
typedef vector<vector<set<int>>> vvsi;
typedef map<int, int> mii;
typedef map<int, bool> mib;
typedef map<int, double> mid;
typedef vector<map<int, int>> vmii;
typedef vector<map<int, double>> vmid;
typedef vector<map<int, bool>> vmib;

#define fail {cout << -1 << "\n"; return 0;}

void dfs(const int ver, vi& p, map<int, set<pii>>& adj) {
    while (!adj[ver].empty()) {
        const int nxt = adj[ver].begin()->first, id = adj[ver].begin()->second;

        adj[ver].erase({nxt, id}), adj[nxt].erase({ver, id});

        dfs(nxt, p, adj); p.pb(id);
    }
}

int main() {
    io

    int n, m; cin >> n >> m;

    map<int, set<pii>> adj; for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].emplace(v, i), adj[v].emplace(u, i);
    }

    int cnt = 0, ver = adj.begin()->first; for (const auto& i : adj) if (adj[i.first].size() % 2) ver = i.first, cnt++; if (cnt != 0 && cnt != 2) fail

    vi p; dfs(ver, p, adj);

    if (p.size() != m) fail reverse(all(p)); for (const int i : p) cout << i << " "; cout << "\n";

    return 0;
}