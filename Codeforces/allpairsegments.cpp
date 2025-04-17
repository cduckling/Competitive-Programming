#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    ll n {}, q {}; cin >> n >> q;

    vector<ll> a (n); for (ll i {0}; i < n; ++i) cin >> a[i]; sort(a.begin(), a.end());

    vector<ll> p (n - 1); for (ll i {0}; i < n - 1; ++i) p[i] = (1 + i) * (n - i - 1);

    map<ll, ll> m {}; for (ll i {0}; i < n - 1; ++i) m[p[i]] += a[i + 1] - a[i] - 1;
    for (int i {0}; i < n; ++i) ++m[(i + 1) * (n - i - 1) + (i)];

    for (ll i {0}; i < q; ++i) {
        ll k {}; cin >> k;
        cout << m[k] << " ";
    }

    cout << "\n";
}

int main() {
    io
    tc

    return 0;
}