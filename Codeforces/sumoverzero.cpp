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
    ll n; vi q;

    SEGTREE(const ll n) {
        this->n = n; q.assign(2 * n, -inf);
    }

    SEGTREE(const vi& a) : SEGTREE(a.size()) {
        for (ll i = 0; i < n; i++) set(i, a[i]);
    }

    ll query(ll a, ll b) {
        a += n, b += n;

        ll val = 0;

        while (a <= b) {
            if (a % 2 == 1) val = max(val, q[a++]);
            if (b % 2 == 0) val = max(val, q[b--]);

            a /= 2; b /= 2;
        }

        return val;
    }

    void set(ll pos, const ll val) {
        pos += n; q[pos] = max(q[pos], val);

        for (pos /= 2; pos >= 1; pos /= 2) q[pos] = max(q[2 * pos], q[2 * pos + 1]);
    }
};

void compress(const ll n, vi& pref) {
    vi p = pref; sort(all(p)); mii inv; for (ll i = 0; i <= n; i++) inv[p[i]] = i; for (ll i = 0; i <= n; i++) pref[i] = inv[pref[i]];
}

void solve() {
    ll n; cin >> n;

    vi a (n + 1); for (ll i = 1; i <= n; i++) cin >> a[i];

    vi pref (n + 1); for (ll i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i]; compress(n, pref); for (const ll i : pref) cout << i << " "; cout << "\n";

    vi dp (n + 1);

    SEGTREE next (n + 1); //next.set(pref[0], 0);

    for (ll i = 1; i <= n; i++) {
        dp[i] = max(0ll, next.query(0, pref[i]) + i);
        next.set(pref[i], dp[i] - i);
    }

    for (const ll i : dp) cout << i << " "; cout << "\n";
}

int main() {
    io

    solve();

    return 0;
}