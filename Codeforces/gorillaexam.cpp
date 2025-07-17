#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

#define tc ll t; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb(i) push_back(i);
#define inf 1e18;

typedef long long ll;
typedef pair<ll, ll> pii;
typedef tuple<ll, ll, ll> tiii;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<pair<ll, ll>> vpii;
typedef vector<tuple<ll, ll, ll>> vtiii;
typedef vector<bool> vb;
typedef multiset<ll> msi;
typedef set<ll> si;
typedef map<ll, ll> mi;
typedef map<ll, vector<ll>> mvi;
typedef map<ll, pair<ll, ll>> mpii;
typedef map<ll, bool> mb;

bool s(const pii a, const pii b) {
    return b.second > a.second;
}

void solve() {
    ll n, k; cin >> n >> k;

    vi a (n); for (ll i = 0; i < n; i++) cin >> a[i];

    mi freq; for (ll i = 0; i < n; i++) freq[a[i]]++;

    ll d = freq.size(), pos = 0;

    vpii f; for (auto i : freq) f.pb(i); sort(f.begin(), f.end(), s);

    while (k > 0) {
        if (k >= f[pos].second) {
            --d; k -= f[pos].second; ++pos;
        } else {
            break;
        }
    }

    cout << max(d, 1ll) << "\n";
}

int main() {
    io
    tc

    return 0;
}