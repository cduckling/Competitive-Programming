#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

ll m = 1e9 + 7;

ll modpow(ll a, ll b) {
    if (b == 0) {
        return 1;
    } else if (b % 2 == 0) {
        return (((modpow(a, b / 2) % m + m) % m) * ((modpow(a, b / 2) % m + m) % m)) % m;
    } else {
        return (((modpow(a, b - 1) % m + m) % m) * ((a % m + m)) % m) % m;
    }
}

void solve() {
    ll l {}, r {}, k {}; cin >> l >> r >> k;

    ll a {(modpow(9 / k + 1, r) % m + m) % m};
    ll b {(modpow(9 / k + 1, l) % m + m) % m};

    cout << ((a - b) % m + m) % m << "\n";
}

int main() {
    io
    tc

    return 0;
}