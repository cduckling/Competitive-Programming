#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

bool s(pair<ll, ll> a, pair<ll, ll> b) {
    return a.second < b.second;
}

int main() {
    io

    ll n {}; cin >> n;

    vector<pair<ll, ll>> product (n);
    for (ll i {0}; i < n; ++i) {
        cin >> product[i].first >> product[i].second;
    }
    sort(product.begin(), product.end(), s);

    ll a {0}, b {n - 1}; ll bought {0}, cost {0};

    while (true) {
        if (a < b) {
            ll p {max(min(product[b].first, product[a].second - bought), 0ll)};

            bought += p; cost += 2 * p; product[b].first -= p;

            if (product[b].first == 0) {
                --b;
            }

            if (product[a].second <= bought) {
                bought += product[a].first;
                cost += product[a].first;
                ++a;
            }
        } else {
            if (bought >= product[a].second) {
                cost += product[a].first;
            } else {
                ll p {min(product[a].first, product[a].second - bought)};

                cost += 2 * p;
                product[a].first -= p;

                cost += product[a].first;
            }

            break;
        }
    }

    cout << cost;

    return 0;
}