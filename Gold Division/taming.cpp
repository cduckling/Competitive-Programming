#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

ll dp[101][101];

void solve() {
    ll n {}; cin >> n;

    vector<ll> a (n + 1); for (ll i {1}; i <= n; ++i) cin >> a[i];

    for (ll i {1}; i <= n; ++i) {
        dp[i][1] = dp[i - 1][1] + (a[i] != i - 1);

        for (ll j {2}; j <= i; ++j) {
            dp[i][j] = 1e18;

            for (ll k {i}; k >= j; --k) {
                ll d {0}; for (ll u {k}; u <= i; ++u) if (a[u] != (u - k)) ++d;

                dp[i][j] = min(dp[i][j], dp[k - 1][j - 1] + d);
            }
        }
    }

    for (int i {1}; i <= n; ++i) cout << dp[n][i] << "\n";
}

int main() {
    io

    freopen("taming.in", "r", stdin); freopen("taming.out", "w", stdout);

    solve();

    return 0;
}