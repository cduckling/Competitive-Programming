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
#define pb(a) push_back(a)
#define eb(a, b) emplace_back(a, b)
#define inf (ll) 1e18
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

void dfs(const ll ver, const ll par, ll& cost, vsi& col, vsi& bad, const vi& w, vi& c, const vvi& adj) {
    vi child; for (const ll i : adj[ver]) if (i != par) child.pb(i), dfs(i, ver, cost, col, bad, w, c, adj);

    si s; for (const ll i : child) {
        if (col[ver].size() < col[i].size()) swap(col[ver], col[i]);

        for (const ll j : col[i]) {
            if (col[ver].count(j)) s.insert(j); col[ver].insert(j);
        }
    }

    if (c[ver]) col[ver].insert(c[ver]);

    if (c[ver]) {
        for (const ll i : child) for (const ll j : bad[i]) c[j] = c[ver];

        s.erase(c[ver]); if (s.empty()) cost -= w[ver];
    } else {
        if (col[ver].empty()) {
            bad[ver].insert(ver); for (const ll i : child) {
                if (bad[ver].size() < bad[i].size()) swap(bad[ver], bad[i]);

                for (const ll j : bad[i]) bad[ver].insert(j);
            }

            cost -= w[ver];
        } else {
            c[ver] = s.empty() ? *col[ver].begin() : *s.begin();

            if (s.size() <= 1) cost -= w[ver];

            for (const ll i : child) for (const ll j : bad[i]) c[j] = c[ver];
        }
    }
}

void solve() {
    ll n, k; cin >> n >> k;

    vi w (n + 1), c (n + 1); for (ll i = 1; i <= n; i++) cin >> w[i]; for (ll i = 1; i <= n; i++) cin >> c[i];

    vvi adj (n + 1); for (ll i = 2; i <= n; i++) {
        ll u, v; cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
    }

    ll cost = 0; for (ll i = 1; i <= n; i++) cost += w[i];

    vsi col (n + 1), bad (n + 1); dfs(1, 0, cost, col, bad, w, c, adj);

    if (!bad[1].empty()) {
        cost = 0; for (ll i = 1; i <= n; i++) c[i] = 1;
    }

    cout << cost << "\n"; for (ll i = 1; i <= n; i++) cout << c[i] << " "; cout << "\n";
}

int main() {
    io
    tc

    return 0;
}