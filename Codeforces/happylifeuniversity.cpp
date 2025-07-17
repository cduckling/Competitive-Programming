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

#define tc ll t; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(a) (a).begin(), (a).end()
#define pb(i) push_back(i)
#define eb(i) emplace_back(i)
#define inf 1e9
#define fir first
#define sec second

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<vector<vector<ll>>> vvvi;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<vector<vector<double>>> vvvd;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef pair<ll, ll> pii;
typedef vector<pair<ll, ll>> vpii;
typedef vector<vector<pair<ll, ll>>> vvpii;
typedef vector<vector<vector<pair<ll, ll>>>> vvvpii;
typedef tuple<ll, ll, ll> tiii;
typedef vector<tuple<ll, ll, ll>> vtiii;
typedef vector<vector<tuple<ll, ll, ll>>> vvtiii;
typedef vector<vector<vector<tuple<ll, ll, ll>>>> vvvtiii;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef set<ll> si;
typedef vector<set<ll>> vsi;
typedef vector<vector<set<ll>>> vvsi;
typedef set<pair<ll, ll>> spii;
typedef vector<set<pair<ll, ll>>> vspii;
typedef map<ll, ll> mii;
typedef map<ll, bool> mib;
typedef map<ll, double> mid;
typedef vector<map<ll, ll>> vmii;
typedef vector<map<ll, double>> vmid;
typedef vector<map<ll, bool>> vmib;

struct SEGTREE {
    ll n; vi t, lazy;

    SEGTREE(const ll n) {
        this->n = n; t.assign(4 * n, 0), lazy.assign(4 * n, 0);
    }

    SEGTREE(const vi& a) : SEGTREE(a.size()) {
        build(1, 0, n - 1, a);
    }

    void build(const ll k, const ll l, const ll r, const vi& a){
        if (l == r) {
            t[k] = a[l];
        } else {
            build(2 * k, l,  (l + r) / 2, a), build(2 * k + 1, (l + r) / 2 + 1, r, a);

            t[k] = max(t[2 * k], t[2 * k + 1]);
        }
    }

    void set(const ll l, const ll r, const ll val) {
        set(l, r, val, 1, 0, n - 1);
    }

    void set(const ll l, const ll r, const ll val, const ll k, const ll a, const ll b) {
        if (r < a || l > b) return;

        if (l <= a && b <= r) {
            apply(k, b - a + 1, val);
        } else {
            push(k, a, b);

            set(l, r, val, 2 * k, a, (a + b) / 2), set(l, r, val, 2 * k + 1, (a + b) / 2 + 1, b);

            t[k] = max(t[2 * k], t[2 * k + 1]);
        }
    }

    ll query(const ll l, const ll r) {
        return query(l, r, 1, 0, n - 1);
    }

    ll query(const ll l, const ll r, const ll k, const ll a, const ll b) {
        if (r < a || l > b) return -inf;

        if (l <= a && b <= r) return t[k];

        push(k, a, b);

        return max(query(l, r, 2 * k, a, (a + b) / 2), query(l, r, 2 * k + 1, (a + b) / 2 + 1, b));
    }

    void push(const ll k, const ll a, const ll b) {
        apply(2 * k, (a + b) / 2 - a + 1, lazy[k]), apply(2 * k + 1, b - (a + b) / 2, lazy[k]);

        lazy[k] = 0;
    }

    void apply(const ll k, const ll len, const ll val) {
        t[k] += val, lazy[k] += val;
    }
};

void dfs(const ll ver, const ll par, ll& pos, vi& tta, vi& size, vi& id, const vvi& adj) {
    tta[pos] = ver, id[ver] = pos, size[ver] = 1;

    for (const ll i : adj[ver]) if (i != par) dfs(i, ver, ++pos, tta, size, id, adj), size[ver] += size[i];
}

void dfs(const ll ver, const ll par, vvi& prev, vector<stack<ll>>& col, const vi& a, const vvi& adj) {
    const ll PREV = col[a[ver]].empty() ? 0 : col[a[ver]].top(); col[a[ver]].push(ver); if (PREV) prev[PREV].pb(ver);

    for (const ll i : adj[ver]) if (i != par) dfs(i, ver, prev, col, a, adj); col[a[ver]].pop();
}

void dfs(const ll ver, const ll par, ll& res, const vvi& prev, const vi& a, const vvi& adj, SEGTREE& diff, const vi& id, const vi& size) {
    vi c; for (const ll i : adj[ver]) if (i != par) c.pb(i), dfs(i, ver, res, prev, a, adj, diff, id, size);

    if (c.empty()) {
        res = max(res, 1ll); diff.set(id[ver], id[ver], 1);
    } else {
        diff.set(id[ver], id[ver] + size[ver] - 1, 1); for (const ll i : prev[ver]) diff.set(id[i], id[i] + size[i] - 1, -1);

        vi use; for (const ll i : c) use.pb(diff.query(id[i], id[i] + size[i] - 1)); sort(all(use), greater<ll>());

        if (use.size() >= 2) res = max(res, use[0] * use[1]); res = max(res, use[0]);
    }
}

void solve() {
    ll n; cin >> n;

    vvi adj (n + 1); for (ll i = 2; i <= n; i++) {
        ll p; cin >> p;
        adj[i].pb(p), adj[p].pb(i);
    }

    vi a (n + 1); for (ll i = 1; i <= n; i++) cin >> a[i];

    vi tta (n + 1), size (n + 1), id (n + 1); ll pos = 1; dfs(1, 0, pos, tta, size, id, adj);

    vvi prev (n + 1); vector<stack<ll>> col (n + 1); dfs(1, 0, prev, col, a, adj);

    ll res = 0; SEGTREE diff (n + 1); dfs(1, 0, res, prev, a, adj, diff, id, size);

    cout << res << "\n";
}

int main() {
    io
    tc

    return 0;
}