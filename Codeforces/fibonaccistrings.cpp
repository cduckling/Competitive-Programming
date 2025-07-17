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

#define fail {cout << "NO\n"; return;}

ll fib[53], pref [53];

void solve() {
    ll k; cin >> k;

    vi c (k); for (ll i = 0; i < k; i++) cin >> c[i]; sort(all(c));

    ll tot = 0; for (const ll i : c) tot += i;

    ll num = -1; for (int i = 1; i <= 52; i++) if (pref[i] == tot) {
        num = i; break;
    }

    if (num == -1) fail

    ll prev = -1;

    for (ll i = num; i >= 1; i--) {
        ll val = -1, ind = -1;

        for (ll j = 0; j < k; j++) {
            if (j == prev) continue;

            if (c[j] >= val) val = c[j], ind = j;
        }

        if (val == -1 || c[ind] < fib[i]) fail

        c[ind] -= fib[i], prev = ind;
    }

    cout << "YES\n";
}

int main() {
    io

    fib[1] = 1, fib[2] = 1; for (ll i = 3; i <= 52; i++) fib[i] = fib[i - 2] + fib[i - 1]; for (int i = 1; i <= 52; i++) pref[i] = fib[i] + pref[i - 1];

    tc

    return 0;
}