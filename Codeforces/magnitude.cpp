#include <iostream>
#include <vector>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<ll, ll> pii;

ll mod = 998244353;

void solve() {
    ll n {}; cin >> n;

    vector<ll> a (n); for (ll i {0}; i < n; ++i) cin >> a[i];

    vector<pii> dp (n); dp[0] = {abs(a[0]), a[0]}; for (int i {1}; i < n; ++i) {
        dp[i].first = max(dp[i - 1].first + a[i], abs(dp[i - 1].second + a[i]));
        dp[i].second = dp[i - 1].second + a[i];
    }

    for (int i {0}; i < n; ++i) {
        if (dp[i].first == dp[i].second) dp[i].second = -2 * 1e16 - 1;
    }

    vector<pii> c (n); if (a[0] >= 0) {c[0].first = 2;} else {c[0].first = 1; c[0].second = 1;}
    for (int i {1}; i < n; ++i) {
        c[i].first = (dp[i].first == (dp[i - 1].first + a[i]) ? c[i - 1].first % mod : 0) +
                     (dp[i].first == abs(dp[i - 1].first + a[i]) ? c[i - 1].first % mod : 0) +
                     (dp[i].first == (dp[i - 1].second + a[i]) ? c[i - 1].second % mod : 0) +
                     (dp[i].first == abs(dp[i - 1].second + a[i]) ? c[i - 1].second % mod : 0);

        c[i].first %= mod;

        if (dp[i].second != static_cast<ll>(-2 * 1e16 - 1)) {
            c[i].second = (dp[i].second == (dp[i - 1].first + a[i]) ? c[i - 1].first % mod : 0) +
                         (dp[i].second == abs(dp[i - 1].first + a[i]) ? c[i - 1].first % mod : 0) +
                         (dp[i].second == (dp[i - 1].second + a[i]) ? c[i - 1].second % mod : 0) +
                         (dp[i].second == abs(dp[i - 1].second + a[i]) ? c[i - 1].second % mod : 0);

            c[i].second %= mod;
        }
    }

    cout << c[n - 1].first % mod << "\n";
}

int main() {
    io
    tc

    return 0;
}