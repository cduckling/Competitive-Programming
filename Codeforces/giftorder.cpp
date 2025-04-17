#pragma GCC optimize("Ofast,unroll-loops")

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
#define pb(i) push_back(i);
#define ceil(a, b) ((a + b - 1) / b)
#define inf 1e18

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
typedef map<ll, ll> mi;
typedef map<ll, vector<ll>> mivi;
typedef map<ll, pair<ll, ll>> mipii;
typedef map<ll, bool> mib;

ll sqrt(const ll n) {
    pair<ll, ll> r {1, 1e4};

    while (r.first != r.second) {
        ll mid = (r.first + r.second + 1) / 2;

        if (mid * mid <= n) {
            r.first = mid;
        } else {
            r.second = mid - 1;
        }
    }

    return r.first;
}

struct RSQRTDECOMP {
    ll N; vi A, MIN, MAX, Q; ll root = 0;;

    RSQRTDECOMP(const ll n, const vi& a) {
        N = n, root = sqrt(n); root++;

        A.resize(n); for (ll i = 0; i < n; i++) A[i] = a[i] - i;

        MIN.assign(root, inf), MAX.assign(root, -inf), Q.assign(root, 0);

        for (ll i = 0; i < n; i++) MIN[i / root] = min(MIN[i / root], A[i]);
        for (ll i = 0; i < n; i++) MAX[i / root] = max(MAX[i / root], A[i]);

        ll low = inf;

        for (ll i = 0; i < n; i++) {
            if (i % root == 0) {
                low = A[i];
            } else {
                Q[i / root] = max(Q[i / root], A[i] - low), low = min(low, A[i]);
            }
        }
    }

    ll query() {
        ll val = -inf, low = inf;

        for (ll i = 0; i < N; i++) {
            val = max(val, Q[i / root]), val = max(val, MAX[i / root] - low), low = min(low, MIN[i / root]); i += root - 1;
        }

        return val;
    }

    void update(const ll pos, const ll val) {
        A[pos] = val, MIN[pos / root] = inf, MAX[pos / root] = -inf, Q[pos / root] = -inf;

        ll low = inf;

        for (ll i = (pos / root) * root; i < min((pos / root + 1) * root, N); ++i) MIN[i / root] = min(MIN[i / root], A[i]), MAX[i / root] = max(MAX[i / root], A[i]);
        for (ll i = (pos / root) * root; i < min((pos / root + 1) * root, N); ++i) Q[pos / root] = max(Q[pos / root], A[i] - low), low = min(low, A[i]);
    }
};

struct LSQRTDECOMP {
    ll N; vi A, MIN, MAX, Q; ll root = 0;;

    LSQRTDECOMP(const ll n, const vi& a) {
        N = n, root = sqrt(n); root++;

        A.resize(n); for (ll i = 0; i < n; i++) A[i] = a[i] + i;

        MIN.assign(root, inf), MAX.assign(root, -inf), Q.assign(root, 0);

        for (ll i = 0; i < n; i++) MIN[i / root] = min(MIN[i / root], A[i]);
        for (ll i = 0; i < n; i++) MAX[i / root] = max(MAX[i / root], A[i]);

        ll low = inf;

        for (ll i = n - 1; i >= 0; i--) {
            if (i % root == 0) {
                Q[i / root] = max(Q[i / root], A[i] - low), low = inf;
            } else {
                Q[i / root] = max(Q[i / root], A[i] - low), low = min(low, A[i]);
            }
        }
    }

    ll query() {
        ll val = -inf, low = inf;

        for (ll i = N - 1; i >= 0; i--) {
            val = max(val, Q[i / root]); val = max(val, MAX[i / root] - low), low = min(low, MIN[i / root]); i -= root - 1;
        }

        return val;
    }

    void update(const ll pos, const ll val) {
        A[pos] = val, MIN[pos / root] = inf, MAX[pos / root] = -inf, Q[pos / root] = -inf;

        ll low = inf;

        for (ll i = min((pos / root + 1) * root, N) - 1; i >= (pos / root) * root; i--) MIN[i / root] = min(MIN[i / root], A[i]), MAX[i / root] = max(MAX[i / root], A[i]);
        for (ll i = min((pos / root + 1) * root, N) - 1; i >= (pos / root) * root; i--) Q[i / root] = max(Q[i / root], A[i] - low), low = min(low, A[i]);
    }
};


void solve() {
    ll n, q; cin >> n >> q;

    vi a (n); for (ll i = 0; i < n; i++) cin >> a[i]; if (n == 1) {
        cout << 0 << "\n";

        for (ll i = 0; i < q; i++) {
            ll p, v; cin >> p >> v;

            cout << 0 << "\n";
        }

        return;
    }

    RSQRTDECOMP g (n, a); LSQRTDECOMP h (n, a); cout << max(0ll, max(g.query(), h.query())) << "\n";

    for (ll i = 0; i < q; i++) {
        ll p, v; cin >> p >> v; p--;

        g.update(p, v - p), h.update(p, v + p);

        cout << max(0ll, max(g.query(), h.query())) << "\n";
    }
}

int main() {
    io
    tc

    return 0;
}