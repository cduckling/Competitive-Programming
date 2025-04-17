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
#define inf (ll) 1e18
#define f first
#define s second

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

void dfs(const ll ver, const ll par, ll& val, vmii& dp, const vi& col, const vvi& adj) {
    vi c; for (const ll i : adj[ver]) if (i != par) c.pb(i), dfs(i, ver, val, dp, col, adj);

    for (const ll i : c) {
        if (dp[ver].size() < dp[i].size()) swap(dp[ver], dp[i]);

        for (const pii j : dp[i]) {
            if (j.f != col[ver]) val += dp[ver][j.f] * j.s;
            dp[ver][j.f] += j.s;
        }
    }

    val += dp[ver][col[ver]], dp[ver][col[ver]] = 1;
}

void solve() {
    ll n; cin >> n;

    vi col (n + 1); for (ll i = 1; i <= n; i++) cin >> col[i];

    vvi adj (n + 1); for (ll i = 1; i < n; i++) {
        ll u, v; cin >> u >> v;
        adj[u].pb(v); adj[v].pb(u);
    }

    vmii dp (n + 1); ll val = 0; dfs(1, 0, val, dp, col, adj);

    cout << val << "\n";
}

int main() {
    io
    tc

    return 0;
}