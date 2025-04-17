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
#define inf (ll) 1e18
#define f first
#define s second

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
typedef tuple<int, int, int> tiii;
typedef vector<tuple<int, int, int>> vtiii;
typedef vector<vector<tuple<int, int, int>>> vvtiii;
typedef vector<vector<vector<tuple<int, int, int>>>> vvvtiii;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef set<int> si;
typedef vector<set<int>> vsi;
typedef vector<vector<set<int>>> vvsi;
typedef set<pair<int, int>> spii;
typedef vector<set<pair<int, int>>> vspii;
typedef map<int, int> mii;
typedef map<int, bool> mib;
typedef map<int, double> mid;
typedef vector<map<int, int>> vmii;
typedef vector<map<int, double>> vmid;
typedef vector<map<int, bool>> vmib;

void dfs(const int ver, const int p, int& pos, vi& tta, vi& size, vi& id, vi& par, const vvi& adj) {
    tta[pos] = ver, id[ver] = pos, size[ver] = 1, par[ver] = p;

    for (const int i : adj[ver]) if (i != p) dfs(i, ver, ++pos, tta, size, id, par, adj), size[ver] += size[i];
}

bool valid(pii& cur, const pii& r) {
    if (cur.second < r.first || r.second < cur.first) return false;

    if (cur.first <= r.first && r.second <= cur.second) cur = r; return true;
}

void solve() {
    int n, q; cin >> n >> q;

    vvi adj (n + 1); for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }

    vi tta (n + 1), size (n + 1), id (n + 1), par (n + 1); int pos = 1; dfs(1, 0, pos, tta, size, id, par, adj);

    for (int i = 0; i < q; i++) {
        int k; cin >> k;

        pii cur {1, n};

        bool ok = true;

        for (int j = 0; j < k; j++) {
            int v; cin >> v; v = par[v]; if (v <= 1) continue;

            if (!valid(cur, {id[v], id[v] + size[v] - 1})) ok = false;
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }
}

int main() {
    io

    solve();

    return 0;
}