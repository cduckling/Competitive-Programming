#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <cstdio>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

map<char, int> m {};

int main() {
    io

    freopen("hps.in", "r", stdin); freopen("hps.out", "w", stdout);

    int n {}, k {}; cin >> n >> k;

    m['H'] = 0; m['P'] = 1; m['S'] = 2;

    vector<char> g (n + 1); for (int i {1}; i <= n; ++i) cin >> g[i];

    vector<vector<array<int, 3>>> dp (n + 1, vector<array<int, 3>> (k + 1));

    for (int i {1}; i <= n; ++i) {
        dp[i][0] = dp[i - 1][0]; ++dp[i][0][m[g[i]]];

        for (int j {1}; j <= min(i - 1, k); ++j) {
            int t = max(dp[i - 1][j - 1][0], max(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]));

            dp[i][j][0] = max(dp[i - 1][j][0], t);
            dp[i][j][1] = max(dp[i - 1][j][1], t);
            dp[i][j][2] = max(dp[i - 1][j][2], t);

            ++dp[i][j][m[g[i]]];
        }
    }

    cout << max(dp[n][k][0], max(dp[n][k][1], dp[n][k][2]));

    return 0;
}