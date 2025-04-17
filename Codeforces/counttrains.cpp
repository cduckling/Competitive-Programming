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
#define inf (ll) 1e18
#define f first
#define s second

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

        ll val = inf;

        while (a <= b) {
            if (a % 2 == 1) val = min(val, Q[a++]);
            if (b % 2 == 0) val = min(val, Q[b--]);

            a /= 2; b /= 2;
        }

        return val;
    }

    void set(ll pos, const ll c) {
        pos += N; Q[pos] = c;

        for (pos /= 2; pos >= 1; pos /= 2) Q[pos] = min(Q[2 * pos], Q[2 * pos + 1]);
    }
};
struct PREF {
    ll N; vi Q;

    PREF(ll n) {
        N = n; Q.assign(2 * n, 0);
    }

    PREF(const vi& a) : PREF(a.size()) {
        for (ll i = 0; i < a.size(); i++) set(i, a[i]);
    }

    ll query(ll a, ll b) {
        a += N, b += N;

        ll val = 0;

        while (a <= b) {
            if (a % 2 == 1) val += Q[a++];
            if (b % 2 == 0) val += Q[b--];

            a /= 2; b /= 2;
        }

        return val;
    }

    void set(ll pos, const ll c) {
        pos += N; Q[pos] = c;

        for (pos /= 2; pos >= 1; pos /= 2) Q[pos] = Q[2 * pos] + Q[2 * pos + 1];
    }
};

void solve() {
    ll n, q; cin >> n >> q;

    vi a (n + 1); for (ll i = 1; i <= n; i++) cin >> a[i]; a[0] = inf;

    si fin; ll cur = a[0]; for (ll i = 1; i <= n; i++) if (cur > a[i]) fin.insert(i - 1), cur = a[i]; fin.erase(0), fin.insert(n);

    SEGTREE g (a); PREF h (n + 1); for (const ll i : fin) h.set(i, 1);

    ll cnt = fin.size();

    for (ll i = 0; i < q; i++) {
        ll pos, dec; cin >> pos >> dec;

        a[pos] -= dec, g.set(pos, a[pos]);

        if (g.query(1, pos - 1) <= a[pos]) {
            cout << cnt << " "; continue;
        }

        pii r = {pos, n};

        while (r.first != r.second) {
            const ll mid = (r.second + r.first + 1) / 2;

            if (g.query(1, mid) == a[pos]) {
                r.first = mid;
            } else {
                r.second = mid - 1;
            }
        }

        const ll num = h.query(pos, r.first);

        if (!fin.count(pos - 1) && pos != 1) cnt++, fin.insert(pos - 1), h.set(pos - 1, 1); cnt -= num - 1;

        cout << cnt << " ";

        vi rem; auto it = fin.lower_bound(pos); while (it != fin.end() && *it < r.first) rem.pb(*it), ++it;

        for (const ll j : rem) fin.erase(j), h.set(j, 0);
    }

    cout << "\n";
}

int main() {
    io
    tc

    return 0;
}