#include <iostream>
#include <vector>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    ll n {}; cin >> n;

    vector<ll> a (n); for (ll i {0}; i < n; ++i) cin >> a[i];

    ll r {n};

    for (ll i {0}; i < n; ++i) {
        ll v = i; for (ll j {i + 1}; j < n; ++j) v += a[j] > a[i]; r = min(r, v);
    }

    cout << r << "\n";
}

int main() {
    io
    tc

    return 0;
}