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
        for (ll i = 0; i < a.size(); i++) change(i, a[i]);
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

    void change(ll pos, const ll c) {
        pos += N; Q[pos] += c;

        for (pos /= 2; pos >= 1; pos /= 2) Q[pos] = Q[2 * pos] + Q[2 * pos + 1];
    }
};

ll inv(const ll n, const vi& a) {
    SEGTREE freq (n + 1);

    ll inv = 0;

    for (const ll i : a) {
        inv += freq.query(i + 1, n);
        freq.change(i, 1);
    }

    return inv;
}

void solve() {
    ll n; cin >> n;

    vi a (n + 1); for (ll i = 1; i <= n; i++) cin >> a[i];

    vi odd; for (ll i = 1; i <= n; i += 2) odd.pb(a[i]);
    vi even; for (ll i = 2; i <= n; i += 2) even.pb(a[i]);

    const ll o = inv(n, odd), e = inv(n, even);

    sort(all(odd)); sort(all(even));

    vi res (n + 1);

    for (ll i = 1, j = 0; i <= n; i += 2, j++) res[i] = odd[j];
    for (ll i = 2, j = 0; i <= n; i += 2, j++) res[i] = even[j];

    if ((o % 2 != 0 && e % 2 == 0) || (o % 2 == 0 && e % 2 != 0)) swap(res[n], res[n - 2]);

    for (ll i = 1; i <= n; i++) cout << res[i] << " "; cout << "\n";
}

int main() {
    io
    tc

    return 0;
}