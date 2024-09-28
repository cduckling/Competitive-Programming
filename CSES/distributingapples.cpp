#include <iostream>
using namespace std;

typedef long long ll;

ll m = 1e9 + 7;

ll factorials[2000001];
ll inverses[2000001];

ll inverse(ll a) {
    if (inverses[m % a] != 0) {
        inverses[a] = (a <= 1 ? a : m - (m/a) * inverses[m % a] % m);
        return inverses[a];
    }

    inverses[a] = (a <= 1 ? a : m - (m/a) * inverse(m % a) % m);
    return inverses[a];
}

int main() {
    ll a {}, b {}; cin >> a >> b;

    factorials[0] = 1; factorials[1] = 1; for (int i {2}; i <= 2000000; ++i) {
        factorials[i] = factorials[i - 1]; factorials[i] *= i % m;
        factorials[i] %= m;
    }

    inverses[0] = 1; inverses[1] = 1; for (int i {2}; i <= 2000000; ++i) {
        inverse(i);
    } for (int i {2}; i <= 2000000; ++i) {
        inverses[i] *= inverses[i - 1] % m;
        inverses[i] %= m;
    }

    ll d {factorials[a + b - 1]};

    d *= inverses[a - 1] % m; d %= m;
    d *= inverses[b] % m; d %= m;

    cout << d;
}