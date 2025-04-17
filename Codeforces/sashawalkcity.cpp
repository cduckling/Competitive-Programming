#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb(i) push_back(i);
#define inf 1e18;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef tuple<ll, ll, ll> tiii;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<pair<ll, ll>> vpii;
typedef vector<tuple<ll, ll, ll>> vtiii;
typedef vector<bool> vb;
typedef multiset<ll> msi;
typedef set<ll> si;
typedef map<ll, ll> mi;
typedef map<ll, vector<ll>> mvi;
typedef map<ll, pair<ll, ll>> mpii;
typedef map<ll, bool> mb;

ll mod = 998244353;

void sub(const ll& ver, const ll& par, vi& anc, const vvi& adj) {
    vi c {}; for (ll i : adj[ver]) if (i != par) {
        c.pb(i); sub(i, ver, anc, adj);
    }

    if (c.empty()) {
        anc[ver] = 1; return;
    }

    anc[ver] = 1; for (ll i : c) anc[ver] *= anc[i] + 1 % mod, anc[ver] %= mod;
}

void dfs(const ll& ver, const ll& par, vi& dp, const vi& anc, const vvi& adj) {
    vi c {}; for (ll i : adj[ver]) if (i != par) {
        c.pb(i); dfs(i, ver, dp, anc, adj);
    }

    if (c.empty()) {
        dp[ver] = 1; return;
    }

    ll b = 1; for (ll i : c) b += anc[i] % mod, b %= mod;

    dp[ver] += b % mod, dp[ver] %= mod;

    for (ll i : c) dp[ver] += dp[i] % mod, dp[ver] %= mod;

    ll w = 1;

    for (ll i : c) w *= anc[i] + 1 % mod, w %= mod;
    for (ll i : c) w -= anc[i] % mod, w %= mod;

    --w;

    dp[ver] += w % mod, dp[ver] %= mod;
}

void solve() {
    ll n {}; cin >> n;

    vvi adj (n); for (ll i {1}; i < n; ++i) {
        ll u, v; cin >> u >> v; --u; --v;
        adj[u].pb(v); adj[v].pb(u);
    }

    vi anc (n); sub(0, -1, anc, adj);
    vi dp (n); dfs(0, -1, dp, anc, adj);

    cout << ((dp[0] % mod + mod) % mod + 1) % mod << "\n";
}

int main() {
    io
    tc

    return 0;
}