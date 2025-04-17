#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

int grid[101][101];
bool dp[101][101];

void solve() {
    int n {}, m {}; cin >> n >> m;

    for (int i {1}; i <= n; ++i) for (int j {1}; j <= m; ++j) cin >> grid[i][j];

    int div = gcd(grid[1][1], grid[n][m]); priority_queue<int> d {}; for (int i {1}; i * i <= div; ++i) if (!(div % i)) {
            d.push(i); d.push(div / i); }

    while (!d.empty()) {
        int divisor = d.top(); d.pop();

        dp[1][1] = true;

        for (int i {1}; i <= n; ++i) {
            for (int j {1}; j <= m; ++j) {
                if (i == 1 && j == 1) continue;

                dp[i][j] = dp[i - 1][j] | dp[i][j - 1];
                if (grid[i][j] % divisor) dp[i][j] = false;
            }
        }

        if (dp[n][m]) {
            cout << divisor << "\n"; return;
        }
    }
}

int main() {
    io
    tc

    return 0;
}