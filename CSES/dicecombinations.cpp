#include <iostream>
#include <vector>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

ll m = 1e9 + 7;

int main() {
    io

    ll n {}; cin >> n;

    vector<ll> dp (n + 1); dp[1] = 1; dp[2] = 1; dp[3] = 1; dp[4] = 1; dp[5] = 1; dp[6] = 1;

    for (ll i {1}; i <= n; ++i) {
        for (ll j {1}; j <= 6; ++j) {
            if (i - j >= 0) { dp[i] += dp[i - j]; dp[i] %= m; }
        }

        dp[i] %= m;
    }

    cout << dp[n];

    return 0;
}