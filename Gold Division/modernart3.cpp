#include <iostream>
#include <vector>
using namespace std;

#define inf 1e9
#define pb(a) push_back(a)

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;

void solve() {
    int n; cin >> n;

    vi a (n + 1); for (int i = 1; i <= n; i++) cin >> a[i];

    vvi pos (n + 1); for (int i = 1; i <= n; i++) pos[a[i]].pb(i);

    vvi dp (n + 1, vi (n + 1, inf)); for (int i = 0; i <= n; i++) for (int j = 0; j < i; j++) dp[i][j] = 0;

    for (int i = n; i >= 1; i--) {
        dp[i][i] = 1;

        for (int j = i + 1; j <= n; j++) {
            dp[i][j] = dp[i][j - 1] + 1;

            for (const int k : pos[a[j]]) if (i <= k && k < j) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j - 1]);
        }
    }

    cout << dp[1][n] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();

    return 0;
}