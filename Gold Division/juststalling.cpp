#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    ll n {}; cin >> n;

    vector<ll> a (n); for (ll i {0}; i < n; ++i) {
        cin >> a[i];
    } sort(a.begin(), a.end(), greater<ll>());
    vector<ll> b (n); for (ll i {0}; i < n; ++i) {
        cin >> b[i];
    } sort(b.begin(), b.end(), greater<ll>());

    ll arrangements {1};

    for (ll i {0}; i < n; ++i) {
        ll o {0};

        for (ll j {i}; j < n; ++j) {
            if (b[j] >= a[i]) {
                ++o;
            } else {
                break;
            }
        }

        arrangements *= o;
    }

    cout << arrangements;
}