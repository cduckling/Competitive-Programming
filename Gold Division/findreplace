#include <iostream>
#include <vector>
using namespace std;

#define pb(a) push_back(a)
#define fir first
#define sec second
#define inf (ll) 1e18

typedef unsigned long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<vector<vector<ll>>> vvvi;

void solve() {
    ll l, r, q; cin >> l >> r >> q;

    vector<pair<char, string>> cs (q + 1); for (ll i = 1; i <= q; i++) cin >> cs[i].fir >> cs[i].sec;

    vvi dp (q + 2, vi (26, 1)); for (ll i = q; i >= 1; i--) {
        ll sum = 0; for (const char j : cs[i].sec) sum += dp[i + 1][j - 'a'];

        dp[i] = dp[i + 1], dp[i][cs[i].fir - 'a'] = min(inf, sum);
    }

    vvvi pref (q + 2, vvi (26)); for (ll i = 1; i <= q; i++) {
        for (const char c : cs[i].sec) pref[i][cs[i].fir - 'a'].pb(dp[i + 1][c - 'a']);
        for (ll j = 1; j < pref[i][cs[i].fir - 'a'].size(); j++) pref[i][cs[i].fir - 'a'][j] += pref[i][cs[i].fir - 'a'][j - 1], pref[i][cs[i].fir - 'a'][j] = min(inf, pref[i][cs[i].fir - 'a'][j]);
    }

    for (ll i = l; i <= r; i++) {
        pii cur = {1, dp[1][0]}; char c = 'a';

        for (ll j = 1; j <= q; j++) {
            if (pref[j][c - 'a'].empty()) continue;

            const ll k = lower_bound(pref[j][c - 'a'].begin(), pref[j][c - 'a'].end(), i - cur.fir + 1) - pref[j][c - 'a'].begin();

            cur = {cur.fir + (k > 0 ? pref[j][c - 'a'][k - 1] : 0), cur.fir + pref[j][c - 'a'][k] - 1}; c = cs[j].sec[k];
        }

        cout << c;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();

    return 0;
}
