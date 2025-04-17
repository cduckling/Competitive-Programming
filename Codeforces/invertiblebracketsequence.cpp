#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

ll e[31];

void solve() {
    string a {}; cin >> a;

    ll n = a.size();

    vector<ll> p (n); p[0] = (a[0] == '(') ? 1 : -1; for (ll i {1}; i < n; ++i) p[i] = p[i - 1] + ((a[i] == '(') ? 1 : -1);

    vector<vector<ll>> st (n, vector<ll> (static_cast<ll>(log2(n)) + 1)); for (ll i {0}; i < n; ++i) st[i][0] = p[i];

    for (ll i {1}; i <= log2(n); ++i) for (ll j {0}; j < n - e[i] + 1; ++j) st[j][i] = max(st[j][i - 1], st[j + e[i - 1]][i - 1]);

    vector<ll> c (n, -1);

    vector<ll> dp (n); for (ll i {0}; i < n; ++i) {
        if (c[p[i]] != -1) {
            ll l = static_cast<ll>(log2(i - (c[p[i]] + 1) + 1)), m = max(st[c[p[i]] + 1][l], st[i - e[l] + 1][l]);

            if (-m + 2 * p[i] >= 0) dp[i] = 1 + dp[c[p[i]]];
        }

        c[p[i]] = i;
    }

    ll t {}; for (ll i : dp) t += i; cout << t << "\n";
}

int main() {
    io

    e[0] = 1; for (ll i {1}; i <= 30; ++i) e[i] = e[i - 1] * 2;

    tc

    return 0;
}