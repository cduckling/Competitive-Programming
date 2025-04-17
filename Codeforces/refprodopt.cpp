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
#define pb(i) push_back(i);
#define ceil(a, b) ((a + b - 1) / b)
#define inf 1e18

typedef long long ll;
typedef pair<ll, ll> pii;
typedef tuple<ll, ll, ll> tiii;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<set<ll>> vsi;
typedef vector<pair<ll, ll>> vpii;
typedef vector<tuple<ll, ll, ll>> vtiii;
typedef vector<bool> vb;
typedef multiset<ll> msi;
typedef set<ll> si;
typedef set<pair<ll, ll>> spii;
typedef set<tuple<ll, ll, ll>> stiii;
typedef map<ll, ll> mi;
typedef map<ll, vector<ll>> mivi;
typedef map<ll, pair<ll, ll>> mipii;
typedef map<ll, bool> mib;

ll mod = 998244353;

ll modpow(ll b, ll e) {
    b %= mod; ll r {1};
    while (e > 0) {
        if (e % 2 == 1) r = r * b % mod;

        b = b * b % mod;
        e /= 2;
    }

    return r;
}

void solve() {
    ll n, q; cin >> n >> q;

    vi a (n); for (ll i = 0; i < n; i++) cin >> a[i];
    vi b (n); for (ll i = 0; i < n; i++) cin >> b[i];

    vi aa = a, bb = b; sort(aa.begin(), aa.end()); sort(bb.begin(), bb.end());

    ll prod = 1; for (ll i = 0; i < n; i++) prod *= min(aa[i], bb[i]) % mod, prod %= mod; cout << prod << " ";

    for (ll i = 0; i < q; i++) {
        ll o, p; cin >> o >> p; p--;

        if (o == 1) {
            const ll j = upper_bound(aa.begin(), aa.end(), a[p]) - aa.begin() - 1; a[p]++;

            prod *= modpow(min(aa[j], bb[j]), mod - 2) % mod, prod %= mod; ;

            aa[j] = a[p];

            prod *= min(aa[j], bb[j]) % mod, prod %= mod;
        } else {
            const ll j = upper_bound(bb.begin(), bb.end(), b[p]) - bb.begin() - 1; b[p]++;

            prod *= modpow(min(aa[j], bb[j]), mod - 2) % mod, prod %= mod; ;

            bb[j] = b[p];

            prod *= min(aa[j], bb[j]) % mod, prod %= mod;
        }

        cout << prod << " ";
    }

    cout << "\n";
}

int main() {
    io
    tc

    return 0;
}