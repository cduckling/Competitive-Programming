#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<ll, ll> pll;

ll a {}, b {};

void solve() {
    ll n {}; cin >> n >> a >> b;

    vector<pll> c (n); for (ll i {0}; i < n; ++i) cin >> c[i].second; for (ll i {0}; i < n; ++i) c[i].first = c[i].second % gcd(a, b); sort(c.begin(), c.end());

    ll d = {c[n - 1].first - c[0].first};
    for (ll i {0}; i < n; ++i) {
        ll p = c[i].first - c[i + 1].first + gcd(a, b);

        if (p < 0) continue;
        d = min(d, p);
    }

    cout << d << "\n";
}

int main() {
    io
    tc

    return 0;
}