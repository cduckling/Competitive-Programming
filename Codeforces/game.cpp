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

struct SEGTREE {
    vi Q; int N;

    SEGTREE(int n) {
        N = n; Q.assign(2 * n, 0);
    }

    SEGTREE(const vi& a) : SEGTREE(a.size()) {
        for (int i {0}; i < a.size(); i++) add(i, a[i]);
    }

    int query(int a, int b) {
        a += N, b += N;

        int val = 0;

        while (a <= b) {
            if (a % 2 == 1) val = max(val, Q[a++]);
            if (b % 2 == 0) val = max(val, Q[b--]);

            a /= 2; b /= 2;
        }

        return val;
    }

    void add(int pos, const int c) {
        pos += N; Q[pos] = c;

        for (pos /= 2; pos >= 1; pos /= 2) Q[pos] = max(Q[2 * pos], Q[2 * pos + 1]);
    }
};

void dfs(const int ver, const int par, vi& id, vi& pos, vi& size, const vvi& adj) {
    pos[ver] = id.size(), id.pb(ver);

    size[ver] = 1; for (const int i : adj[ver]) if (i != par) dfs(i, ver, id, pos, size, adj); for (const int i : adj[ver]) if (i != par) size[ver] += size[i];
}

void solve() {
    int n; cin >> n;

    vi w (n + 1); for (int i = 1; i <= n; i++) cin >> w[i];

    vvi adj (n + 1); for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }

    vi id (1), pos (n + 1), size (n + 1); dfs(1, -1, id, pos, size, adj);

    SEGTREE g (n + 1); for (int i = 1; i <= n; i++) g.add(pos[i], w[i]);

    int sol = 0, val = 0;

    for (int i = 1; i <= n; i++) {
        const int out = max(g.query(1, pos[i] - 1), g.query(pos[i] + size[i], n));
        if (out > w[i] && w[i] > val) sol = i, val = w[i];
    }

    cout << sol << "\n";
}

int main() {
    io
    tc

    return 0;
}