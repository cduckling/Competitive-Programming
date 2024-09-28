#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    ll n {}, k {}, q {}; cin >> n >> k >> q;

    vector<ll> a (k + 1); for (ll i {1}; i <= k; ++i) cin >> a[i];
    vector<ll> b (k + 1); for (ll i {1}; i <= k; ++i) cin >> b[i];

    for (ll i {0}; i < q; ++i) {
        ll d {}; cin >> d;

        if (d == n) {
            cout << b[k] << " ";
        } else {
            ll j = upper_bound(a.begin(), a.end(), d) - a.begin() - 1;
            ll m = b[j] + ((d - a[j]) * (b[j + 1] - b[j])) / (a[j + 1] - a[j]);
            cout << m << " ";
        }
    }

    cout << "\n";
}

int main() {
    io
    tc

    return 0;
}