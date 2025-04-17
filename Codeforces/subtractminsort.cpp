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
#define all(a) (a).begin(), (a).end()
#define pb(i) push_back(i);
#define inf 1e18;

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
    ll n; cin >> n;

    vi a (n); for (ll i = 0; i < n; i++) cin >> a[i]; if (n == 1) {
        cout << "YES\n"; return;
    }

    for (ll i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            cout << "NO\n"; return;
        }

        const ll val = min(a[i], a[i + 1]); a[i] -= val, a[i + 1] -= val;
    }

    cout << "YES\n";
}

int main() {
    io
    tc

    return 0;
}