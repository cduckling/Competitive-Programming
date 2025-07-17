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

void solve() {
    ll n, l, r; cin >> n >> l >> r;

    vi a (n + 1); for (ll i = 1; i <= n; i++) cin >> a[i];

    vi left, center, right; for (ll i = 1; i < l; i++) left.pb(a[i]); for (ll i = l; i <= r; i++) center.pb(a[i]); for (ll i = r + 1; i <= n; i++) right.pb(a[i]); sort(left.begin(), left.end()); sort(center.begin(), center.end(), greater<ll>()); sort(right.begin(), right.end());

    for (ll i = 1; i < left.size(); i++) left[i] += left[i - 1]; for (ll i = 1; i < right.size(); i++) right[i] += right[i - 1]; for (ll i = 1; i < center.size(); i++) center[i] += center[i - 1];

    ll lll = 0, rrr = 0;

    for (ll i = 0; i < center.size(); i++) {
        if (i < left.size()) lll = min(lll, left[i] - center[i]);

        if (i < right.size()) rrr = min(rrr, right[i] - center[i]);
    }

    cout << center[center.size() - 1] + min(lll, rrr) << "\n";
}

int main() {
    io
    tc

    return 0;
}