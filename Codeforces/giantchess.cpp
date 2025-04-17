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
#define inf (ll) 1e18
#define fail cout << -1 << "\n"; return;

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
typedef set<ll> si;
typedef vector<set<ll>> vsi;
typedef vector<vector<set<ll>>> vvsi;
typedef map<ll, ll> mii;
typedef map<ll, bool> mib;
typedef map<ll, double> mid;
typedef vector<map<ll, ll>> vmii;
typedef vector<map<ll, double>> vmid;
typedef vector<map<ll, bool>> vmib;

ll mod = 1e9 + 7;

ll fac[1000001];
ll inv[1000001];

ll combo(const ll a, const ll b) {
    return ((fac[a] * inv[b]) % mod *  inv[a - b]) % mod;
}

void solve() {
    ll h, w, n; cin >> h >> w >> n;

    vpii rc (n); for (ll i = 0; i < n; i++) cin >> rc[i].first >> rc[i].second; rc.emplace_back(h, w); sort(rc.begin(), rc.end());

    vi dp (n + 1); for (ll i = 0; i <= n; i++) {
        dp[i] = combo(rc[i].first + rc[i].second - 2, rc[i].first - 1);

        for (ll j = 0; j < i; j++) if (rc[j].first <= rc[i].first && rc[j].second <= rc[i].second) dp[i] -= dp[j] * combo(rc[i].first + rc[i].second - rc[j].first - rc[j].second, rc[i].first - rc[j].first), dp[i] %= mod;
    }

    cout << (dp[n] + mod) % mod << "\n";
}

ll inverse(const ll x) {
    return x <= 1 ? x : mod - mod / x * inverse(mod % x) % mod;
}

int main() {
    io

    fac[0] = 1; for (ll i = 1; i <= 1000000; i++) fac[i] = ((fac[i - 1] % mod) * (i % mod)) % mod;
    inv[0] = 1, inv[1] = 1; for (ll i = 2; i <= 1000000; i++) inv[i] = ((inv[i - 1] % mod) * (inverse(i) % mod)) % mod;

    solve();

    return 0;
}