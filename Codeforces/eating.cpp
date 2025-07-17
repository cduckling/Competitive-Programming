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

ll msb(const ll w) {
    ll bit = 0; for (ll j = 0; j < 30; j++) if ((w&(1<<j)) > 0) bit = j; return bit;
}

ll next(const ll pos, const ll val, const vvi& b) {
    ll next = inf; for (ll i = val; i < 30; i++) {
        auto it = lower_bound(b[i].begin(), b[i].end(), pos);

        if (it != b[i].end()) next = min(next, *it);
    }

    return next;
}

void solve() {
    ll n, q; cin >> n >> q;

    vi w (n + 1); for (ll i = n; i >= 1; i--) cin >> w[i];

    vi p (n + 1); for (ll i = 1; i <= n; i++) p[i] = p[i - 1]^w[i];

    vi m (n + 1); m[0] = -1; for (ll i = 1; i <= n; i++) m[i] = msb(w[i]);

    vvi b (30); for (ll i = 1; i <= n; i++) b[m[i]].pb(i);

    for (ll i = 0; i < q; i++) {
        ll Q; cin >> Q;

        ll l = 0;

        for (ll j = 1; j <= n; j++) {
            const ll fin = next(j, msb(Q), b);

            if (fin == inf) {
                l = n; break;
            }

            l = fin - 1;

            Q = Q^(p[fin - 1]^p[j - 1]);

            if (Q < w[fin]) break;

            Q = Q^w[fin], l++;

            j = fin;
        }

        cout << l << " ";
    }

    cout << "\n";
}

int main() {
    io
    tc

    return 0;
}