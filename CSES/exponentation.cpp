#include <iostream>
using namespace std;

typedef long long ll;

ll m = 1e9 + 7;

ll modpow(ll a, ll b) {
    if (b == 0) {
        return 1;
    } else if (b % 2 == 0) {
        return ((modpow(a, b / 2) % m) * (modpow(a, b / 2) % m)) % m;
    } else {
        return ((modpow(a, b - 1) % m) * (a % m)) % m;
    }
}

int main() {
    ll t {}; cin >> t;

    while (t--) {
        ll a {}, b {}; cin >> a >> b;
        cout << modpow(a, b) << "\n";
    }
}