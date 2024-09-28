#include <iostream>
using namespace std;

typedef long long ll;

ll m = 1e9 + 7;

ll modpow(ll b, ll e) {
    b %= m; ll r {1};
    while (e > 0) {
        if (e % 2 == 1) r = r * b % m;

        b = b * b % m;
        e /= 2;
    }

    return r;
}

int main() {
    ll a {}, b {}; cin >> a >> b;
    cout << modpow(a, b);
}