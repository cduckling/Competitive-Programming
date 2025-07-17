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

struct DSU {
    vi pars, sizes;

    DSU(const int n) : pars(n), sizes(n, 1) {
        for (int i = 0; i < n; i++) pars[i] = i;
    }

    int root(const int x) {
        return pars[x] == x ? x : (pars[x] = root(pars[x]));
    }

    void unite(const int a, const int b) {
        if (root(a) == root(b)) return;

        int A = root(a), B = root(b);

        if (sizes[A] < sizes[B]) swap(A, B);

        sizes[A] += sizes[B]; pars[B] = A;
    }

    bool connected(const int x, const int y) {
        return root(x) == root(y);
    }
};

struct SEGTREE {
    int n; vi t;

    SEGTREE(const int n) {
        this->n = n; t.assign(2 * n, 0);
    }

    SEGTREE(const vi& a) : SEGTREE(a.size()) {
        for (int i = 0; i < n; i++) set(i, a[i]);
    }

    int query(int a, int b) {
        a += n, b += n;

        int val = 0;

        while (a <= b) {
            if (a % 2 == 1) val = max(val, t[a++]);
            if (b % 2 == 0) val = max(val, t[b--]);

            a /= 2; b /= 2;
        }

        return val;
    }

    void set(int pos, const int val) {
        pos += n; t[pos] = val;

        for (pos /= 2; pos >= 1; pos /= 2) t[pos] = max(t[2 * pos], t[2 * pos + 1]);
    }
};

void solve() {
    int n, m, q; cin >> n >> m >> q;

    SEGTREE time (n + 1);

    vb b (n + 1);

    vi root (n + 2); for (int i = 1; i <= n; i++) root[i] = i;

    vvi s (n + 1); for (int i = 1; i <= n; i++) s[i].pb(i);

    DSU dsu (n + 1);

    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;

        int U = dsu.root(u), V = dsu.root(v); if (U == V) continue; dsu.unite(U, V);

        if (s[U].size() < s[V].size()) swap(U, V);

        for (const int j : s[V]) {
            s[U].pb(j);

            if (root[j - 1] == U && !b[j - 1]) time.set(j - 1, i), b[j - 1] = true;
            if (root[j + 1] == U && !b[j]) time.set(j, i), b[j] = true;

            root[j] = U;
        }

        s[V].clear();
    }

    for (int i = 1; i <= q; i++) {
        int l, r; cin >> l >> r;

        cout << time.query(l, r - 1) << " ";
    }

    cout << "\n";
}

int main() {
    io
    tc

    return 0;
}