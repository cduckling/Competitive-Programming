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

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef set<ll> si;
typedef map<ll, ll> mii;
typedef map<ll, vector<ll>> miv;

void solve() {
    ll n {}; cin >> n;

    vi a (n); for (ll i {0}; i < n; ++i) cin >> a[i];
    vi b (n); for (ll i {0}; i < n; ++i) cin >> b[i];

    mii m {}; ++m[a[0] - b[0]];

    vi dp (n); for (ll i {1}; i < n; ++i) {
        dp[i] = dp[i - 1] + (i - m[a[i] - b[i]]);
        ++m[a[i] - b[i]];
    }

    cout << dp[n - 1];
}

int main() {
    io

    solve();

    return 0;
}