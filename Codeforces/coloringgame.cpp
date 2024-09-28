#include <iostream>
#include <vector>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}

typedef long long ll;

bool bipartite = true;

void dfs(ll node, ll color, vector<ll>& visited, const vector<vector<ll>>& adj) {
    if (visited[node] == 0) {
        visited[node] = color;

        if (color == 1) {
            color = 2;
        } else {
            color = 1;
        }

        for (ll i : adj[node]) {
            dfs(i, color, visited, adj);
        }
    } else if (visited[node] == color) {
        return;
    } else {
        bipartite = false; return;
    }
}

void solve() {
    ll n {}, m {}; cin >> n >> m;

    vector<vector<ll>> adj (n); for (ll i {0}; i < m; ++i) {
        ll a {}, b {}; cin >> a >> b; --a; --b;
        adj[a].push_back(b); adj[b].push_back(a);
    }

    bipartite = true; vector<ll> visited (n); dfs(0, 1, visited, adj);

    cout << (bipartite ? "Bob" : "Alice") << endl;

    if (bipartite) {
        vector<ll> _1 {}, _2 {}; for (ll i {0}; i < n; ++i) {
            (visited[i] == 1 ? _1 : _2).push_back(i + 1);
        }

        for (ll i {0}; i < n; ++i) {
            ll a {}, b {}; cin >> a >> b;

            if ((a == 1 || b == 1) && !_1.empty()) {
                cout << _1[0] << " " << 1 << endl;
                _1.erase(_1.begin());
            } else if ((a == 2 || b == 2) && !_2.empty()) {
                cout << _2[0] << " " << 2 << endl;
                _2.erase(_2.begin());
            } else {
                if (!_1.empty()) {
                    cout << _1[0] << " " << 3 << endl;
                    _1.erase(_1.begin());
                } else {
                    cout << _2[0] << " " << 3 << endl;
                    _2.erase(_2.begin());
                }
            }
        }
    } else {
        for (ll i {0}; i < n; ++i) {
            cout << 1 << " " << 2 << endl;
            ll v {}, c {}; cin >> v >> c;
        }
    }

    cout << endl;
}

int main() {
    tc

    return 0;
}