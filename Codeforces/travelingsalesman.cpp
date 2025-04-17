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

    vi x (n), y (n); for (ll i = 0; i < n; i++) cin >> x[i] >> y[i];

    pii p; p.first = x[0] + y[0], p.second = p.first;

    for (ll i = 0; i < n; i++) p.first = min(p.first, x[i] + y[i]), p.second = max(p.second, x[i] + y[i]);

    cout << abs(x[0] + y[0] - p.first) + abs(x[0] + y[0] - p.second) + p.second - p.first << "\n";
}

int main() {
    io
    tc

    return 0;
}