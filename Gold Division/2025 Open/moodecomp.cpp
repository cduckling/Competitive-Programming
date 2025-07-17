#include <iostream>
using namespace std;

#define combo(n, k) (((fac[n] * inv[k]) % mod *  inv[n - k]) % mod)

typedef long long ll;

ll mod = 1e9 + 7;

ll fac[1000001];
ll inv[1000001];

ll inverse(const ll val) {
    if (val <= 1) return val; return mod - mod / val * inverse(mod % val) % mod;
}

ll exp(ll b, ll e) {
    b %= mod; ll r = 1;

    while (e > 0) {
        if (e % 2 == 1) r = r * b % mod;

        b = b * b % mod;
        e /= 2;
    }

    return r;
}

void solve() {
    ll k, n, l; cin >> k >> n >> l;

    string t; cin >> t; t = " " + t;

    ll o = 0; ll cnt = 1;

    for (ll i = n; i >= 1; i--) {
        if (t[i] == 'M') {
            cnt *= combo(o, k), cnt %= mod; o -= k;
        } else {
            o++;
        }
    }

    cout << exp((cnt + mod) % mod, l) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    fac[0] = 1; for (int i = 1; i <= 1000000; i++) fac[i] = fac[i - 1] % mod * (i % mod) % mod;
    inv[0] = 1, inv[1] = 1; for (int i = 2; i <= 1000000; i++) inv[i] = inv[i - 1] % mod * (inverse(i) % mod) % mod;

    solve();

    return 0;
}