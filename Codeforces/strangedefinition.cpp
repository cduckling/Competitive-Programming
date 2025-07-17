#include <iostream>
#include <vector>
#include <set>
#include <map>
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

vi p[1000001];

void solve() {
    ll n; cin >> n;

    vi a (n); for (ll i = 0; i < n; i++) cin >> a[i];

    vi rem (n, 1); for (ll i = 0; i < n; i++) {
        for (const ll j : p[a[i]]) {
            ll cnt = 0, rep = a[i];

            while (rep % j == 0) rep /= j, cnt++;

            if (cnt % 2 != 0) rem[i] *= j;
        }
    }

    mii freq; for (const ll i : rem) freq[i]++;

    vi even, odd; for (const pii i : freq) (i.second % 2 == 0 || i.first == 1 ? even : odd).pb(i.second);

    ll zero = 0; for (const ll i : even) zero = max(zero, i); for (const ll i : odd) zero = max(zero, i);
    ll one = 0; for (const ll i : even) one += i; for (const ll i : odd) one = max(one, i);

    ll q; cin >> q;

    for (ll i = 0; i < q; i++) {
        ll w; cin >> w;

        cout << (w > 0 ? one : zero) << "\n";
    }
}

int main() {
    io

    for (ll i = 2; i <= 1000000; i++) if (p[i].empty()) for (ll j = i; j <= 1000000; j += i) p[j].pb(i);

    tc

    return 0;
}