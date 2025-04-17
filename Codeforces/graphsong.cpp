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

#define tc ll t; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(a) (a).begin(), (a).end()
#define pb(i) push_back(i);
#define inf 1e18;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef tuple<ll, ll, ll> tiii;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<set<ll>> vsi;
typedef vector<pair<ll, ll>> vpii;
typedef vector<tuple<ll, ll, ll>> vtiii;
typedef vector<bool> vb;
typedef multiset<ll> msi;
typedef set<ll> si;
typedef set<pair<ll, ll>> spii;
typedef set<tuple<ll, ll, ll>> stiii;
typedef map<ll, ll> mi;
typedef map<ll, vector<ll>> mivi;
typedef map<ll, pair<ll, ll>> mipii;
typedef map<ll, bool> mib;

template <typename T>
void dfs(const ll ver, const ll col, vi& vis, const T& adj) {
    if (vis[ver]) return;

    vis[ver] = col; for (const ll i : adj[ver]) dfs(i, col, vis, adj);
}

void flood(const ll n, const vvi& adj, vsi& con) {
    vi vis (n); ll col = 0; for (ll i = 0; i < n; i++) if (!vis[i]) {
        col++; dfs(i, col, vis, adj);
    }

    con.resize(col); for (ll i = 0; i < n; i++) con[vis[i] - 1].insert(i);
}

void solve() {
    ll n, a, b; cin >> n >> a >> b;

    vsi f (n); for (ll i = 0; i < a; i++) {
        ll u, v; cin >> u >> v; u--; v--;

        f[u].insert(v); f[v].insert(u);
    }

    vvi g (n); for (ll i = 0; i < b; i++) {
        ll u, v; cin >> u >> v; u--; v--;

        g[u].pb(v); g[v].pb(u);
    }

    vsi con; flood(n, g, con);

    ll ops = 0;

    vpii rem;

    for (ll i = 0; i < con.size(); i++) for (const ll j : con[i]) for (const ll k : f[j]) if (!con[i].count(k)) rem.emplace_back(min(j, k), max(j, k));

    for (const auto i : rem) f[i.first].erase(i.second), f[i.second].erase(i.first);

    vi vis (n); ll col = 0; for (ll i = 0; i < n; i++) if (!vis[i]) {
        col++; dfs(i, col, vis, f);
    }

    for (ll i = 0; i < con.size(); i++) {
        si d;

        for (const ll j : con[i]) d.insert(vis[j]);

        ops += d.size() - 1;
    }

    cout << ops + rem.size() / 2 << "\n";
}

int main() {
    io
    tc

    return 0;
}