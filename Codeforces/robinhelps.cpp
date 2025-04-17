#include <iostream>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    ll n {}, k {}; cin >> n >> k;

    ll r = 0, p = 0;

    for (ll i {0}; i < n; ++i) {
        ll g {}; cin >> g;

        if (g >= k) r += g;
        if (g == 0 && r > 0) {
            --r;
            ++p;
        }
    }

    cout << p << "\n";
}

int main() {
    io
    tc

    return 0;
}