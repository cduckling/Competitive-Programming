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

#define tc ll t {}; cin >> t; while (t--) solve();
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

bool equal(const vi& a) {
    for (ll i = 1; i < a.size(); i++) if (a[i] != a[i - 1]) return false; return true;
}

bool sign(const vi& a) {
    for (ll i = 1; i < a.size(); i++) {
        ll u = 0, v = 0;

        if (a[i] > 0) {
            u = 2;
        } else if (a[i] == 0) {
            u = 1;
        }

        if (a[i - 1] > 0) {
            v = 2;
        } else if (a[i - 1] == 0) {
            v = 1;
        }

        if (u != v) return false;
    }

    return true;
}

void solve() {
    ll n, k; cin >> n >> k;

    vi a (n); for (ll i = 0; i < n; i++) cin >> a[i]; for (ll i = 0; i < n; i++) a[i] -= k; sort(a.begin(), a.end());

    if (equal(a)) {
        cout << 0 << "\n"; return;
    } if (!sign(a)) {
        cout << -1 << "\n"; return;
    }

    for (ll i = 0; i < n; i++) a[i] = abs(a[i]);

    ll c = a[0]; for (const ll i : a) c = gcd(c, i);

    ll p = 0; for (const ll i : a) p += (i / c) - 1; cout << p << "\n";
}

int main() {
    io
    tc

    return 0;
}