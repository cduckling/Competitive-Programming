#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

int main() {
    freopen("cowpatibility.in", "r", stdin); freopen("cowpatibility.out", "w", stdout);

    io

    ll n {}; cin >> n;

    map<set<ll>, ll> flavors {};

    for (ll i {0}; i < n; ++i) {
        vector<ll> f (5);

        for (ll j {0}; j < 5; ++j) {
            cin >> f[j];
        }
        for (ll j {1}; j <= 31; ++j) {
            set<ll> s {};

            for (ll k {0}; k <= 4; ++k) {
                if (j&(1<<k)) {
                    s.insert(f[k]);
                }
            }

            ++flavors[s];
        }
    }

    ll compatible {0};

    for (const auto& [flavor, cows] : flavors) {
        if (flavor.size() % 2 == 0) {
            compatible -= (cows * (cows - 1)) / 2;
        } else {
            compatible += (cows * (cows - 1)) / 2;
        }
    }

    cout << (n * (n - 1)) / 2 - compatible;
}