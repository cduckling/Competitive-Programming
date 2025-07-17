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

#define tc ll t; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb(i) push_back(i);
#define inf 1e18;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef tuple<ll, ll, ll> tiii;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<pair<ll, ll>> vpii;
typedef vector<tuple<ll, ll, ll>> vtiii;
typedef vector<bool> vb;
typedef multiset<ll> msi;
typedef set<ll> si;
typedef map<ll, ll> mi;
typedef map<ll, vector<ll>> mvi;
typedef map<ll, pair<ll, ll>> mpii;
typedef map<ll, bool> mb;

ll Q[200002];

struct SEGTREE {
    ll N;

    SEGTREE(ll n) {
        N = n;

        for (ll i = 0; i < 2 * N; i++) Q[i] = 0;
    }

    SEGTREE(const vi& a) : SEGTREE(a.size()) {
        for (ll i {0}; i < a.size(); i++) add(i, a[i]);
    }

    ll query(ll a, ll b) {
        a += N, b += N;

        ll val = inf;

        while (a <= b) {
            if (a % 2 == 1) val = min(val, Q[a++]);
            if (b % 2 == 0) val = min(val, Q[b--]);

            a /= 2; b /= 2;
        }

        return val;
    }

    void add(ll pos, ll c) {
        pos += N; Q[pos] += c;

        for (pos /= 2; pos >= 1; pos /= 2) Q[pos] = min(Q[2 * pos], Q[2 * pos + 1]);
    }
};

pii range(const vi& a) {
    pii r;

    for (ll i : a) r.first = max(r.first, i), r.second += i;

    return r;
}

void solve() {
    ll n; cin >> n;

    vi a (n + 1); for (ll i = 1; i <= n; i++) cin >> a[i];

    vi pref (n + 1); for (ll i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i];

    vi dp (n + 1);

    pii r = range(a);

    while (r.first != r.second) {
        ll mid = (r.first + r.second) / 2;

        dp[1] = a[1]; for (ll i = 2; i <= n; i++) dp[i] = 0;

        SEGTREE g (dp);

        for (ll i = 2; i <= n; i++) {
            ll j = lower_bound(pref.begin(), pref.end(), pref[i - 1] - mid) - pref.begin();

            dp[i] = a[i] + g.query(j, i - 1);

            g.add(i, dp[i]);
        }

        ll b = min(dp[n], g.query((lower_bound(pref.begin(), pref.end(), pref[n] - mid) - pref.begin()), n));

        if (b > mid) {
            r.first = mid + 1;
        } else {
            r.second = mid;
        }
    }

    cout << r.first << "\n";
}

int main() {
    io
    tc

    return 0;
}