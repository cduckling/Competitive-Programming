#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
using namespace std;

#define pb(a) push_back(a)

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<bool> vb;
typedef set<int> si;

struct DSU {
    vi pars, sizes;

    DSU(const int n) : pars(n), sizes(n, 1) {
        for (int i = 0; i < n; i++) pars[i] = i;
    }

    int root(const int v) {
        return pars[v] == v ? v : (pars[v] = root(pars[v]));
    }

    void unite(const int u, const int v) {
        if (root(u) == root(v)) return;

        int U = root(u), V = root(v);

        if (sizes[U] < sizes[V]) swap(U, V);

        sizes[U] += sizes[V]; pars[V] = U;
    }

    bool connected(const int u, const int v) {
        return root(u) == root(v);
    }

    int size(const int v) {
        return sizes[root(v)];
    }
};

void solve() {
    int n, m; cin >> n >> m;

    vvi adj (n + 1); for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
    }

    vi rem (n + 1); for (int i = 1; i <= n; i++) cin >> rem[i];

    DSU dsu (n + 1);

    si dead; for (int i = 1; i <= n; i++) dead.insert(i); vb res (n + 1); for (int i = n; i >= 1; i--) {
        dead.erase(rem[i]); for (const int j : adj[rem[i]]) if (!dead.count(j)) dsu.unite(rem[i], j); res[i] = dsu.size(rem[i]) == n - i + 1;
    }

    for (int i = 1; i <= n; i++) cout << (res[i] ? "YES" : "NO") << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    freopen("closing.in", "r", stdin), freopen("closing.out", "w", stdout);

    solve();

    return 0;
}