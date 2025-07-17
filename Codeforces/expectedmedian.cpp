#include <iostream>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

const ll m = 1e9 + 7, s = 2 * 1e5;
ll factorials[s + 1];
ll inverses[s + 1];

ll inverse(ll x) {
    return x <= 1 ? x : m - m / x * inverse(m % x) % m;
}

ll choose(ll a, ll b) {
    if (a < b) return 0;

    return ((factorials[a] * inverses[b] % m) * inverses[a - b]) % m;
}

void solve() {
    ll n {}, k {}; cin >> n >> k;

    ll _1 {0}, _0 {0}; for (ll i {0}; i < n; ++i) {
        int b {}; cin >> b;

        if (b) ++_1; if (!b) ++_0;
    }

    ll c {0};

    for (ll i = (k + 1) / 2; i <= min(_1, k); ++i) c += (choose(_1, i) * choose(_0, k - i) % m) % m; c %= m;

    cout << c << "\n";
}

int main() {
    io

    factorials[0] = 1; for (ll i {1}; i <= s; ++i) {
        factorials[i] = ((factorials[i - 1] % m) * (i % m)) % m;
    }
    inverses[0] = 1; inverses[1] = 1; for (ll i {2}; i <= s; ++i) {
        inverses[i] = ((inverses[i - 1] % m) * (inverse(i) % m)) % m;
    }

    tc

    return 0;
}