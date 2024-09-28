#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

pair<ll, ll> intersection(pair<ll, ll> a, pair<ll, ll> b, ll r) {
    if (max(a.second, b.second) - min(a.first, b.first) < (a.second - a.first) + (b.second - b.first)) {
        return {max(a.first, b.first), min(a.second, b.second)};
    } else {
        ll k = ceil((b.first - a.second + 0.0) / r);

        return {max(a.first + k * r, b.first), min(a.second + k * r, b.second)};
    }
}

void solve() {
    ll n {}, k {}; cin >> n >> k;

    vector<ll> a (n); for (ll i {0}; i < n; ++i) cin >> a[i]; sort(a.begin(), a.end());

    pair<ll, ll> u {a[0], a[0] + k - 1};
    for (ll i {1}; i < n; ++i) {
        u = intersection(u, {a[i], a[i] + k - 1}, 2 * k);

        if (u.first > u.second) {
            cout << -1 << "\n"; return;
        }
    }

    cout << u.first << "\n";
}

int main() {
    io
    tc

    return 0;
}