#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n {}, w {}; cin >> n >> w;

    vector<int> c (n); for (int i {0}; i < n; ++i) {
        cin >> c[i];
    } sort(c.begin(), c.end());

    vector<int> dp (w + 1, 2147483647); for (int coin : c) {
        dp[coin] = 1;
    }

    for (int i {1}; i <= w; ++i) {
        if (dp[i] == 2147483647) continue;

        for (int coin : c) {
            if (i + coin > w) break;

            dp[i + coin] = min(dp[i] + 1, dp[i + coin]);
        }
    }

    cout << dp[w];
}