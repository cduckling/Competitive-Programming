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
#define eb(i) emplace_back(i)
#define ceil(a, b) ((a + b - 1) / b)
#define inf (ll) 1e18
#define fail cout << -1 << "\n"; return;
#define fir first
#define sec second

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
typedef set<pair<int, int>> spii;
typedef vector<set<int>> vsi;
typedef vector<vector<set<int>>> vvsi;
typedef map<int, int> mii;
typedef map<int, bool> mib;
typedef map<int, double> mid;
typedef vector<map<int, int>> vmii;
typedef vector<map<int, double>> vmid;
typedef vector<map<int, bool>> vmib;

void dfs(const int ver, const int par, vb& vis, vi& dep, vi& dp, vpii& bridge, const vvi& adj) {
    vis[ver] = true;

    for (const int i : adj[ver]) {
        if (i == par) continue;

        if (vis[i]) {
            if (dep[i] < dep[ver]) {
                dp[ver]++;
            } else {
                dp[ver]--;
            }
        } else {
            dep[i] = dep[ver] + 1; dfs(i, ver, vis, dep, dp, bridge, adj); dp[ver] += dp[i];
        }
    }

    if (ver != 1 && dp[ver] == 0) bridge.emplace_back(ver, par);
}

int main() {
    io

    int n, m; cin >> n >> m;

    vvi adj (n + 1); for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
    }

    vb vis (n + 1); vi dep (n + 1), dp (n + 1); vpii bridge; dfs(1, 0, vis, dep, dp, bridge, adj);

    for (const pii i : bridge) cout << i.fir << " " << i.sec << "\n";

    return 0;
}
