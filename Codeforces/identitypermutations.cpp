#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

ll combinations(ll n, ll k) {
    ll c {1};

    for (ll i {0}; i < k; ++i) {
        c *= (n - i);
    }

    for (ll i {1}; i <= k; ++i) {
        c /= i;
    }

    return c;
}

int main() {
    ll n {}, k {}; cin >> n >> k;

    ll identity {0};

    for (; k >= 0; --k) {
        vector<ll> a (k, 0);
        for (ll i {0}; i < k; ++i) {
            a[i] = i;
        }

        ll d {0};

        do {
            bool d_ {true};

           for (ll i {0}; i < k; ++i) {
               if (a[i] == i) {
                   d_ = false;
                   break;
               }
           }

           d += (d_) ? 1 : 0;
        } while (next_permutation(a.begin(), a.end()));

        identity += combinations(n, k) * d;
    }

    cout << identity;
}