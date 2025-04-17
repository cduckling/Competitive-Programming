#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

ll n {}, k {};

array<ll, 100001> sieve {};
void eratosthenes() {
    sieve[0] = 1; sieve[1] = 1;

    for (ll i {2}; i <= 100000; ++i) {
        if (!sieve[i]) {
            for (ll j {i}; j <= 100000; j += i) {
                sieve[j] = i;
            }
        }
    }
}
map<ll, ll> factor(ll a) {
    map<ll, ll> f {};

    if (a == 1) {
        return f;
    } else {
        while (a != sieve[a]) {
            ++f[sieve[a]];
            f[sieve[a]] %= k;
            a /= sieve[a];
        }

        ++f[a]; f[a] %= k;

        map<ll, ll> f_ {};
        for (auto i : f) {
            if (i.second != 0) {
                f_[i.first] = i.second;
            }
        }

        return f_;
    }
}
map<ll, ll> opposite(const map<ll, ll>& a) {
    map<ll, ll> o {};
    for (auto i : a) {
        o[i.first] = k - i.second;
    }
    return o;
}

int main() {
    io

    eratosthenes();

    cin >> n >> k;

    vector<ll> a (n); for (ll i {0}; i < n; ++i) {
        cin >> a[i];
    }
    vector<map<ll, ll>> f (n); for (ll i {0}; i < n; ++i) {
        f[i] = factor(a[i]);
    }

    map<map<ll, ll>, ll> m {}; for (ll i {0}; i < n; ++i) {
        ++m[f[i]];
    }

    ll p {};
    for (ll i {0}; i < n; ++i) {
        map<ll, ll> o {opposite(f[i])};

        if (f[i] == o) {
            p += m[o] - 1;
        } else {
            p += m[o];
        }
    }

    cout << p / 2;
}