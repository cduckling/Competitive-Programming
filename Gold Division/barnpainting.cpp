#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

#define pb(i) push_back(i)

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;

constexpr ll mod = 1e9 + 7;

vi diff(const ll val) {
    switch (val) {
        case 0: return {1, 2, 3};
        case 1: return {2, 3};
        case 2: return {1, 3};
        case 3: return {1, 2};
    }
}

void dfs(const ll ver, const ll par, vvi& dp, const vi& col, const vvi& adj) {
    vi c; for (const ll i : adj[ver]) if (i != par) c.pb(i), dfs(i, ver, dp, col, adj);

    for (ll i = 1; i <= 3; i++) {
        if (col[ver] && i != col[ver]) dp[ver][i] = 0;

        for (const ll j : c) {
            ll sum = 0; for (const ll k : diff(i)) sum += dp[j][k], sum %= mod; dp[ver][i] *= sum, dp[ver][i] %= mod;
        }
    }
}

void solve() {
    ll n, k; cin >> n >> k;

    vvi adj (n + 1); for (ll i = 1; i < n; i++) {
        ll u, v; cin >> u >> v;
        adj[u].pb(v), adj[v].pb(u);
    }

    vi col (n + 1); for (ll i = 1; i <= k; i++) {
        ll b, c; cin >> b >> c; col[b] = c;
    }

    vvi dp (n + 1, vi (4, 1)); dfs(1, -1, dp, col, adj); cout << (dp[1][1] + dp[1][2] + dp[1][3] + mod) % mod << "\n";
}

int main() {
    freopen("barnpainting.in", "r", stdin), freopen("barnpainting.out", "w", stdout);

    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();

    return 0;
}