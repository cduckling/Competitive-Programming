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

        ll val = -inf;

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

void solve() {
    ll n, k; cin >> n >> k;

    vi a (n), b (n); for (ll i = 0; i < n; i++) cin >> a[i]; for (ll i = 0; i < n; i++) cin >> b[i];

    for (ll i = 0; i < n; i++) {
        const ll val = min(a[i], b[i]);

        a[i] -= val, b[i] -= val;
    }

    vi pref (2 * n); pref[0] = b[0] - a[0]; for (ll i = 1; i < 2 * n; i++) pref[i] = pref[i - 1] + b[i % n] - a[i % n];

    SEGTREE rmq (pref);

    ll rnd = 0;

    for (ll i = 0; i < n; i++) {
        if (a[i] == 0) continue;

        pii r = {i + 1, 2 * n - 1};

        while (r.fir != r.sec) {
            const ll mid = (r.fir + r.sec) / 2;

            if (rmq.query(i + 1, mid) >= pref[i] + a[i]) {
                r.sec = mid;
            } else {
                r.fir = mid + 1;
            }
        }

        rnd = max(rnd, r.fir - i);
    }

    cout << rnd + 1 << "\n";
}

int main() {
    io
    tc

    return 0;
}