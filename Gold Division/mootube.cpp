#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <cstdio>
using namespace std;

#define eb(a, b) emplace_back(a, b)
#define all(a) (++(a).begin()), (a).end()

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<pair<int, int>>> vvpii;
typedef tuple<int, int, int> tiii;
typedef vector<tuple<int, int, int>> vtiii;

struct DSU {
    vi pars, sizes;

    DSU(const int n) : pars(n), sizes(n, 1) {
        for (int i = 0; i < n; i++) pars[i] = i;
    }

    int root(const int ver) {
        return pars[ver] == ver ? ver : (pars[ver] = root(pars[ver]));
    }

    void unite(const int a, const int b) {
        if (root(a) == root(b)) return;

        int A = root(a), B = root(b);

        if (sizes[A] < sizes[B]) swap(A, B);

        sizes[A] += sizes[B]; pars[B] = A;
    }

    int size(const int ver) {
        return sizes[root(ver)];
    }

    bool connected(const int x, const int y) {
        return root(x) == root(y);
    }
};

void solve() {
    int n, q; cin >> n >> q;

    vtiii ruv (n); for (int i = 1; i < n; i++) {
        int u, v, r; cin >> u >> v >> r;
        ruv[i] = make_tuple(r, u, v);
    } sort(all(ruv));

    vtiii kvi (q + 1); for (int i = 1; i <= q; i++) {
        int k, v; cin >> k >> v; kvi[i] = make_tuple(k, v, i);
    } sort(all(kvi), greater<tiii>());

    DSU adj (n + 1);

    vi res (q + 1); for (int i = 1; i <= q; i++) {
        while (!ruv.empty() && get<0>(ruv[ruv.size() - 1]) >= get<0>(kvi[i])) adj.unite(get<1>(ruv[ruv.size() - 1]), get<2>(ruv[ruv.size() - 1])), ruv.pop_back();

        res[get<2>(kvi[i])] = adj.size(get<1>(kvi[i])) - 1;
    }

    for (int i = 1; i <= q; i++) cout << res[i] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    freopen("mootube.in", "r", stdin), freopen("mootube.out", "w", stdout);

    solve();

    return 0;
}