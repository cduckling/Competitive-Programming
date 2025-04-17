#include <iostream>
#include <vector>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    ll m {}, s {}; cin >> m >> s;

    vector<ll> c (m + 1), h (m + 1); ll t {0}; for (ll i {1}; i <= m; ++i) {
        cin >> c[i] >> h[i]; t += h[i];
    }

    vector<vector<ll>> dp (m + 1, vector<ll> (t + 1, -1));

    dp[1][0] = 0; if (c[1] == 0) dp[1][h[1]] = 0;

    for (ll i {2}; i <= m; ++i) {
        for (ll j {0}; j <= t; ++j) {
            if (dp[i - 1][j] != -1) dp[i][j] = dp[i - 1][j] + s;
            if (j >= h[i] && dp[i - 1][j - h[i]] != -1 && dp[i - 1][j - h[i]] + s >= c[i]) dp[i][j] = max(dp[i][j], dp[i - 1][j - h[i]] + s - c[i]);
        }
    }

    ll hapiness {0}; for (ll i {1}; i <= t; ++i) hapiness = max(hapiness, (dp[m][i] != -1 ? i : -1)); cout << hapiness << "\n";
}

int main() {
    io
    tc

    return 0;
}