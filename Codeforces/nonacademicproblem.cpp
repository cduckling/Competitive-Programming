#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define combo(n) (((n) * (n - 1)) / 2)

typedef long long ll;

void dfs(ll v, ll p, const vector<vector<ll>>& adj, vector<ll>& visited, vector<map<ll, ll>>& tree) {
    visited[v] = true;

    for (ll i : adj[v]) {
        if (i == p || !visited[i]) {
            tree[v][i] = 1;
            if (!visited[i]) dfs(i, v, adj, visited, tree);
        } else {
            if (!tree[i][v]) {
                tree[v][i] = -2;
            } else {
                tree[v][i] = -1;
            }
        }
    }
}

void dp(ll v, ll p, vector<map<ll, ll>>& tree, vector<ll>& bridge) {
    vector<ll> c {}; for (auto i : tree[v]) if (i.first != p && i.second == 1) {
            c.push_back(i.first);
            dp(i.first, v, tree, bridge);
    }

    for (auto i : tree[v]) bridge[v] += (i.second == -2);
    for (auto i : tree[v]) bridge[v] -= (i.second == -1);

    if (!c.empty()) for (ll i : c) bridge[v] += bridge[i];
}

void size(ll v, ll p, vector<map<ll, ll>>& tree, vector<ll>& s) {
    vector<ll> c {}; for (auto i : tree[v]) if (i.first != p && i.second == 1) {
        c.push_back(i.first);
        size(i.first, v, tree, s);
    }

    s[v] = 1;

    if (!c.empty()) for (ll i : c) s[v] += s[i];
}

void solve() {
    ll n {}, m {}; cin >> n >> m;

    vector<vector<ll>> adj (n); for (ll i {0}; i < m; ++i) {
        ll u {}, v {}; cin >> u >> v; --u; --v;
        adj[u].push_back(v); adj[v].push_back(u);
    }

    vector<map<ll, ll>> tree (n); vector<ll> visited (n); dfs(0, -1, adj, visited, tree);

    vector<ll> bridge (n); dp(0, -1, tree, bridge);

    vector<ll> s (n); size(0, -1, tree, s);

    ll c = combo(n); for (ll i {0}; i < n; ++i) if (!bridge[i]) c = min(c, combo(s[i]) + combo(n - s[i])); cout << c << "\n";
}

int main() {
    io
    tc

    return 0;
}