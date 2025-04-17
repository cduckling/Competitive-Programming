#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<ll, ll> pii;

ll sqrt(const ll& n) {
    pair<ll, ll> r {0, 1e10};

    while (r.first != r.second) {
        ll mid = (r.first + r.second + 1) / 2;

        if (mid * mid <= n) {
            r.first = mid;
        } else {
            r.second = mid - 1;
        }
    }

    return r.first;
}

void solve() {
    ll k {}; cin >> k;

    vector<ll> a (k); for (ll i {0}; i < k; ++i) cin >> a[i];

    map<ll, ll> m {}; for (ll i : a) ++m[i];

    for (ll i {1}; i <= sqrt(k - 2); ++i) {
        if ((k - 2) % i != 0) continue;

        if ((k - 2) == i * i) {
            if (m[i] >= 2) {
                cout << i << " " << i << "\n"; return;
            }
        } else {
            if (m[(k - 2) / i] >= 1 && m[i] >= 1) {
                cout << (k - 2) / i << " " << i << "\n"; return;
            }
        }
    }
}

int main() {
    io
    tc

    return 0;
}