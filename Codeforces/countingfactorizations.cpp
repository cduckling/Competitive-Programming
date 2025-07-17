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

#define tc ll t; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(a) (a).begin(), (a).end()
#define pb(i) push_back(i)
#define eb(i) emplace_back(i)
#define inf (ll) 1e18
#define f first
#define s second

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

#define fail {cout << 0 << "\n"; return;}

ll mod = 998244353;

bool prime[1000001];
ll fact[4045], inv[4045];

ll modpow(ll b, ll e) {
    b %= mod; ll r = 1;

    while (e > 0) {
        if (e % 2 == 1) r = r * b % mod;

        b = b * b % mod;
        e /= 2;
    }

    return r;
}

bool cmp(const pii& a, const pii& b) {
    return a.s < b.s;
}

void solve() {
    ll n; cin >> n;

    vi a (2 * n); for (ll i = 0; i < 2 * n; i++) cin >> a[i];

    mii freq; for (const ll i : a) freq[i]++;

    ll rem = fact[n]; for (const pii i : freq) if (!prime[i.f]) rem *= inv[i.s], rem %= mod;

    vpii primes; for (const pii i : freq) if (prime[i.f]) primes.pb(i); sort(all(primes), cmp); if (primes.size() < n) fail

    vvi dp (primes.size() + 1, vi (n + 1)); dp[0][0] = 1;

    for (ll i = 1; i <= primes.size(); i++) {
        const ll occ = primes[i - 1].second;

        dp[i][0] = dp[i - 1][0] * inv[occ], dp[i][0] %= mod;

        for (ll j = 1; j <= min(i, n); j++) {
            dp[i][j] = dp[i - 1][j - 1] * inv[occ - 1] % mod + dp[i - 1][j] * inv[occ] % mod, dp[i][j] %= mod;
        }
    }

    cout << (rem * dp[primes.size()][n] % mod + mod) % mod << "\n";
}

int main() {
    io

    prime[1] = true;

    for (ll i = 2; i <= 1000000; i++) {
        if (prime[i]) continue;

        for (ll j = 2 * i; j <= 1000000; j += i) prime[j] = true;
    }

    for (ll i = 1; i <= 1000000; i++) prime[i] = !prime[i];

    fact[0] = 1; for (ll i = 1; i <= 4044; i++) fact[i] = fact[i - 1] * i, fact[i] %= mod; inv[0] = 1; for (int i = 1; i <= 4044; i++) inv[i] = modpow(fact[i], mod - 2);

    solve();

    return 0;
}