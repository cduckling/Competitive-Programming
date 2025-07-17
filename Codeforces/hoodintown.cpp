#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    ll n {}; cin >> n;

    ll t = 0; vector<ll> a (n); for (ll i {0}; i < n; ++i) {
        cin >> a[i]; t += a[i];
    } sort(a.begin(), a.end()); if (n < 3) {
        cout << -1 << "\n"; return;
    }

    pair<ll, ll> x {0, 1e13};

    while (x.first != x.second) {
        ll mid = (x.first + x.second) / 2;

        ll l = 0; for (ll i : a) if ((i * n * 2) < (t + mid)) ++l;

        if ((n % 2 == 0 && l > n / 2) || (n % 2 != 0 && l >= (n + 1) / 2)) {
            x.second = mid;
        } else {
            x.first = mid + 1;
        }
    }

    cout << x.first << "\n";
}

int main() {
    io
    tc

    return 0;
}