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
#define fail cout << -1 << "\n"; return;
#define inf (ll) 1e18

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<vector<vector<ll>>> vvvi;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<vector<vector<double>>> vvvd;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef pair<ll, ll> pii;
typedef vector<pair<ll, ll>> vpii;
typedef vector<vector<pair<ll, ll>>> vvpii;
typedef vector<vector<vector<pair<ll, ll>>>> vvvpii;
typedef tuple<ll, ll, ll> tiii;
typedef vector<tuple<ll, ll, ll>> vtiii;
typedef vector<vector<tuple<ll, ll, ll>>> vvtiii;
typedef vector<vector<vector<tuple<ll, ll, ll>>>> vvvtiii;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef set<ll> si;
typedef vector<set<ll>> vsi;
typedef vector<vector<set<ll>>> vvsi;
typedef set<pair<ll, ll>> spii;
typedef vector<set<pair<ll, ll>>> vspii;
typedef map<ll, ll> mii;
typedef map<ll, bool> mib;
typedef map<ll, double> mid;
typedef vector<map<ll, ll>> vmii;
typedef vector<map<ll, double>> vmid;
typedef vector<map<ll, bool>> vmib;

ll mod = 1e9 + 7;

void solve() {
    ll n, k, q; cin >> n >> k >> q;

    vi a (n + 1); for (ll i = 1; i <= n; i++) cin >> a[i], a[i] %= mod;

    vvi dp (n + 2, vi (k + 1)); for (ll i = 1; i <= n; i++) dp[i][0] = 1;

    for (ll j = 1; j <= k; j++) for (ll i = 1; i <= n; i++) dp[i][j] = dp[i - 1][j - 1] + dp[i + 1][j - 1], dp[i][j] %= mod;

    vi cnt (n + 1); for (ll i = 1; i <= n; i++) for (ll j = 0; j <= k; j++) cnt[i] += dp[i][j] * dp[i][k - j], cnt[i] %= mod;

    ll sum = 0; for (ll i = 1; i <= n; i++) sum += a[i] * cnt[i], sum %= mod;

    for (ll i = 0; i < q; i++) {
        ll p, v; cin >> p >> v;

        sum -= cnt[p] * a[p], sum %= mod;
        a[p] = v, a[p] %= mod;
        sum += cnt[p] * a[p], sum %= mod;

        cout << (sum + mod) % mod<< "\n";
    }
}

int main() {
    io

    solve();

    return 0;
}