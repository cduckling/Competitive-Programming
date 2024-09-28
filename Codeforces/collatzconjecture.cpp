#include <iostream>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    ll x {}, y {}, k {}; cin >> x >> y >> k;

    if (x % y == 0) {
        ++x; --k;
    }

    while (x != 1) {
        const ll s {y - x % y};

        if (s > k) {
            x += k; k = 0; break;
        }

        k -= s; x += s; while (x % y == 0) {
            x /= y;
        }
    }

    if (k != 0) {
        x += k % (y - 1);
    }

    cout << x << "\n";
}

int main() {
    io
    tc

    return 0;
}