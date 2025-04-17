#include <iostream>
#include <vector>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<ll, ll> pii;

ll n {};

vector<ll> a (300001);
vector<ll> b (300001);
vector<ll> c (300001);
vector<ll> d (300001);
vector<ll> e (300001);

pii op(ll p) {
    pair<ll, ll> r {1, n};

    while (r.first != r.second) {
        ll mid = (r.first + r.second + 1) / 2;

        if (b[mid - 1] < p) {
            r.first = mid;
        } else {
            r.second = mid - 1;
        }
    }

    return {r.first, p - b[r.first - 1]};
}

ll pref(pii o) {
    if (o.second == 0) return d[o.first - 1];

    return d[o.first] - (c[n] - c[o.first + o.second - 1]) - ((n - o.first + 1) - (o.second)) * (e[o.first + o.second - 1] - e[o.first - 1]);
}

void solve() {
    cin >> n;

    for (ll i {1}; i <= n; ++i) cin >> a[i];
    for (ll i {1}; i <= n; ++i) b[i] = (n - i + 1) + b[i - 1];
    for (ll i {1}; i <= n; ++i) c[i] = (n - i + 1) * a[i] + c[i - 1];
    for (ll i {1}; i <= n; ++i) d[i] = c[n] - c[i - 1] + d[i - 1];
    for (ll i {1}; i <= n; ++i) e[i] = a[i] + e[i - 1];
    
    ll q {}; cin >> q;

    while (q--) {
        ll l {}, r {}; cin >> l >> r;

        pii f = op(l); --f.second;

        cout << pref(op(r)) - pref(f) << "\n";
    }
}

int main() {
    io

    solve();

    return 0;
}