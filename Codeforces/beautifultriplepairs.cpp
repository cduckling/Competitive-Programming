#include <iostream>
#include <vector>
#include <map>
#include <array>
#include <algorithm>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    ll n {}; cin >> n;

    vector<ll> a (n); for (ll i {0}; i < n; ++i) cin >> a[i];

    map<array<ll, 3>, ll> m {}; for (ll i {0}; i < n - 2; ++i) {
        ll x = a[i], y = a[i + 1], z = a[i + 2];

        ++m[{0, y, z}]; ++m[{x, 0, z}]; ++m[{x, y, 0}]; ++m[{x, y, z}];
    }

    ll p {0};

    for (ll i {0}; i < n - 2; ++i) {
        p += m[{0, a[i + 1], a[i + 2]}] + m[{a[i], 0, a[i + 2]}] + m[{a[i], a[i + 1], 0}];
        p -= 3 * m[{a[i], a[i + 1], a[i + 2]}];
    }

    cout << p / 2 << "\n";
}

int main() {
    io
    tc

    return 0;
}