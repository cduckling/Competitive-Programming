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
#define inf 1e18
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
typedef vector<char> vc;
typedef vector<vector<char>> vvc;

struct DSU {
    vi pars, sizes;

    DSU(const ll n) : pars(n), sizes(n, 1) {
        for (ll i = 0; i < n; i++) pars[i] = i;
    }

    ll root(const ll v) {
        return pars[v] == v ? v : (pars[v] = root(pars[v]));
    }

    void unite(const ll u, const ll v) {
        if (root(u) == root(v)) return;

        ll U = root(u), V = root(v);

        if (sizes[U] < sizes[V]) swap(U, V);

        sizes[U] += sizes[V]; pars[V] = U;
    }

    bool connected(const ll u, const ll v) {
        return root(u) == root(v);
    }

    ll size(const ll v) {
        return sizes[v];
    }
};

void solve() {
    ll n, m; cin >> n >> m;

    vtiii wuv (m + 1); for (ll i = 1; i <= m; i++) cin >> get<1>(wuv[i]) >> get<2>(wuv[i]) >> get<0>(wuv[i]); sort(all(wuv));

    DSU g (n + 1);

    ll res = inf; vi low (n + 1, inf);

    for (ll i = 1; i <= m; i++) {
        const ll w = get<0>(wuv[i]), u = get<1>(wuv[i]), v = get<2>(wuv[i]);

        pii U = {g.root(u), g.size(g.root(u))}, V = {g.root(v), g.size(g.root(v))}; if (U.sec < V.sec) swap(U, V);

        low[U.fir] = min(min(low[U.fir], low[V.fir]), w); g.unite(u, v);

        res = min(res, (g.root(1) == g.root(n) ? low[g.root(1)] + w : static_cast<ll>(2 * inf + 1)));
    }

    cout << res << "\n";
}

int main() {
    io
    tc

    return 0;
}