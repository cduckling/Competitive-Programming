#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<ll, ll> pii;

vector<ll> paths {};

void dfs(ll v, ll p, ll c, const vector<vector<pii>>& adj, vector<ll>& dp) {
    vector<ll> children {}; for (pii i : adj[v]) if (i.first != p) { children.push_back(i.first); dfs(i.first, v, c + i.second, adj, dp); }

    if (children.empty()) paths.push_back(c);
}

void solve() {
    ll n {}; cin >> n;

    ll tot {0};

    vector<vector<pii>> adj (n); for (ll i {1}; i < n; ++i) {
        ll a {}, b {}, c {}; cin >> a >> b >> c;

        --a; --b; tot += c;

        adj[a].emplace_back(b, c);
        adj[b].emplace_back(a, c);
    }

    vector<ll> dp (n); dfs(0, -1, 0, adj, dp);

    sort(paths.begin(), paths.end());

    ll q {}; cin >> q;

    for (ll i {0}; i < q; ++i) {
        ll Q {}; cin >> Q;

        ll j = lower_bound(paths.begin(), paths.end(), tot - Q) - paths.begin();

        if (paths[j] == Q) --j;

        cout << j << "\n";
    }
}

int main() {
    io

    solve();

    return 0;
}