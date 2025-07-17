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

void dfs(const int ver, const int par, vi& dep, vvi& up, const vvi& adj) {
    up[ver][0] = par; for (int i = 1; i <= 30; i++) up[ver][i] = up[up[ver][i - 1]][i - 1];

    for (const int i : adj[ver]) if (i != par) dep[i] = dep[ver] + 1, dfs(i, ver, dep, up, adj);
}

int anc(int ver, const int k, const vvi& up) {
    for (int j = 0; j <= 30; j++) if ((1<<j&k) > 0) ver = up[ver][j]; return ver;
}

int lca(int a, int b, const vi& dep, const vvi& up) {
    if (dep[a] < dep[b]) swap(a, b); a = anc(a, dep[a] - dep[b], up);

    if (a == b) return a;

    for (int i = 30; i >= 0; i--) if (up[a][i] != up[b][i]) a = up[a][i], b = up[b][i]; return up[a][0];
}

int main() {
    io

    int n, q; cin >> n >> q;

    vvi adj (n + 1); for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
    }

    vi dep (n + 1); dep[1] = 1;

    vvi up (n + 1, vi (31));

    dfs(1, 0, dep, up, adj);

    for (int i = 0; i < q; i++) {
        int a, b; cin >> a >> b;

        cout << lca(a, b, dep, up) << "\n";
    }

    return 0;
}