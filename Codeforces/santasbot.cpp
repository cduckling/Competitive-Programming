#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

ll m {998244353};

map<ll, vector<ll>> gifts {};

ll inverse(ll x) {
    return x <= 1 ? x : m - m / x * inverse(m % x) % m;
}

int main() {
    io

    ll n {}; cin >> n;

    for (ll i {0}; i < n; ++i) {
        ll k {}; cin >> k;

        for (ll a {0}; a < k; ++a) {
            ll g {}; cin >> g;

            gifts[g].push_back(k);
        }
    }

    ll valid {0};
    for (const auto& i : gifts) {
        ll v = i.second.size();
        v *= ((inverse(n) % m) * (inverse(n) % m)) % m;

        for (ll j : i.second) {
            valid += ((v % m) * (inverse(j) % m)) % m;
        }

        valid %= m;
    }

    cout << valid;
}
