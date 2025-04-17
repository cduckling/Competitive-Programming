#include <iostream>
#include <vector>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

ll m = 1e9 + 7;

ll modpow(ll b, ll e) {
    b %= m; ll r {1};
    while (e > 0) {
        if (e % 2 == 1) r = r * b % m;

        b = b * b % m;
        e /= 2;
    }

    return r;
}

void solve() {
    ll t {}; cin >> t;

    vector<ll> n (t), k (t); for (ll i {0}; i < t; ++i) cin >> n[i]; for (ll i {0}; i < t; ++i) cin >> k[i];

    for (ll i {0}; i < t; ++i) cout << modpow(2, k[i]) << "\n";
}

int main() {
    io

    solve();

    return 0;
}