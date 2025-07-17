#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
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

#define rev(a) make_pair(a.sec, a.fir)
#define done(col) {for (int i = 1; i < col.size(); i++) cout << col[i]; cout << "\n"; return;}

void dfs(const int ver, const int par, vb& vis, vi& dep, vi& up, vpii& back, const vvi& adj) {
    vis[ver] = true, up[ver] = par;

    for (const int i : adj[ver]) {
        if (i == par) continue;

        if (vis[i]) {
            if (dep[i] < dep[ver]) back.emplace_back(ver, i);
        } else {
            dep[i] = dep[ver] + 1; dfs(i, ver, vis, dep, up, back, adj);
        }
    }
}

void solve() {
    int n, m; cin >> n >> m;

    vvi adj (n + 1); vpii edge (m + 1); for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
        edge[i] = {u, v};
    }

    vpii back; vi dep (n + 1), up (n + 1); vb vis (n + 1); dfs(1, 0, vis, dep, up, back, adj);

    vi ind; for (const pii i : back) for (int j = 1; j <= m; j++) if (i == edge[j] || rev(i) == edge[j]) ind.pb(j);

    vb col (m + 1); for (const int i : ind) col[i] = true;

    si dist; for (const pii i : back) dist.insert(i.fir), dist.insert(i.sec);

    if (m - n + 1 <= 2 || (m - n + 1 == 3 && dist.size() > 4)) done(col)

    pii bad;

    for (int i = 0; i < back.size(); i++) {
        int first = 0, second = 0;

        for (int j = 0; j < back.size(); j++) {
            if (i == j) continue;

            if (back[i].fir == back[j].fir || back[i].fir == back[j].sec) first++;
            if (back[i].sec == back[j].fir || back[i].sec == back[j].sec) second++;
        }

        if (first == 1 && second == 1) {
            bad = back[i];
        }
    }

    for (int i = 1; i <= m; i++) if (bad == edge[i] || bad == rev(edge[i])) col[i] = false;

    pii good = {bad.fir, up[bad.fir]}; for (int i = 1; i <= m; i++) if (good == edge[i] || good == rev(edge[i])) col[i] = true;

    done(col);
}

int main() {
    io
    tc

    return 0;
}