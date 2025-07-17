#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

int main() {
    io

    freopen("snakes.in", "r", stdin); freopen("snakes.out", "w", stdout);

    int n {}, k {}; cin >> n >> k;

    vector<int> a (n + 1); for (int i {1}; i <= n; ++i) cin >> a[i];

    vector<vector<int>> dp (n + 1, vector<int> (k + 1));

    int m {a[1]}, p {a[1]};

    for (int i {2}; i <= n; ++i) {

        m = max(m, a[i]); p += a[i];
        dp[i][0] = m * i - p;

        for (int j {1}; j <= k; ++j) {
            int g {0}, t {0};

            for (int q {0}; q < i; ++q) {
                g = max(g, a[i - q]); t += a[i - q];
                if (q == 0) dp[i][j] = g * (q + 1) - t + dp[i - q - 1][j - 1];
                dp[i][j] = min(dp[i][j], g * (q + 1) - t + dp[i - q - 1][j - 1]);
            }

        }
    }

    cout << dp[n][k];

    return 0;
}