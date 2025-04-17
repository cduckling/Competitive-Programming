#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    ll n {}, m {}; cin >> n >> m;

    vector<ll> a (n + 1); for (ll i {1}; i <= n; ++i) {
        cin >> a[i];
    } sort(a.begin(), a.end());
    vector<ll> p {a}; for (ll i {1}; i <= n; ++i) {
        p[i] += p[i - 1];
    }

    ll petals {0};

    for (ll i {n}; i >= 1; --i) {
        ll j = lower_bound(a.begin(), a.end(), a[i] - 1) - a.begin(); if (j == 0) ++j;
        ll k = lower_bound(p.begin(), p.end(), p[i] - m) - p.begin(); ++k;

        petals = max(petals, p[i] - p[max(j, k) - 1]);
    }

    cout << petals << "\n";
}


int main() {
    io
    tc

    return 0;
}