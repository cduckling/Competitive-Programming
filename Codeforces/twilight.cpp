#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
using namespace std;

#define tc ll t; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(a) (a).begin(), (a).end()
#define pb(i) push_back(i)
#define eb(i) emplace_back(i)
#define ceil(a, b) ((a + b - 1) / b)
#define inf (ll) 1e18
#define fail cout << -1 << "\n"; return;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef tuple<ll, ll, ll> tiii;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<set<ll>> vsi;
typedef vector<pair<ll, ll>> vpii;
typedef vector<vector<pair<ll, ll>>> vvpii;
typedef vector<tuple<ll, ll, ll>> vtiii;
typedef vector<bool> vb;
typedef multiset<ll> msi;
typedef set<ll> si;
typedef set<pair<ll, ll>> spii;
typedef set<tuple<ll, ll, ll>> stiii;
typedef map<ll, ll> mii;
typedef map<ll, vector<ll>> mivi;
typedef map<ll, pair<ll, ll>> mipii;
typedef map<ll, set<ll>> misi;
typedef map<ll, bool> mib;

ll p[60];
vi fac[60];

void solve() {
    ll n; cin >> n;

    vi a (n + 1); for (ll i = 1; i <= n; i++) cin >> a[i];

    vvpii dp (n + 1, vpii (1<<17, {inf, 0})); for (ll i = 1; i < 60; i++) {
        ll b = 0; for (const ll j : fac[i]) b += (1<<p[j]);

        if (abs(a[1] - i) < dp[1][b].first) dp[1][b].first = abs(a[1] - i), dp[1][b].second = i;
    }

    for (ll i = 2; i <= n; i++) {
        for (ll j = 1; j < 60; j++) {
            ll b = 0; for (const ll k : fac[j]) b += (1<<p[k]);

            const ll s = (1<<17) - 1 - b;

            for (ll sub = s; sub; sub = (sub - 1)&s) {
                if (dp[i - 1][sub].first + abs(a[i] - j) < dp[i][sub|b].first) {
                    dp[i][sub|b].first = dp[i - 1][sub].first + abs(a[i] - j), dp[i][sub|b].second = j;
                }
            }

            if (dp[i - 1][0].first + abs(a[i] - j) < dp[i][b].first) {
                dp[i][b].first = dp[i - 1][0].first + abs(a[i] - j), dp[i][b].second = j;
            }
        }
    }

    ll c = 0; for (ll i = 0; i < (1<<17); i++) if (dp[n][i].first < dp[n][c].first) c = i;

    vi b (n + 1);

    for (ll i = n; i >= 1; i--) {
        b[i] = dp[i][c].second;

        for (const ll j : fac[b[i]]) c -= (1<<p[j]);
    }

    for (ll i = 1; i <= n; i++) cout << b[i] << " "; cout << "\n";
}

int main() {
    io

    ll ind = 0;

    for (ll i = 2; i < 60; i++) {
        if (!fac[i].empty()) continue;

        p[i] = ind++; for (ll j = i; j < 60; j += i) fac[j].pb(i);
    }

    solve();

    return 0;
}