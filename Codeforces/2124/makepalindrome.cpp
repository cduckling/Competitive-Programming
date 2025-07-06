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

ll palindrome(const ll rem, const vi& b) {
    pii r = {0, b.size() - 1};

    int ops = 0;

    while (r.fir < r.sec) {
        if (b[r.fir] == b[r.sec]) {
            r.fir++, r.sec--;
        } else if (b[r.fir] == rem) {
            r.fir++, ops++;
        } else if (b[r.sec] == rem) {
            r.sec--, ops++;
        } else {
            return inf;
        }
    }

    return ops;
}

void solve() {
    ll n, k; cin >> n >> k;

    vi a (n + 1); for (ll i = 1; i <= n; i++) cin >> a[i];

    vi cnt (n + 1); for (ll i = 1; i <= n; i++) cnt[a[i]]++; for (ll i = 1; i <= n; i++) cnt[i] = cnt[i - 1] + cnt[i];

    vi del (n + 1); for (ll i = 1; i <= n; i++) for (ll j = 1; j <= cnt[i] - cnt[i - 1]; j++) if (cnt[i] - j + 1 >= k) del[i]++;

    si kill; for (ll i = 1; i <= n; i++) if (del[i] == cnt[i] - cnt[i - 1]) kill.insert(i), del[i] = 0;

    vi b; for (ll i = 1; i <= n; i++) if (!kill.count(a[i])) b.pb(a[i]);

    pii rem; for (ll i = 1; i <= n; i++) if (del[i]) rem = {i, del[i]};

    cout << (palindrome(rem.fir, b) <= rem.sec ? "YES" : "NO") << "\n";
}

int main() {
    io
    tc

    return 0;
}