#include <iostream>
#include <vector>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define square(a) ((a) * (a))

typedef long long ll;
typedef pair<ll, ll> pii;

ll a = 0, b = 0; bool bipartite = true;

void dfs(ll ver, ll col, vector<ll>& c, const vector<vector<ll>>& adj) {
    if (c[ver]) {
        if (c[ver] != col) bipartite = false;
    } else {
        c[ver] = col; if (col == 1) {++a;} else {++b;} col = (col == 1 ? 2 : 1);

        for (ll i : adj[ver]) dfs(i, col, c, adj);
    }
}

void solve() {
    ll n {}; cin >> n;

    vector<pii> c (n); vector<ll> r (n); for (ll i {0}; i < n; ++i) cin >> c[i].first >> c[i].second >> r[i];

    vector<vector<ll>> adj (n); for (ll i {0}; i < n; ++i) for (ll j {i + 1}; j < n; ++j) if (square(r[i] + r[j]) == (square(c[i].first - c[j].first) + square(c[i].second - c[j].second))) {
        adj[i].push_back(j); adj[j].push_back(i);
    }

    vector<ll> color (n);

    for (ll i {0}; i < n; ++i) {
        if (color[i]) continue;

        bipartite = true; a = 0; a = b; dfs(i, 1, color, adj);

        if (bipartite && a != b) {
            cout << "YES\n"; return;
        }
    }

    cout << "NO\n";
}

int main() {
    io

    solve();

    return 0;
}