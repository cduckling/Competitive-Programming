#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb(i) push_back(i);
#define inf 1e18;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<pair<ll, ll>> vpii;
typedef vector<bool> vb;
typedef set<ll> si;
typedef map<ll, ll> mi;
typedef map<ll, vector<ll>> mvi;
typedef map<ll, pair<ll, ll>> mpii;
typedef map<ll, bool> mb;

void solve() {
    ll n {}, m {}, v {}; cin >> n >> m >> v;

    vi a (n + 2), pref (n + 2); for (ll i {1}; i <= n; ++i) cin >> a[i]; for (ll i {1}; i <= n + 1; ++i) pref[i] = a[i] + pref[i - 1];

    vi l (n + 2); ll s = a[1]; if (s >= v) { s = 0; l[1] = 1; } for (ll i {2}; i <= n; ++i) {
        s += a[i];

        if (s >= v) {
            l[i] = 1; s = 0;
        }

        l[i] += l[i - 1];
    }

    vi r (n + 2); s = a[n]; if (s >= v) { s = 0; r[n] = 1; } for (ll i {n - 1}; i >= 1; --i) {
        s += a[i];

        if (s >= v) {
            r[i] = 1; s = 0;
        }

        r[i] += r[i + 1];
    }

    mi f {}; for (ll i {1}; i <= n + 1; ++i) f[r[i]] = i;

    ll h = -1;

    for (ll i {0}; i <= n; ++i) {
        ll p = f[m - l[i]]; if (!p) continue;

        h = max(h, pref[p - 1] - pref[i]);
    }

    cout << h << "\n";
}

int main() {
    io
    tc

    return 0;
}