#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<ll, ll> pii;

int r = 20;

void dfs(ll v, ll p, const vector<vector<ll>>& adj, const vector<ll>& a, vector<vector<ll>>& dp) {
    vector<ll> children {}; for (ll i : adj[v]) if (i != p) { children.push_back(i); dfs(i, v, adj, a, dp); }

    for (ll i {1}; i < r; ++i) dp[v][i] = a[v] * i;

    if (!children.empty()) {
        for (ll c : children) {
            vector<pii> b {}; for (ll i {1}; i < r; ++i) b.emplace_back(dp[c][i], i); sort(b.begin(), b.end());
            
            for (ll i {1}; i < r; ++i) {
                dp[v][i] += b[0].first;

                if (b[0].second == i) {
                    dp[v][i] -= b[0].first; dp[v][i] += b[1].first;
                }
            }
        }
    }
}

void solve() {
    ll n {}; cin >> n;

    vector<ll> a (n); for (ll i {0}; i < n; ++i) cin >> a[i];

    vector<vector<ll>> adj (n); for (ll i {1}; i < n; ++i) {
        ll u {}, v {}; cin >> u >> v; --u; --v;
        adj[u].push_back(v); adj[v].push_back(u);
    }

    vector<vector<ll>> dp (n, vector<ll> (r)); dfs(0, -1, adj, a, dp);

    ll c = dp[0][1]; for (ll i {2}; i < r; ++i) c = min(c, dp[0][i]); cout << c << "\n";
}

int main() {
    io
    tc

    return 0;
}