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

void path(const ll n, const ll m, const string& s, vi& r, vi& c, vvi& a) {
    pii pos = {0, 0};

    if (s[0] == 'D') {
        a[0][0] = 0 - r[0];
    } else {
        a[0][0] = 0 - c[0];
    }

    r[0] += a[0][0], c[0] += a[0][0];

    for (ll i = 0; i < s.size() - 1; i++) {
        if (s[i] == 'D') {
            pos.first++;

            if (s[i + 1] == 'R') {
                a[pos.first][pos.second] = 0 - c[pos.second];
            } else {
                a[pos.first][pos.second] = 0 - r[pos.first];
            }

            r[pos.first] += a[pos.first][pos.second], c[pos.second] += a[pos.first][pos.second];

        } else {
            pos.second++;

            if (s[i + 1] == 'D') {
                a[pos.first][pos.second] = 0 - r[pos.first];
            } else {
                a[pos.first][pos.second] = 0 - c[pos.second];
            }

            r[pos.first] += a[pos.first][pos.second], c[pos.second] += a[pos.first][pos.second];
        }
    }

    if (s[s.size() - 1] == 'D') {
        a[n - 1][m - 1] = 0 - r[n - 1];
    } else {
        a[n - 1][m - 1] = 0 - c[m - 1];
    }
}

void solve() {
    ll n, m; cin >> n >> m;

    string s; cin >> s;

    vvi a (n, vi (m)); for (ll i = 0; i < n; i++) for (ll j = 0; j < m; j++) cin >> a[i][j];

    vi r (n); for (ll i = 0; i < n; i++) for (ll j = 0; j < m; j++) r[i] += a[i][j];

    vi c (m); for (ll i = 0; i < m; i++) for (ll j = 0; j < n; j++) c[i] += a[j][i];

    path(n, m, s, r, c, a);

    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) cout << a[i][j] << " "; cout << "\n";
    }
}

int main() {
    io
    tc

    return 0;
}