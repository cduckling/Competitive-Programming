#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

ll MOD = 1e9 + 7;

ll factorials[200001];
ll inverses[200001];

ll inverse(ll x) {
    return x <= 1 ? x : MOD - MOD / x * inverse(MOD % x) % MOD;
}

void solve() {
    ll n {}, m {}, k {}; cin >> n >> m >> k;

    vector<ll> a (n); for (ll  i {0}; i < n; ++i) {
        cin >> a[i];
    } sort(a.begin(), a.end());

    ll tuples {0};

    for (int i {0}; i < n; ++i) {
        int f = lower_bound(a.begin(), a.end(), a[i] - k) - a.begin();

        if (i - f + 1 >= m) {
            tuples += ((factorials[i - f] * inverses[m - 1]) % MOD * inverses[i - f - m + 1]) % MOD;
            tuples %= MOD;
        }
    }

    cout << tuples << "\n";
}

int main() {
    io

    factorials[0] = 1; for (int i {1}; i <= 200000; ++i) {
        factorials[i] = ((factorials[i - 1] % MOD) * (i % MOD)) % MOD;
    }

    inverses[0] = 1; inverses[1] = 1; for (int i {2}; i <= 200000; ++i) {
        inverses[i] = ((inverses[i - 1] % MOD) * (inverse(i) % MOD)) % MOD;
    }

    tc

    return 0;
}