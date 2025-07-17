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

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef set<ll> si;
typedef map<ll, ll> mii;
typedef map<ll, vector<ll>> miv;

ll div(ll n) {
    ll s {0};

    for (ll i {1}; i <= sqrt(n); ++i) {
        if (n % i != 0) continue;

        if (i != n / i) {
            s += i + n / i;
        } else {
            s += i;
        }
    }
    
    return s;
}

void solve() {
    ll n {}; cin >> n;

    vi a (n); for (ll i {0}; i < n; ++i) cin >> a[i];

    vi d (n); for (ll i {0}; i < n; ++i) d[i] = div(a[i]);

    map<ll, vi> m {}; for (ll i {0}; i < n; ++i) m[a[i]].push_back(i);

    int p {0};

    for (ll i {0}; i < n; ++i) {
        int j = upper_bound(m[d[i]].begin(), m[d[i]].end(), i) - m[d[i]].begin();

        p += m[d[i]].size() - (j);
    }

    cout << p << "\n";
}

int main() {
    io

    solve();

    return 0;
}