#include <iostream>
#include <vector>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

bool f = true;

void dfs(ll vertice, ll cost, ll mid, const vector<ll>& v, const vector<vector<ll>>& adj) {
    if (!f) return;

    vector<ll> children {};

    if (cost > 1e9) f = false;

    for (ll i : adj[vertice]) {
        children.push_back(i);
    }

    if (children.empty()) {
        if ((v[vertice] - cost) < mid) f = false; return;
    }

    if (((v[vertice] - cost) >= mid )|| vertice == 1) {
        for (ll i : children) dfs(i, cost, mid, v, adj);
    } else {
        for (ll i : children) dfs(i, cost + (mid - (v[vertice] - cost)), mid, v, adj);
    }
}



void solve() {
    ll n {}; cin >> n;

    vector<ll> v (n + 1); for (ll i {1}; i <= n; ++i) cin >> v[i];
    vector<vector<ll>> adj (n + 1); for (ll i {2}; i <= n; ++i) {
        ll p {}; cin >> p;

        adj[p].push_back(i);
    }

    pair<ll, ll> r {0, 1e9};

    while (r.first != r.second) {
        ll mid = (r.first + r.second + 1) / 2;

        f = true; dfs(1, 0, mid, v, adj);

        if (f) {
            r.first = mid;
        } else {
            r.second = mid - 1;
        }
    }

    cout << v[1] + r.first << "\n";
}

int main() {
    io
    tc

    return 0;
}