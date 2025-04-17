#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    ll n {}; cin >> n;

    vector<ll> a (n); for (ll i {0}; i < n; ++i) cin >> a[i]; sort(a.begin(), a.end()); sort(++a.begin(), a.end(), greater<ll>());

    ll t {a[0]}, b {a[0]}, c {0};

    for (ll i {1}; i < n; ++i) {
        t = max(t, a[i]); b = min(b, a[i]);

        c += t - b;
    }

    cout << c << "\n";
}

int main() {
    io
    tc

    return 0;
}