#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    ll n {}, m {}; cin >> n >> m;

    vector<ll> a (n); for (ll i {0}; i < n; ++i) cin >> a[i]; sort(a.begin(), a.end());

    for (int i {0}; i < m; ++i) {
        char o {}; ll l {}, r {}; cin >> o >> l >> r;

        if (l <= a[n - 1] && a[n - 1] <= r) {
            a[n - 1] += (o == '+'); a[n - 1] -= (o == '-');
        }

        cout << a[n - 1] << " ";
    }

    cout << "\n";
}

int main() {
    io
    tc

    return 0;
}