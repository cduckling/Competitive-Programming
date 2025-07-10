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

#define discount(s, k, x) (((s) + 5 * (x)) * ((k) - (x)))

void solve() {
    ll s, k; cin >> s >> k;

    ll d = -1;

    if (s % 10 == 0) {
        cout << s * k << "\n"; return;
    } if (s % 5 == 0) {
        cout << max(s * k, (s + 5) * (k - 1)) << "\n"; return;
    }

    while (k > 0 && s % 10 != 2) d = max(d, s * k), s += s % 10, k--;

    for (ll i = 0 ; i < 4; i++) {
        if (!k) break;

        pii r = {0, k / 4};

        while (r.fir < r.sec) {
            const ll mid = (r.fir + r.sec) / 2;

            if (discount(s, k, mid * 4) < discount(s, k, mid * 4 + 4)) {
                r.fir = mid + 1;
            } else {
                r.sec = mid;
            }
        }

        d = max(d, (s + 5 * 4 * r.fir) * (k - 4 * r.fir));

        s += s % 10, k--;
    }

    cout << d << "\n";
}

int main() {
    io
    tc

    return 0;
}