#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n {}, w {}; cin >> n >> w;

    pair<int, int> items[n]; for (int i {0}; i < n; ++i) {
        cin >> items[i].first >> items[i].second;
    }

    int dp[n + 1][w + 1]; for (int i {0}; i <= w; ++i) dp[0][i] = 0;
    for (int i {1}; i <= n; ++i) {
        for (int j {0}; j <= w; ++j) dp[i][j] = dp[i - 1][j];

        for (int j {0}; j <= w; ++j) {
            if (j >= items[i - 1].first) dp[i][j] = max(dp[i][j], dp[i - 1][j - items[i - 1].first] + items[i - 1].second);
        }
    }

    cout << dp[n][w];
}