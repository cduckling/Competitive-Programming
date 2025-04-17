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
#define pb(i) push_back(i)
#define eb(i) emplace_back(i)
#define ceil(a, b) ((a + b - 1) / b)
#define inf 1e18
#define fail cout << -1 << "\n"; return;

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
typedef map<ll, ll> mii;
typedef map<ll, vector<ll>> mivi;
typedef map<ll, pair<ll, ll>> mipii;
typedef map<ll, set<ll>> misi;
typedef map<ll, bool> mib;

void solve() {
    ll n, m; cin >> n >> m;

    vvi a (n + 2, vi (m + 2, -1)); for (ll i = 1; i <= n; i++) for (ll j = 1; j <= m; j++) cin >> a[i][j];

    mii freq; for (ll i = 1; i <= n; i++) for (ll j = 1; j <= m; j++) {
        freq[a[i][j]] = max(1ll, freq[a[i][j]]);
        if (a[i][j] == a[i - 1][j] || a[i][j] == a[i][j - 1] || a[i][j] == a[i + 1][j] || a[i][j] == a[i][j + 1]) freq[a[i][j]] = 2;
    }

    vi col; for (const pii i : freq) col.pb(max(1ll, i.second)); sort(col.begin(), col.end());

    ll tot = 0; for (const ll i : col) tot += i;

    ll val = 0; if (col.size() > 0) val = col[col.size() - 1];

    cout << tot - val << "\n";
}

int main() {
    io
    tc

    return 0;
}