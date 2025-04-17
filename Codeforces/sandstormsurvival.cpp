#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define inf 1e18;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<vector<ll>> vii;
typedef set<ll> si;
typedef map<ll, ll> mii;
typedef map<ll, vector<ll>> miv;

void solve() {
    ll n {}; cin >> n;

    vi a (n + 1); for (ll i {1}; i <= n; ++i) cin >> a[i];

    vii dp (2, vi (n + 1));

    pii r {1, 1e18};

    while (r.first != r.second) {
        ll mid = (r.first + r.second) / 2;

        for (ll i {0}; i < 2; ++i) for (ll j {0}; j <= n; ++j) dp[i][j] = 0;

        dp[0][0] = mid, dp[1][0] = 2 * mid;

        for (ll i {1}; i <= n; ++i) {
            dp[0][i] = dp[0][i - 1] + a[i]; if (dp[0][i] <= 0) dp[0][i] = -inf;
            dp[1][i] = max(dp[1][i - 1] + a[i], 2 * (dp[0][i - 1] + a[i])); if (dp[1][i] <= 0) dp[1][i] = -inf;
        }

        if (dp[1][n] > 0) {
            r.second = mid;
        } else {
            r.first = mid + 1;
        }
    }

    cout << r.first;
}
int main() {
    io

    solve();

    return 0;
}