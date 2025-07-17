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

void solve() {
    ll n; cin >> n;

    vi a (n + 1); for (ll i = 1; i <= n; i++) cin >> a[i];

    vpii blx; for (ll i = 1; i <= n; i++) {
        ll p = i; while (p + 1 <= n && a[p + 1] == a[i]) p++; blx.eb(i, p); i = p;
    }

    ll cost = inf;

    for (ll i = 1; i < blx.size() - 1; i++) cost = min(cost, (blx[i].fir - 1) * a[blx[i].fir] + (n - blx[i].sec) * a[blx[i].sec]);

    cost = min(cost, (n - blx[0].sec) * a[1]), cost = min(cost, (blx[blx.size() - 1].fir - 1) * a[n]);

    cout << cost << "\n";
}

int main() {
    io
    tc

    return 0;
}