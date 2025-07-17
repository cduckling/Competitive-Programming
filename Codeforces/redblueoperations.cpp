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

bool check(const ll n, ll k, const ll mid, vi a) {
    ll over = 0; for (ll i = 1; i < n; i++) {
        if (k) a[i] += k, k--; if (a[i] < mid) return false; over += a[i] - mid;
    }

    if (k % 2 != 0) a[n] += k, k--; if (a[n] < mid) return false; over += a[n] - mid;

    return over >= k / 2;
}

void solve() {
    ll n, q; cin >> n >> q;

    vi a (n + 1); for (ll i = 1; i <= n; i++) cin >> a[i]; sort(all(a));

    while (q--) {
        ll k; cin >> k;

        if (n == 1 & k % 2 == 0) {
            cout << a[1] - k / 2 << " "; continue;
        }

        pii r = {a[1], inf};

        while (r.fir != r.sec) {
            const ll mid = (r.fir + r.sec + 1) / 2;

            if (check(n, k, mid, a)) {
                r.fir = mid;
            } else {
                r.sec = mid - 1;
            }
        }

        cout << r.fir << " ";
    }
}

int main() {
    io

    solve();

    return 0;
}