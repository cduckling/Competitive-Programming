#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    io

    freopen("time.in", "r", stdin); freopen("time.out", "w", stdout);

    int n {}, m {}, c {}; cin >> n >> m >> c;

    vector<int> moo (n + 1); for (int i {1}; i <= n; ++i) cin >> moo[i];

    vector<vector<int>> adj (n + 1); for (int i {0}; i < m; ++i) {
        int u {}, v {}; cin >> u >> v;

        adj[u].push_back(v);
    }

    vector<vector<int>> dp (2001, vector<int> (n + 1, -1));

    for (const int i : adj[1]) dp[1][i] = moo[i];

    for (int i {1}; i <= 1999; ++i) for (int j {1}; j <= n; ++j) if (dp[i][j] != -1) for (const int k : adj[j]) dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + moo[k]);

    int moonies {0}; for (int i {1}; i <= 2000; ++i) moonies = max(moonies, dp[i][1] - c * i * i); cout << moonies << "\n";

    return 0;
}