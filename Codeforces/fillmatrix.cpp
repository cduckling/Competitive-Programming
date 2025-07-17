#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

#define tc ll t; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(a) (a).begin(), (a).end()
#define pb(i) push_back(i)
#define eb(i) emplace_back(i)
#define inf (ll) 1e18
#define fir first
#define sec second

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<vector<vector<ll>>> vvvi;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<vector<vector<double>>> vvvd;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef pair<ll, ll> pii;
typedef vector<pair<ll, ll>> vpii;
typedef vector<vector<pair<ll, ll>>> vvpii;
typedef vector<vector<vector<pair<ll, ll>>>> vvvpii;
typedef tuple<ll, ll, ll> tiii;
typedef vector<tuple<ll, ll, ll>> vtiii;
typedef vector<vector<tuple<ll, ll, ll>>> vvtiii;
typedef vector<vector<vector<tuple<ll, ll, ll>>>> vvvtiii;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef set<ll> si;
typedef vector<set<ll>> vsi;
typedef vector<vector<set<ll>>> vvsi;
typedef set<pair<ll, ll>> spii;
typedef vector<set<pair<ll, ll>>> vspii;
typedef map<ll, ll> mii;
typedef map<ll, bool> mib;
typedef map<ll, double> mid;
typedef vector<map<ll, ll>> vmii;
typedef vector<map<ll, double>> vmid;
typedef vector<map<ll, bool>> vmib;

struct SEGTREE {
    ll N; vi Q;

    SEGTREE(ll n) {
        N = n; Q.assign(2 * n, 0);
    }

    SEGTREE(const vi& a) : SEGTREE(a.size()) {
        for (ll i = 0; i < a.size(); i++) set(i, a[i]);
    }

    ll query(ll a, ll b) {
        a += N, b += N;

        ll val = 0;

        while (a <= b) {
            if (a % 2 == 1) val = max(val, Q[a++]);
            if (b % 2 == 0) val = max(val, Q[b--]);

            a /= 2; b /= 2;
        }

        return val;
    }

    void set(ll pos, const ll c) {
        pos += N; Q[pos] = c;

        for (pos /= 2; pos >= 1; pos /= 2) Q[pos] = max(Q[2 * pos], Q[2 * pos + 1]);
    }
};

void block(const ll h, const ll l, const ll r, vi& b, SEGTREE& push, const vvi& occ, const vi& a) {
    const ll diff = r - l - 1; if (diff <= 1) return;

    const ll next = push.query(l + 1, r - 1);

    b[diff] += h - next; if (!next) return;

    const ll i = lower_bound(all(occ[next]), l) - occ[next].begin(), j = upper_bound(all(occ[next]), r) - occ[next].begin();

    vi pts; pts.pb(l); for (ll k = i; k < j; k++) pts.pb(occ[next][k]); pts.pb(r);

    for (ll k = 1; k < pts.size(); k++) block(next, pts[k - 1], pts[k], b, push, occ, a);
}

void solve() {
    ll n; cin >> n;

    vi a (n + 2); for (ll i = 1; i <= n; i++) cin >> a[i]; a[0] = n, a[n + 1] = n;

    ll m; cin >> m;

    vvi occ (n + 1); for (ll i = 0; i <= n + 1; i++) occ[a[i]].pb(i);

    SEGTREE push (a);

    vi b (n + 1);

    for (ll i = 1; i < occ[n].size(); i++) block(n, occ[n][i - 1], occ[n][i], b, push, occ, a);

    ll res = 0; for (ll i = n; i >= 2; i--) {
        const ll ops = min(b[i], m / i);

        res += ops * (i - 1), m -= ops * i, b[i] -= ops;

        if (b[i] && m) res += m - 1, m = 0;
    }

    cout << res << "\n";
}

int main() {
    io
    tc

    return 0;
}