#include <iostream>
#include <vector>
#include <array>
#include <map>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

vector<ll> sieve (200001);
void eratosthenes() {
    sieve[0] = 1; sieve[1] = 1;

    for (ll i {2}; i <= 200000; ++i) {
        if (!sieve[i]) {
            for (ll j {i}; j <= 200000; j += i) {
                sieve[j] = i;
            }
        }
    }
}
vector<ll> factor(ll n) {
    if (n == 1) {
        return {};
    } else {
        vector<ll> f {};

        while (n != sieve[n]) {
            f.push_back(sieve[n]);
            n /= sieve[n];
        }

        f.push_back(sieve[n]);

        return f;
    }
}

map<ll, array<ll, 3>> p {};

void primes(const vector<ll>& f) {
    map<ll, ll> factor {}; for (ll i : f) {
        ++factor[i];
    }

    for (auto const& [prime, exponent] : factor) {
        ++p[prime][2];

        if (p[prime][2] == 1) {
            p[prime][0] = 100; p[prime][1] = 100;
            p[prime][0] = exponent;
        } else {
            if (exponent < p[prime][0]) {
                p[prime][1] = p[prime][0];
                p[prime][0] = exponent;
            } else if (exponent < p[prime][1]) {
                p[prime][1] = exponent;
            }
        }
    }
}
ll modpow(ll a, ll b) {
    if (b == 0) {
        return 1;
    } else if (b % 2 == 0) {
        return modpow(a, b / 2) * modpow(a, b / 2);
    } else {
        return modpow(a, b - 1) * a;
    }
}

int main() {
    io

    eratosthenes();

    ll n {}; cin >> n;

    vector<ll> a (n); for (ll i {0}; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<ll>> f (n);
    for (ll i {0}; i < n; ++i) {
        f[i] = factor(a[i]);
    }

    for (ll i {0}; i < n; ++i) {
        primes(f[i]);
    }

    ll g {1};

    for (auto i : p) {
        if (n - i.second[2] == 0) {
            g *= modpow(i.first, i.second[1]);
        } else if (n - i.second[2] == 1) {
            g *= modpow(i.first, i.second[0]);
        }
    }

    cout << g;

    return 0;
}