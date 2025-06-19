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

void solve() {
    ll n, m, l; cin >> n >> m >> l;

    vi a (l + 1); for (ll i = 1; i <= l; i++) cin >> a[i];

    ll sum = 0, use = inf; for (ll i = 1; i <= l; i++) {
        sum += a[i]; if (a[i] % 2 != 0) use = min(use, a[i]);
    }

    ll even = 0, odd = 0;

    if (sum % 2 == 0) {
        even = sum; if (use < inf) odd = sum - use;
    } else {
        odd = sum; if (use < inf) even = sum - use;
    }

    vvi adj (n + 1); for (ll i = 0; i < m; i++) {
        ll u, v; cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
    }

    vvb vis (2, vb (n + 1)); vvi dist (2, vi (n + 1, inf));

    queue<pii> q; q.emplace(1, 0); dist[0][1] = 0, vis[0][1] = true;

    while (!q.empty()) {
        const ll ver = q.front().fir; ll p = (q.front().sec + 1) % 2 ; q.pop();

        for (const ll i : adj[ver]) if (!vis[p][i]) {
            dist[p][i] = dist[(p + 1) % 2][ver] + 1, vis[p][i] = true;
            q.emplace(i, p);
        }
    }

    //for (ll i = 1; i <= n; i++) cout << dist[0][i] << " "; cout << "\n";
    //for (ll i = 1; i <= n; i++) cout << dist[1][i] << " "; cout << "\n";

    for (ll i = 1; i <= n; i++) cout << (dist[0][i] <= even || dist[1][i] <= odd); cout << "\n";
}

int main() {
    io
    tc

    return 0;
}