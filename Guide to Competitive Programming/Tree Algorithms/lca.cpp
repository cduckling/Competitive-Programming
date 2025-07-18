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

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

#define tc int t; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(a) (a).begin(), (a).end()
#define pb(i) push_back(i)
#define eb(i) emplace_back(i)
#define inf 1e9
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
typedef vector<char> vc;
typedef vector<vector<char>> vvc;

struct SEGTREE {
    int n; vi t, dep;

    SEGTREE(const int n) {
        this->n = n; t.assign(2 * n, 0);
    }

    SEGTREE(const vi& a, const vi& dep) : SEGTREE(a.size()) {
        this->dep = dep; for (int i = 0; i < n; i++) set(i, a[i]);
    }

    int query(int a, int b) {
        a += n, b += n;

        int val = 0;

        while (a <= b) {
            if (a % 2 == 1) {
                if (dep[t[a]] < dep[val]) val = t[a]; a++;
            }

            if (b % 2 == 0) {
                if (dep[t[b]] < dep[val]) val = t[b]; b--;
            }

            a /= 2, b /= 2;
        }

        return val;
    }

    void set(int pos, const int val) {
        pos += n; t[pos] = val;

        for (pos /= 2; pos >= 1; pos /= 2) {
            t[pos] = t[2 * pos]; if (dep[t[2 * pos]] > dep[t[2 * pos + 1]]) t[pos] = t[2 * pos + 1];
        }
    }
};

void dfs(const int ver, const int par, vi& dep, const vvi& adj) {
    for (const int i : adj[ver]) if (i != par) dep[i] = dep[ver] + 1, dfs(i, ver, dep, adj);
}

void dfs(const int ver, const int par, int& pos, vi& tour, const vvi& adj) {
    tour[pos] = ver; for (const int i : adj[ver]) if (i != par) dfs(i, ver, ++pos, tour, adj), tour[++pos] = ver;
}

int main() {
    io

    int n, q; cin >> n >> q;

    vvi adj (n + 1); for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
    }

    vi dep (n + 1); dfs(1, -1, dep, adj); dep[0] = inf;

    int pos = 1; vi tour (2 * n + 1); dfs(1, -1, pos, tour, adj); tour.pop_back();

    vi r (n + 1); for (int i = 1; i < 2 * n; i++) if (!r[tour[i]]) r[tour[i]] = i;

    SEGTREE lca (tour, dep);

    for (int i = 1; i <= q; i++) {
        int u, v; cin >> u >> v; if (r[u] > r[v]) swap(u, v); cout << lca.query(r[u], r[v]) << "\n";
    }

    return 0;
}
