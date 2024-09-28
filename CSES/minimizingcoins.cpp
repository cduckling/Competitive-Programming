#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

int main() {
    io

    ll k {}, n {}; cin >> k >> n;

    vector<ll> a (k); for (ll i {0}; i < k; ++i) cin >> a[i];

    if (a[0] == 1000000) {cout << -1; return 0;}

    vector<ll> dp (n + 1, LONG_LONG_MAX); for (ll i : a) dp[i] = 1;

    for (ll i {1}; i <= n; ++i) {
        if (dp[i] == LONG_LONG_MAX) continue;

        for (ll j : a) { if (i + j <= n) { dp[i + j] = min(dp[i] + 1, dp[i + j]); }}
    }

    cout << (dp[n] != LONG_LONG_MAX ? dp[n] : -1);

    return 0;
}