#include <iostream>
using namespace std;

typedef long long ll;

ll modpow(ll a, ll b, ll m) {
    if (b == 0) {
        return 1;
    } else if (b % 2 == 0) {
        return ((modpow(a, b / 2, m) % m) * (modpow(a, b / 2, m) % m)) % m;
    } else {
        return ((modpow(a, b - 1, m) % m) * (a % m)) % m;
    }
}

int main() {
    int t {}; cin >> t;

    while (t--) {
        ll a, b, c; cin >> a >> b >> c;

        ll p = modpow(b, c, 1e9 + 6);
        ll q = modpow(a, p, 1e9 + 7);

        cout << q << '\n';
    }
}