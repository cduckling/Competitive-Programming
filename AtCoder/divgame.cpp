#include <iostream>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;

int binarysearch(ll n) {
    pair<ll, ll> k {1, 2000000};
    while (k.first != k.second) {
        ll i {(k.first + k.second) / 2};

        if (n <= (i * (i + 1) / 2)) {
            k.second = i;
        } else {
            k.first = i + 1;
        }
    }

    return k.first;
}

vector<ll> factor(ll n) {
    vector<ll> f {};

    for (ll i {2}; i * i <= n; ++i) {
        while (n % i == 0) {
            f.push_back(i);
            n /= i;
        }
    }

    if (n > 1) f.push_back(n);

    return f;
}

int main() {
    ll n {}; cin >> n;

    if (n == 1) {
        cout << 0;
    } else {
        vector<ll> f {factor(n)};

        map<ll, ll> f_ {};
        for (ll i : f) {
            ++f_[i];
        }

        ll o {0};

        for (auto i : f_) {
            ll j {binarysearch(i.second)};

            if (i.second == (j * (j + 1)) / 2) {
                o += j;
            } else {
                o += j - 1;
            }
        }

        cout << o;
    }
}