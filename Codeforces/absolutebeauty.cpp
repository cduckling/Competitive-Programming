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
typedef set<pair<ll, ll>> spii;
typedef set<tuple<ll, ll, ll>> stiii;
typedef map<ll, ll> mi;
typedef map<ll, vector<ll>> mivi;
typedef map<ll, pair<ll, ll>> mipii;
typedef map<ll, bool> mib;

void solve() {
    ll n; cin >> n;

    vi a (n + 1); for (ll i = 1; i <= n; i++) cin >> a[i];
    vi b (n + 1); for (ll i = 1; i <= n; i++) cin >> b[i];

    for (ll i = 1; i <= n; i++) if (b[i] == max(a[i], b[i])) swap(a[i], b[i]);

    ll up = b[1], low = a[1], d = 0;

    for (ll i = 2; i <= n; i++) {
        if (up > a[i]) d = max(d, up - a[i]);

        if (low < b[i]) d = max(d, b[i] - low);

        up = max(up, b[i]), low = min(low, a[i]);
    }

    d *= 2; for (ll i = 1; i <= n; i++) d += abs(a[i] - b[i]);

    cout << d << "\n";
}

int main() {
    io
    tc

    return 0;
}