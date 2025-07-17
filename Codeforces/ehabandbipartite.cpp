#include <iostream>
#include <vector>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void dfs(ll v, ll p, const vector<vector<ll>>& adj, vector<bool>& color) {
    vector<ll> c {}; for (ll i : adj[v]) if (i != p) c.push_back(i);

    for (ll i : c) color[i] = !color[v];
    for (ll i : c) dfs(i, v, adj, color);
}

void solve() {
    ll n {}; cin >> n;

    vector<vector<ll>> adj (n); for (ll i {1}; i < n; ++i) {
        ll u {}, v {}; cin >> u >> v; --u; --v;
        adj[u].push_back(v); adj[v].push_back(u);
    }

    vector<bool> color (n); dfs(0, -1, adj, color);

    ll r {0}, b {0}; for (bool i : color) {
        if (i) {
            ++r;
        } else {
            ++b;
        }
    }

    ll e {0};

    for (ll i {0}; i < n; ++i) {
        if (color[i]) {
            e += b - adj[i].size();
        } else {
            e += r - adj[i].size();
        }
    }

    cout << e / 2;
}

int main() {
    io

    solve();

    return 0;
}