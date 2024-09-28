#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<ll, ll> pll;

void solve() {
    ll n {}, m {}; cin >> n >> m;

    vector<pll> o (n + 1); for (ll i {1}; i <= n; ++i) cin >> o[i].first; for (ll i {1}; i <= n; ++i) cin >> o[i].second; sort(o.begin(), o.end());

    pll op = o[1]; for (int i {2}; i <= n; ++i) {if (o[i].first - o[i].second < op.first - op.second) op = o[i];} op.second = op.first - op.second;

    vector<pll> q (m); for (ll i {0}; i < m; ++i) cin >> q[i].first; for (int i {0}; i < m; ++i) {
        if (q[i].first >= op.first) {
            ll it = (q[i].first - op.first + 1 + op.second - 1) / op.second;
            q[i].second = it * 2;
            q[i].first -= it * op.second;
        }
    }

    vector<ll> dp (1000000 + 1); ll t = 0; ll e = 0;
    for (ll i {1}; i <= 1000000; ++i) {
        if (e < n) {while (o[e + 1].first <= i) {++e; if (t == 0) t = o[e].first - o[e].second; t = min(t, o[e].first - o[e].second); if (e == n) break;}}

        if (t == 0) continue;
        dp[i] = dp[i - t] + 2;
    }

    ll p = 0; for (auto i : q) p += dp[i.first] + i.second; cout << p;
}

int main() {
    io

    solve();

    return 0;
}