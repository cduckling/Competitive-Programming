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
    ll n, m, x; cin >> n >> m >> x;

    vi d (n); for (ll i = 0; i < n; i++) cin >> d[i];

    mii freq; for (const ll i : d) freq[i % m]++;

    vi opt; for (const pii i : freq) opt.pb(i.second); sort(all(opt), greater<ll>());

    int tot = 0;

    for (ll i = 0; i < min(x, (ll) opt.size()); i++) {
        tot += opt[i];
    }

    cout << tot << "\n";
}

int main() {
    io

    solve();

    return 0;
}