#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

#define tc ll t; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(a) (a).begin(), (a).end()
#define pb(a) push_back(a)
#define eb(a, b) emplace_back(a, b)
#define inf (ll) 1e18
#define fir first
#define sec second

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
typedef vector<char> vc;
typedef vector<vector<char>> vvc;

bool bad[31][30][31];

void solve() {
    ll n, k, mod; cin >> n >> k >> mod;

    ll cnt = 1; for (ll i = 1; i <= n; i++) cnt *= k, cnt %= mod;

    for (ll s = 0; s < k; s++) {
        vvi dp (n + 1, vi (k)); dp[0][0] = 1; for (ll i = 1; i <= n; i++) for (ll j = 0; j < k; j++) for (ll val = 1; val <= k; val++) if (!bad[k][s][val]) dp[i][j] += dp[i - 1][(j - val + k) % k], dp[i][j] %= mod; cnt -= dp[n][s], cnt %= mod;
    }

    cout << (cnt + mod) % mod << "\n";
}

int main() {
    io

    for (ll i = 1; i <= 30; i++) for (ll j = 0; j < i; j++) for (ll k = 1; k <= i; k++) if (2 * k % i == j) bad[i][j][k] = true;

    solve();

    return 0;
}