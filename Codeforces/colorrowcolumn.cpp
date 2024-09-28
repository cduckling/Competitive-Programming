#include <iostream>
#include <vector>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<ll, ll> pii;

ll m = 100000;

void solve() {
    ll n {}, k {}; cin >> n >> k;

    vector<pii> rects (n + 1); vector<ll> t (n + 1); for (ll i {1}; i <= n; ++i) {
        ll w {}, h {}; cin >> w >> h;

        rects[i] = {w, h};

        t[i] = w + h + t[i - 1];
    }

    vector<vector<ll>> dp (n + 1, vector<ll> (k + 2, m));

    for (ll i {0}; i <= n; ++i) {
        dp[i][0] = 0;
    }

    for (ll i {1}; i <= n; ++i) {
        for (ll j {1}; j <= min(k + 1, t[i]); ++j) {

            pii r = rects[i]; ll o = 0;

            dp[i][j] = dp[i - 1][j];

            for (ll p {1}; p <= t[i] - t[i - 1]; ++p) {
                if (p == t[i] - t[i - 1] && j - p >= 0) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - p] + o + 1);
                } else if (p == t[i] - t[i - 1] - 1 && j - p >= 0) {
                    ;
                } else {
                    o += min(r.first, r.second);

                    if (r.first < r.second) {
                        --r.second;
                    } else {
                        --r.first;
                    }

                    if (j - p >= 0) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j - p] + o);
                    } else {
                        break;
                    }
                }
            }
        }
    }

    if (min(dp[n][k], dp[n][k + 1]) == m) {
        cout << -1;
    } else {
        cout << min(dp[n][k], dp[n][k + 1]);
    }

    cout << "\n";
}

int main() {
    io
    tc

    return 0;
}