#include <iostream>
#include <vector>
#include <tuple>
#include <cstdio>
using namespace std;

#define inf 1e9
#define pb(a) push_back(a)
#define eb(a, b, c) emplace_back(a, b, c)

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef tuple<int, int, int> tiii;
typedef vector<tuple<int, int, int>> vtiii;
typedef vector<vector<tuple<int, int, int>>> vvtiii;
typedef vector<bool> vb;

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

void dfs(const int ver, const int par, vb& h, vvi& col, const vi& dep, const vi& t, const vvtiii& req, const vvi& adj) {
    col[t[ver]].pb(dep[ver]);

    for (const tiii i : req[ver]) if (!col[get<1>(i)].empty() && col[get<1>(i)][col[get<1>(i)].size() - 1] >= get<0>(i)) h[get<2>(i)] = true;

    for (const int i : adj[ver]) if (i != par) dfs(i, ver, h, col, dep, t, req, adj);

    col[t[ver]].pop_back();
}

void solve() {
    int n, q; cin >> n >> q;

    vi t (n + 1); for (int i = 1; i <= n; i++) cin >> t[i];

    vvi adj (n + 1); for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
    }

    vi dep (n + 1); dfs(1, -1, dep, adj); dep[0] = inf;

    int pos = 1; vi tour (2 * n + 1); dfs(1, -1, pos, tour, adj); tour.pop_back();

    vi r (n + 1); for (int i = 1; i < 2 * n; i++) if (!r[tour[i]]) r[tour[i]] = i;

    SEGTREE lca (tour, dep);

    vb h (q + 1); vvtiii req (n + 1);

    for (int i = 1; i <= q; i++) {
        int u, v; cin >> u >> v; if (r[u] > r[v]) swap(u, v); const int LCA = lca.query(r[u], r[v]); int c; cin >> c;

        req[u].eb(dep[LCA], c, i), req[v].eb(dep[LCA], c, i);
    }

    vvi col (n + 1); dfs(1, -1, h, col, dep, t, req, adj);

    for (int i = 1; i <= q; i++) cout << h[i]; cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    freopen("milkvisits.in", "r", stdin), freopen("milkvisits.out", "w", stdout);

    solve();

    return 0;
}