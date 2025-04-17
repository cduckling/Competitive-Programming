#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef vector<vector<ll>> matrix;

void solve() {
    ll n {}; cin >> n;

    vector<ll> a (n); for (ll i {0}; i < n; ++i) {
        cin >> a[i];
    } sort(a.begin(), a.end());

    if (n == 1) {
        if (a[0] == 0) {
            cout << 0 << "\n\n";
        } else {
            cout << 1 << "\n" << a[0] << "\n";
        }
    } else {
        vector<ll> o {};

        for (ll i {0}; i < 40; ++i) {
            vector<ll> e {}; for (ll a_ : a) {
                if (a_ != 0) {
                    e.push_back(a_);
                }
            }

            if (e.empty()) {
                break;
            }

            if (e.size() > 1 && (e[0] % 2 != e[1] % 2)) {
                break;
            }

            pair<ll, ll> extrema {2147483647, 0};
            for (ll a_ : a) {
                extrema.first = min(extrema.first, a_); extrema.second = max(extrema.second, a_);
            }

            ll operation {(extrema.first + extrema.second) / 2}; o.push_back(operation);
            for (ll j {0}; j < n; ++j) {a[j] = abs(a[j] - operation);}
        }

        for (ll i : a) {
            if (i != 0) {
                cout << -1 << "\n"; return;
            }
        }

        cout << o.size() << "\n";

        for (ll i : o) {
            cout << i << " ";
        }

        cout << "\n";
    }
}

int main() {
    io
    tc

    return 0;
}