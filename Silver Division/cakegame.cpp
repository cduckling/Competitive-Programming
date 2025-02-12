#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

void solve() {
    ll n {}; cin >> n;

    vector<ll> a (n + 1); for (ll i {1}; i <= n; ++i) cin >> a[i];

    vector<ll> pref (n + 1); for (ll i {1}; i <= n; ++i) pref[i] = pref[i - 1] + a[i];

    ll elsie = 0; for (ll i = n / 2 + 1; i <= n; ++i) elsie = max(elsie, pref[n] - (pref[i] - pref[i - n / 2 - 1]));

    cout << pref[n] - elsie << " " << elsie << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    ll t {}; cin >> t; while (t--) solve();

    return 0;
}