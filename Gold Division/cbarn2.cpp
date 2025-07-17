#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

ll dp[201][8];

void solve() {
    ll n {}, d {}; cin >> n >> d;

    vector<ll> r (2 * n + 1), pref (2 * n + 1); for (ll i {1}; i <= n; ++i) cin >> r[i]; for (ll i {n + 1}; i <= 2 * n; ++i) r[i] = r[i - n]; for (ll i {1}; i <= 2 * n; ++i) pref[i] = r[i] + pref[i - 1];

    ll dist = 1e18;

    for (ll i {1}; i <= n; ++i) {
        for (ll j {1}; j <= 2 * n; ++j) for (ll k {1}; k <= d; ++k) dp[j][k] = 0;

        for (ll j {i + 1}; j <= i + n - 1; ++j) {
            dp[j][1] = dp[j - 1][1] + r[j] * (j - i);

            for (ll k {2}; k <= min(d, j - i + 1); ++k) {
                dp[j][k] = dp[j - 1][k - 1];

                ll tot {0};

                for (ll l {j - 1}; l >= i + 1; --l) {
                    tot += pref[j] - pref[l];

                    dp[j][k] = min(dp[j][k], dp[l - 1][k - 1] + tot);
                }

            }
        }

        dist = min(dist, dp[i + n - 1][d]);
    }

    cout << dist << "\n";
}

int main() {
    io

    freopen("cbarn2.in", "r", stdin); freopen("cbarn2.out", "w", stdout);

    solve();

    return 0;
}