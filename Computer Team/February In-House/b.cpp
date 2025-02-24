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
typedef vector<char> vc;
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
	ll n, m, a, b; cin >> n >> m >> a >> b;

    string s; cin >> s; s = " " + s;

    vi x (n + 1); for (ll i = 1; i <= n; i++) x[i] = x[i - 1] + (s[i] == 'X');
    vi y (n + 1); for (ll i = 1; i <= n; i++) y[i] = y[i - 1] + (s[i] == 'Y');
    vi z (n + 1); for (ll i = 1; i <= n; i++) z[i] = z[i - 1] + (s[i] == 'Z');

    ll time = inf, occ = 0;
    
    for (ll i = 1; i <= n - m + 1; i++) {
        const ll T = (y[i + m - 1] - y[i - 1]) * a + (z[i + m - 1] - z[i - 1]) * b + (x[i + m - 1] - x[i - 1]);

        if (time > T) {
            time = T, occ = i;
        }
    }

    cout << time << " " << occ << "\n";
}

int main() {
    io

    solve();

    return 0;
}