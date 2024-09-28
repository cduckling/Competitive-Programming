#include <iostream>
#include <vector>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<ll, ll> pll;

void dfs(ll v, ll p, vector<ll>& l, const vector<vector<ll>>& adj) {
    vector<ll> c {};

    for (ll i : adj[v]) {
        if (i == p) continue;
        c.push_back(i);
    }

    if (c.empty()) {
        l.push_back(v); return;
    }

    for (ll i : c) dfs(i, v, l, adj);
}

void solve() {
    ll n {}; cin >> n;

    vector<vector<ll>> adj (n); for (ll i {1}; i < n; ++i) {
        ll u {}, v {}; cin >> u >> v; --u; --v;

        adj[u].push_back(v); adj[v].push_back(u);
    }
    vector<ll> leaves {}; dfs(0, -1, leaves, adj);

    pll q, l;

    vector<char> v (n); for (ll i {0}; i < n; ++i) {
        cin >> v[i]; if (v[i] == '?') ++q.second;
    }

    for (ll i : leaves) {
        if (v[i] == '?') {
            ++q.first;
        } else if (v[i] == '0') {
            ++l.first;
        } else {
            ++l.second;
        }
    }

    ll s = 0;

    if (v[0] == '1') {
        s = l.first + (q.first + 1) / 2;
    } else if (v[0] == '0') {
        s = l.second + (q.first + 1) / 2;
    } else {
        if (l.first == l.second) {
            if ((q.second - q.first - 1) % 2 != 0) {
                s = l.first + (q.first + 1) / 2;
            } else {
                s = l.first + q.first / 2;
            }
        } else {
            s = max(l.first, l.second) + q.first / 2;
        }
    }

    cout << s << "\n";
}

int main() {
    io
    tc

    return 0;
}