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
#define eb(a, b) emplace_back(a, b)
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
    ll n; vi t, lazy;

    SEGTREE(const ll n) {
        this->n = n; t.assign(4 * n, 0), lazy.assign(4 * n, 0);
    }

    SEGTREE(const vi& a) : SEGTREE(a.size()) {
        build(1, 0, n - 1, a);
    }

    void build(const ll k, const ll l, const ll r, const vi& a){
        if (l == r) {
            t[k] = a[l];
        } else {
            build(2 * k, l,  (l + r) / 2, a), build(2 * k + 1, (l + r) / 2 + 1, r, a);

            t[k] = min(t[2 * k], t[2 * k + 1]);
        }
    }

    void update(const ll l, const ll r, const ll val) {
        update(l, r, val, 1, 0, n - 1);
    }

    void update(const ll l, const ll r, const ll val, const ll k, const ll a, const ll b) {
        if (r < a || l > b) return;

        if (l <= a && b <= r) {
            apply(k, b - a + 1, val);
        } else {
            push(k, a, b);

            update(l, r, val, 2 * k, a, (a + b) / 2), update(l, r, val, 2 * k + 1, (a + b) / 2 + 1, b);

            t[k] = min(t[2 * k], t[2 * k + 1]);
        }
    }

    ll query(const ll l, const ll r) {
        return query(l, r, 1, 0, n - 1);
    }

    ll query(const ll l, const ll r, const ll k, const ll a, const ll b) {
        if (r < a || l > b) return inf;

        if (l <= a && b <= r) return t[k];

        push(k, a, b);

        return min(query(l, r, 2 * k, a, (a + b) / 2), query(l, r, 2 * k + 1, (a + b) / 2 + 1, b));
    }

    void push(const ll k, const ll a, const ll b) {
        apply(2 * k, (a + b) / 2 - a + 1, lazy[k]), apply(2 * k + 1, b - (a + b) / 2, lazy[k]);

        lazy[k] = 0;
    }

    void apply(const ll k, const ll len, const ll val) {
        t[k] += val, lazy[k] += val;
    }
};

void solve() {
    ll n, k, a; cin >> n >> k >> a;

    vvpii xyc (k + 1); for (ll i = 1; i <= n; i++) {
        ll x, y, c; cin >> x >> y >> c;
        xyc[x].eb(y, c);
    } for (ll i = 0; i <= k; i++) sort(all(xyc[i]), greater<pii>());

    vi c (k + 1); for (ll i = 0; i <= k; i++) for (const pii j : xyc[i]) c[i] += j.sec;

    vi dp (k + 1); dp[k] = 0;

    SEGTREE t (k + 1); t.update(k, k, a * k);

    for (ll i = k - 1; i >= 0; i--) {
        for (const pii j : xyc[i]) if (i + 1 <= k - j.fir - 1) t.update(i + 1, k - j.fir - 1, j.sec);

        dp[i] = min(c[i] + dp[i + 1], - a * i + t.query(i + 1, k));

        t.update(i, i, i * a + dp[i]);
    }

    cout << dp[0] << "\n";
}

int main() {
    io

    solve();

    return 0;
}