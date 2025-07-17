#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

int main() {
    io freopen("talent.in", "r", stdin); freopen("talent.out", "w", stdout);

    ll n {}, w {}, t {0}; cin >> n >> w;

    ll weight[n + 1]; ll talent[n + 1]; for (ll i {1}; i <= n; ++i) {
        cin >> weight[i] >> talent[i]; t += talent[i];
    }

    ll dp[2][t + 1]; for (int i {0}; i <= t; ++i) {
        dp[0][i] = -1; dp[1][i] = -1;
    }

    dp[0][0] = 0;

    for (ll i {1}; i <= n; ++i) {
        for (ll j {0}; j <= t; ++j) {
            ll p {dp[0][j]}, q {-1};

            if (j >= talent[i]) {
                if (dp[0][j - talent[i]] != -1) q = dp[0][j - talent[i]] + weight[i];
            }

            if (p == -1 && q == -1) {
                dp[1][j] = -1;
            } else if (p == -1) {
                dp[1][j] = q;
            } else if (q == -1) {
                dp[1][j] = p;
            } else {
                dp[1][j] = min(p, q);
            }
        }

        for (int j {0}; j <= t; ++j) {
            dp[0][j] = dp[1][j];
            dp[1][j] = -1;
        }
    }

    ll r {0};

    for (ll i {0}; i <= t; ++i) {
        if (dp[0][i] < w || dp[0][i] == -1) continue;

        r = max(r, ((1000 * i) / dp[0][i]));
    }

    cout << r;

    return 0;
}