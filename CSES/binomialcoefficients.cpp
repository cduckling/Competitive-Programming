#include <iostream>
using namespace std;

typedef long long ll;

ll m = 1e9 + 7;
ll factorials[1000001];
ll inverses[1000001];

ll inverse(ll x) {
    return x <= 1 ? x : m - m / x * inverse(m % x) % m;
}

int main() {
    ll n {}; cin >> n;

    factorials[0] = 1;
    for (int i {1}; i <= 1000000; ++i) {
        factorials[i] = ((factorials[i - 1] % m) * (i % m)) % m;
    }

    inverses[0] = 1; inverses[1] = 1;
    for (int i {2}; i <= 1000000; ++i) {
        inverses[i] = ((inverses[i - 1] % m) * (inverse(i) % m)) % m;
    }

    for (ll i {0}; i < n; ++i) {
        ll a {}, b {}; cin >> a >> b;
        cout << ((factorials[a] * inverses[b]) % m *  inverses[a - b]) % m << "\n";
    }
}

/*


ll m = 1e9 + 7;
ll factorials[1000001];
ll inverses[1000001];

ll inverse(ll x) {
    return x <= 1 ? x : m - m / x * inverse(m % x) % m;
}

    factorials[0] = 1;
    for (int i {1}; i <= 1000000; ++i) {
        factorials[i] = ((factorials[i - 1] % m) * (i % m)) % m;
    }

    inverses[0] = 1; inverses[1] = 1;
    for (int i {2}; i <= 1000000; ++i) {
        inverses[i] = ((inverses[i - 1] % m) * (inverse(i) % m)) % m;
    }
 */