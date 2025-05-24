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

bool p[10000001];
ll g[10000001];

void solve() {
    ll n; cin >> n;

    vi a (n); for (ll i = 0; i < n; i++) cin >> a[i];

    vi p (n); for (ll i = 0; i < n; i++) {
        for (ll div = 2; div * div <= a[i]; div++) if (a[i] % div == 0) {
            p[i] = div; break;
        }

        if (p[i] == 0) p[i] = a[i];
    }

    ll sum = 0; for (const ll i : p) {
        if (i == 1) {
            sum ^= 1;
        } else if (i % 2 != 0) {
            sum ^= g[i] + 1;
        }
    }

    cout << (sum == 0 ? "Bob" : "Alice") << "\n";
}

int main() {
    io

    ll cnt = 0;

    for (ll i = 2; i <= 10000000; i++) {
        if (p[i] == true) continue;

        g[i] = cnt++; for (ll j = i * 2; j <= 10000000; j += i) p[j] = true;
    }

    tc

    return 0;
}
