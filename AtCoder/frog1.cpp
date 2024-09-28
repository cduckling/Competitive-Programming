#include <iostream>
#include <vector>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

int main() {
    io

    ll n {}; cin >> n;

    vector<ll> a (n); for (ll i {0}; i < n; ++i) cin >> a[i];

    vector<ll> dp (n, -1); dp[0] = 0;
    for (ll i {0}; i < n; ++i) {
        if (dp[i + 1] == -1) dp[i + 1] = dp[i] + abs(a[i + 1] - a[i]); dp[i + 1] = min(dp[i + 1], dp[i] + abs(a[i + 1] - a[i]));
        if (dp[i + 2] == -1) dp[i + 2] = dp[i] + abs(a[i + 2] - a[i]); dp[i + 2] = min(dp[i + 2], dp[i] + abs(a[i + 2] - a[i]));
    }

    cout << dp[n - 1];

    return 0;
}