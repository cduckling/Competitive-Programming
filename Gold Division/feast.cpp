#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

int main() {
    freopen("feast.in", "r", stdin); freopen("feast.out", "w", stdout);

    io

    ll t {}, a {}, b {}; cin >> t >> a >> b;

    vector<bool> dp (t + 1); dp[a] = true; dp[b] = true;
    for (ll i {1}; i <= t; ++i) {
        if (!dp[i]) continue;

        if (i + a <= t) dp[i + a] = true;
        if (i + b <= t) dp[i + b] = true;
    }

    vector<ll> f {}; for (ll i {1}; i <= t; ++i) {
        if (dp[i]) f.push_back(i);
    }

    ll fullness {f[f.size() - 1]};

    for (ll f_ : f) {
        if (upper_bound(f.begin(), f.end(), t - f_ / 2) != f.begin()) {
            ll i = upper_bound(f.begin(), f.end(), t - f_ / 2) - f.begin() - 1;
            fullness = max(fullness, f_ / 2 + f[i]);
        }
    }

    cout << fullness;

    return 0;
}