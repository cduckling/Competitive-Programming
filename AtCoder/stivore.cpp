#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll m = 1e9 + 7;
ll factorials[2000001];
ll inverses[2000001];

ll inverse(ll x) {
    return x <= 1 ? x : m - m / x * inverse(m % x) % m;
}

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
    factorials[0] = 1; for (ll i {1}; i <= 2000000; ++i) {
        factorials[i] = ((factorials[i - 1] % m) * (i % m)) % m;
    }
    inverses[0] = 1; inverses[1] = 1; for (ll i {2}; i <= 2000000; ++i) {
        inverses[i] = ((inverses[i - 1] % m) * (inverse(i) % m)) % m;
    }

    ll k {}; cin >> k;
    string s {}; cin >> s;

    ll strings {modpow(26, s.size() + k) % m};

    for (ll i {0}; i < s.length(); ++i) {
        ll a {((factorials[s.size() + k] * inverses[i] % m) * inverses[s.size() + k - i]) % m};
        a *= modpow(25, s.size() + k - i) % m;
        a %= m;

        strings -= a; strings %= m;
    }

    cout << (strings + m) % m;
}