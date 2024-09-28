#include <iostream>
#include <cstdio>
using namespace std;

int s[10001];
int dp[10001];

int main() {
    freopen("teamwork.in", "r", stdin); freopen("teamwork.out", "w", stdout);

    int n {}, k {}; cin >> n >> k;

    for (int i {1}; i <= n; ++i) cin >> s[i];

    dp[1] = s[1]; for (int i {2}; i <= n; ++i) {
        int r = 0;

        for (int j {1}; j <= k; ++j) {
            if (i - j < 0) continue;

            r = max(r, s[i - j + 1]); dp[i] = max(dp[i], dp[i - j] + r * j);
        }
    }

    cout << dp[n];

    return 0;
}