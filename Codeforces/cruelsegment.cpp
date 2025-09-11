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
#define eb(a, b) emplace_back((a), (b))
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

void solve() {
    ll n; cin >> n;

    vpii lr (n + 1); for (ll i = 1; i <= n; i++) cin >> lr[i].fir >> lr[i].sec;

    ll sum = 0; for (ll i = 1; i <= n; i++) sum += lr[i].sec - lr[i].fir;

    ll res = -1e9;

    if (n % 2 == 0) {
        ll bad = 0; for (ll i = 1; i <= n; i++) bad += -lr[i].fir;

        vi good; for (ll i = 1; i <= n; i++) good.pb(lr[i].fir + lr[i].sec); sort(all(good), greater<ll>());

        res = bad; for (ll i = 0; i < n / 2; i++) res += good[i];
    } else {
        ll bad = 0; for (ll i = 1; i <= n; i++) bad += -lr[i].fir;

        vpii good; for (ll i = 1; i <= n; i++) good.eb(lr[i].fir + lr[i].sec, i); sort(all(good), greater<pii>());
        ll best = 0; si pos; for (ll i = 0; i < n / 2; i++) pos.insert(good[i].sec), best += good[i].fir;

        const ll val = good[n / 2].fir;

        for (ll i = 1; i <= n; i++) {
            bad += lr[i].fir;

            res = max(res, bad + best + (pos.count(i) ? - lr[i].fir - lr[i].sec + val : 0));

            bad -= lr[i].fir;
        }
    }

    cout << sum + res << "\n";
}

int main() {
    io
    tc

    return 0;
}