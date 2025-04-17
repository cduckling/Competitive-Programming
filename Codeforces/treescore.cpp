#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
using namespace std;

#define tc ll t; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(a) (a).begin(), (a).end()
#define pb(i) push_back(i)
#define eb(i) emplace_back(i)
#define ceil(a, b) ((a + b - 1) / b)
#define fail cout << -1 << "\n"; return;
#define inf (ll) 1e18

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

ll mod = 1e9 + 7;

ll modpow(ll b, ll e) {
    b %= mod; ll r = 1;

    while (e > 0) {
        if (e % 2 == 1) r = r * b % mod;

        b = b * b % mod;
        e /= 2;
    }

    return r;
}

void dfs(const ll ver, const ll par, vi& dp, const vvi& adj) {
    vi c; for (const ll i : adj[ver]) if (i != par) {
        c.pb(i); dfs(i, ver, dp, adj);
    }

    for (const ll i : c) dp[ver] = max(dp[ver], dp[i]); dp[ver]++;
}

void solve() {
    ll n; cin >> n;

    vvi adj (n + 1); for (ll i = 1; i < n; i++) {
        ll u, v; cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
    }

    vi dp (n + 1); dfs(1, 0, dp, adj);

    ll sum = 0; for (ll i = 1; i <= n; i++) sum += dp[i], sum %= mod;

    cout << (sum * modpow(2, n - 1) + mod) % mod << "\n";
}

int main() {
    io
    tc

    return 0;
}