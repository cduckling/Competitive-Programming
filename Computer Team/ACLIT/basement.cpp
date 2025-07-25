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
#define inf 1e18
#define fail cout << -1 << "\n"; return;

typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<set<int>> vsi;
typedef vector<pair<int, int>> vpii;
typedef vector<tuple<int, int, int>> vtiii;
typedef vector<bool> vb;
typedef multiset<int> msi;
typedef set<int> si;
typedef set<pair<int, int>> spii;
typedef set<tuple<int, int, int>> stiii;
typedef map<int, int> mii;
typedef map<int, vector<int>> mivi;
typedef map<int, pair<int, int>> mipii;
typedef map<int, set<int>> misi;
typedef map<int, bool> mib;

void dfs(const int ver, const int par, vi& dp, vi& val, const vvi& adj) {
    vi c; for (const int i : adj[ver]) {
        if (i != par) {
            c.pb(i); dfs(i, ver, dp, val, adj);
        }
    }

    if (c.empty()) return;

    vi C; for (const int i : c) C.pb(dp[i]); sort(all(C), greater<int>());

    dp[ver] = C[0] + 1;

    if (c.size() >= 2) val[ver] = C[0] + C[1] + 2;
}

void solve() {
    int n; cin >> n;

    vvi adj (n + 1); for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }

    vi dp (n + 1), val (n + 1);

    dfs(1, -1, dp, val, adj);

    int sol = 0; for (const int i : val) sol = max(sol, i);

    cout << max(sol, dp[1]) << "\n";
}

int main() {
    io

    solve();

    return 0;
}