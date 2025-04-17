#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    ll n {}, x {}; cin >> n >> x;

    ll t {0}; vector<ll> a (n); for (ll i {0}; i < n; ++i) {
        cin >> a[i]; t += a[i];
    } sort(a.begin(), a.end());

    cout << max((t + x - 1) / x, a[n - 1]) << "\n";
}

int main() {
    io
    tc

    return 0;
}