#include <iostream>
#include <cmath>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    ll r {}; cin >> r;

    ll p {0};

    for (ll i {1}; i <= r; ++i) {
        ll a {static_cast<ll>(ceil(sqrt(r * r - i * i + 0.0)))}, b {static_cast<ll>(floor(sqrt((r + 1) * (r + 1) - i * i + 0.0)))};

        if ((b * b + i * i) == (r + 1) * (r + 1)) --b;

        p += b - a + 1;
    }

    cout << p * 4 << "\n";
}

int main() {
    io
    tc

    return 0;
}