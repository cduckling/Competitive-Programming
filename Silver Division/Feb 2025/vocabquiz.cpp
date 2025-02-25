#include <iostream>
#include <vector>
using namespace std;

#define pb(i) push_back(i)

typedef vector<int> vi;

vi adj[1000001]; int par[1000001], dp[1000001], dep[1000001]; int m;

void dfs(const int ver, const int par) {
    vi c; for (const int i : adj[ver]) if (i != par) c.pb(i);

    if (c.empty()) dp[ver] = 1, m++; if (par != -1) dep[ver] = dep[par] + 1;

    for (const int i : c) dfs(i, ver);

    for (const int i : c) dp[ver] += dp[i];
}

void solve() {
    int n; cin >> n;

    for (int i = 0; i <= n; i++) adj[i].clear(), par[i] = 0, dp[i] = 0, dep[i] = 0; m = 0;

    for (int i = 1; i <= n; i++) {
        int p; cin >> p; adj[p].pb(i), adj[i].pb(p); par[i] = p;
    }

    dfs(0, -1);

    for (int i = 0; i < m; i++) {
        int w; cin >> w;

        int ver = par[w], r = dep[w]; while (ver != 0 && dp[ver] == 1) r--, ver = par[ver]; if (dp[0] == 1) r--;

        ver = w; while (ver != 0) dp[ver]--, ver = par[ver]; dp[0]--;

        cout << r << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();

    return 0;
}