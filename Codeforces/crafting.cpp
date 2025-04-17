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

    vi a (n); for (ll i = 0; i < n; i++) cin >> a[i];
    vi b (n); for (ll i = 0; i < n; i++) cin >> b[i];

    ll del = 0, pos = -1;

    for (ll i = 0; i < n; i++) {
        if (a[i] >= b[i]) continue;

        del = b[i] - a[i], pos = i; break;
    }

    if (pos == -1) {
        cout << "YES\n"; return;
    }

    for (ll i = 0; i < n; i++) {
        if (i == pos) {
            a[i] += del; continue;
        }

        a[i] -= del;
    }

    for (ll i = 0; i < n; i++) if (b[i] > a[i]) {
        cout << "NO\n"; return;
    }

    cout << "YES\n";
}

int main() {
    io
    tc

    return 0;
}