#include <iostream>
#include <vector>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    ll n {}; cin >> n;

    vector<ll> s (n - 1), j (n - 2); for (ll i {0}; i < n - 1; ++i) cin >> s[i]; for (ll i {0}; i < n - 2; ++i) cin >> j[i];

    vector<ll> dp (n); dp[0] = 0; dp[1] = s[0];

    for (ll i {2}; i < n; ++i) {
        dp[i] = min(dp[i - 1] + s[i - 1], dp[i - 2] + j[i - 2]);
    }

    cout << dp[n - 1] << "\n";
}

int main() {
    io
    tc

    return 0;
}