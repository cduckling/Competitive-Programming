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

void solve() {
    ll n {}; cin >> n;

    vi a (n + 1); for (ll i {1}; i <= n; ++i) cin >> a[i];

    vi o {}; for (ll i {2}; i <= n; ++i) o.pb(a[i] * a[i - 1]); o.pb(a[1] * a[n]); sort(o.begin(), o.end());

    ll tot = 0; for (ll i {1}; i < n; ++i) tot += o[i]; cout << tot << "\n";
}

int main() {
    io

    solve();

    return 0;
}