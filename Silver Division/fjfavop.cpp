#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

#define ceil(a, b) ((a + b - 1) / b)
#define inf (1e18);

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<pair<ll, ll>> vpii;

ll push(const ll val, const ll g, const ll m) {
    switch (g) {
        case 0: return val - m;
        case 1: return val - m / 2;
        case 2: return val + 1;
        case 3: return val + ceil(m, 2);
    }
}

ll cost(const ll x, const ll m, const vi& p, const vi& pref) {
    ll c = 0, l = 0;

    for (ll i = 3; i >= 0; i--) {
        if (p[i] == 0) continue;

        const ll len = p[i] - l, tot = (pref[p[i]] - pref[l]) - x * len;

        switch (i) {
            case 0: c += len * m - tot; break;
            case 1: c += tot; break;
            case 2: c += -tot; break;
            case 3: c += m * len + tot; break;
        }

        l = p[i];
    }

    return c;
}

void solve() {
    ll n, m; cin >> n >> m;

    vi a (n + 1); for (ll i = 1; i <= n; i++) cin >> a[i]; for (ll i = 1; i <= n; i++) a[i] %= m; sort(a.begin(), a.end());

    vi pref (n + 1); for (ll i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i];

    vpii ops; for (ll i = 1; i <= n; i++) for (ll j = 1; j < 4; j++) ops.emplace_back(max(0ll, push(a[i], j, m)), j); sort(ops.begin(), ops.end());

    vi p (4); p[0] = n;

    ll c = inf;

    for (ll i = 0; i < ops.size(); i++) {
        if (ops[i].first >= m) break;

        ll j = i;

        while (j < ops.size() && ops[i].first == ops[j].first) p[ops[j].second]++, j++;

        i += j - i - 1;

        c = min(c, cost(ops[i].first, m, p, pref)); c = min(c, cost(min(m - 1, (i + 1 < ops.size() ? ops[i + 1].first - 1 : m - 1)), m, p, pref));
    }

    cout << c << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    ll t; cin >> t; while (t--) solve();

    return 0;
}