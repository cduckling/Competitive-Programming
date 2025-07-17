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

ll s(const ll k, const ll b, const ll x, const vi& c) {
    ll p = 0;

    for (const ll i : c) {
        const ll r = i % k, e = i / k;

        p += k * e * (k - 1) * e / 2 + r * (r - 1) / 2 + r * (k - 1) * e;
    }

    return p * b - (k - 1) * x;
}

void solve() {
    ll n, b, x; cin >> n >> b >> x;

    vi c (n); for (ll i = 0; i < n; i++) cin >> c[i]; sort(c.begin(), c.end());

    pii r {2, c[n - 1]};

    while (r.first < r.second) {
        const ll mid = (r.first + r.second + 1) / 2;

        if (s(mid - 1, b, x, c) < s(mid, b, x, c)) {
            r.first = mid;
        } else {
            r.second = mid - 1;
        }
    }

    cout << max(0ll, s(r.first, b, x, c)) << "\n";
}

int main() {
    io
    tc

    return 0;
}