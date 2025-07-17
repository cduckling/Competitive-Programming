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

#define combo(a, b) ((fac[(a)] * modpow(fac[(b)], mod - 2)) % mod * modpow(fac[(a) - (b)], mod - 2) % mod)

ll mod = 998244353;

ll fac[200001];

ll modpow(ll b, ll e) {
    b %= mod; ll r = 1;

    while (e > 0) {
        if (e % 2 == 1) r = r * b % mod;

        b = b * b % mod;
        e /= 2;
    }

    return r;
}

void solve() {
    ll n; cin >> n;

    vi a (n + 1); for (ll i = 1; i <= n; i++) cin >> a[i]; sort(all(a));

    vi freq (n); for (ll i = 1; i <= n; i++) freq[a[i]]++; vi pref = freq; for (ll i = 1; i < n; i++) pref[i] = min(pref[i - 1], pref[i]);

    ll cnt = 0;

    vi least (n + 1), greater (n + 1, 1), suff (n + 1); suff[n] = 1; for (ll i = n - 1; i >= 0; i--) suff[i] = suff[i + 1] * modpow(2, freq[i]), suff[i] %= mod;

    vi select (n); for (ll i = 0; i < n; i++) for (ll j = 1; j <= freq[i]; j++) select[i] += combo(freq[i], j), select[i] %= mod;

    for (ll i = 0; i < n; i++) {
        for (ll j = 1; j <= pref[i]; j++) {
            least[j] = (least[j] * select[i]) % mod + (greater[j] * combo(freq[i], j)) % mod, least[j] %= mod;
            
            cnt += (j * suff[i + 1]) % mod * least[j], cnt %= mod;

            select[i] -= combo(freq[i], j), select[i] %= mod;
            
            greater[j] *= select[i], greater[j] %= mod;
        }
    }

    cout << (cnt + mod) % mod << "\n";
}

int main() {
    io

    fac[0] = 1; for (ll i = 1; i <= 200000; i++) fac[i] = fac[i - 1] % mod * (i % mod) % mod;

    tc

    return 0;
}