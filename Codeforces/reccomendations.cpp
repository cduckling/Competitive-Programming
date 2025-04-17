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

#define tc ll t {}; cin >> t; while (t--) solve();
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

bool L(const tiii& a, const tiii& b) {
    if (get<0>(a) == get<0>(b)) return get<1>(a) > get<1>(b);
    return get<0>(a) < get<0>(b);
}
bool R(const tiii& a, const tiii& b) {
    if (get<1>(a) == get<1>(b)) return get<0>(a) < get<0>(b);
    return get<1>(a) > get<1>(b);
}

void solve() {
    ll n {}; cin >> n;

    vpii lr (n); map<pii, ll> m {}; for (ll i {0}; i < n; ++i) {
        cin >> lr[i].first >> lr[i].second; ++m[lr[i]];
    }

    vpii rec (n);

    vtiii l (n), r (n); for (ll i {0}; i < n; ++i) l[i] = make_tuple(lr[i].first, lr[i].second, i), r[i] = l[i]; stable_sort(l.begin(), l.end(), L), stable_sort(r.begin(), r.end(), R);

    si ms {}; for (ll i {0}; i < n; ++i) {
        auto j = ms.lower_bound(get<1>(l[i]));

        if (j != ms.end()) rec[get<2>(l[i])].second = *j;

        ms.insert(get<1>(l[i]));
    } ms.clear(); for (ll i {0}; i < n; ++i) {
        auto j = ms.upper_bound(get<0>(r[i]));

        if (j != ms.begin()) rec[get<2>(r[i])].first = *(--j);

        ms.insert(get<0>(r[i]));
    }

    for (ll i {0}; i < n; ++i) if (!rec[i].first || !rec[i].second || m[lr[i]] > 1) {
        cout << 0 << "\n";
    } else {
        cout << rec[i].second - rec[i].first -(lr[i].second - lr[i].first) << "\n";
    }
}

int main() {
    io
    tc

    return 0;
}