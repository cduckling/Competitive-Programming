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

#define choose(a, b) ((fac[(a)] * modpow(fac[(b)], mod - 2)) % mod * modpow(fac[(a) - (b)], mod - 2) % mod)

ll mod = 1e9 + 7;

ll fac[1000001];

ll modpow(ll b, ll e) {
    b %= mod; ll r = 1;

    while (e > 0) {
        if (e % 2 == 1) r = r * b % mod;

        b = b * b % mod;
        e /= 2;
    }

    return r;
}

void dfs(const ll ver, const ll par, const ll n, const ll k, vi& dp, vi& size, const vvi& adj) {
    vi c; for (const ll i : adj[ver]) if (i != par) c.pb(i), dfs(i, ver, n, k, dp, size, adj);

    size[ver] = 1; for (const ll i : c) size[ver] += size[i]; if (size[ver] < k / 2 || n - size[ver] < k / 2) return;

    dp[ver] = choose(size[ver], k / 2) * choose(n - size[ver], k / 2) % mod;
}

void solve() {
    ll n, k; cin >> n >> k;

    vvi adj (n + 1); for (ll i = 1; i < n; i++) {
        ll u, v; cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
    } if (k % 2 != 0) {
        cout << 1 << "\n"; return;
    }

    vi dp (n + 1), size (n + 1); dfs(1, -1, n, k, dp, size, adj);

    ll sum = 0; for (ll i = 1; i <= n; i++) sum += dp[i], sum %= mod; cout << (sum * modpow(choose(n, k), mod - 2) % mod + 1 + mod) % mod << "\n";
}

int main() {
    io

    fac[0] = 1; for (ll i = 1; i <= 1000000; i++) fac[i] = fac[i - 1] % mod * (i % mod) % mod;

    solve();

    return 0;
}