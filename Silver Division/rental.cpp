#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;

ll n {}, m {}, r {};

bool s (ll a, ll b) {
    return a > b;
}
bool s_ (pair<ll, ll> a, pair<ll, ll> b) {
    return a.second > b.second;
}

ll price(const ll milk, vector<pair<ll, ll>>& stores, ll& i) {
    ll sold {0}, profit {0};

    while (milk != sold) {
        ll j {min(milk - sold, stores[i].first)};

        profit += j * stores[i].second;
        sold += j;
        stores[i].first -= j;

        if (stores[i].first == 0) {
            ++i;
        }
    }

    return profit;
}

int main() {
    freopen("rental.in", "r", stdin); freopen("rental.out", "w", stdout);

    cin >> n >> m >> r;

    vector<ll> cows (n, 0);
    for (ll i {0}; i < n; ++i) {
        cin >> cows[i];
    }
    sort(cows.begin(), cows.end());

    vector<pair<ll, ll>> stores (m, {0, 0}); for (ll i {0}; i < m; ++i) {
        cin >> stores[i].first >> stores[i].second;
    }
    sort(stores.begin(), stores.end(), s_);
    stores.emplace_back(1000000000, 0);

    vector<ll> neighbors (r, 0);
    for (ll i {0}; i < r; ++i) {
        cin >> neighbors[i];
    }
    sort(neighbors.begin(), neighbors.end(), s);

    vector<ll> profits (n, 0); ll profit {0};

    ll j {0};
    for (ll i {n - 1}; i >= 0; --i) {
        profits[i] = price(cows[i], stores, j);
        profit += profits[i];
    }

    ll k {0};
    for (ll i : profits) {
        if (k == r) {
            break;
        }

        if (i < neighbors[k]) {
            profit -= i;
            profit += neighbors[k];
            ++k;
        }
    }

    cout << profit;
}