#include <iostream>
using namespace std;

#define fail cout << -1 << "\n"; return;
#define ceil(a, b) ((a + b - 1) / b)

typedef long long ll;

void solve() {
    ll a, b, c, d; cin >> a >> b >> c >> d; if (a > c || b > d) {
        cout << -1 << "\n"; return;
    }

    ll ops = 0;

    while (d != c && c >= a && d >= b) {
        ops += ceil(max(c, d) - min(c, d), min(c, d));

        if (d > c) {
            d -= c * ceil(d - c, c);
        } else {
            c -= d * ceil(c - d, d);
        }
    }

    if (a == c && b == d) {
        cout << ops << "\n";
    } else if (a != c && b != d) {
        fail
    } else {
        if (a == c && b > d) {
            ops -= (b - d) / c;
            d += (b - d) / c * c;
        } else if (b == d && a > c) {
            ops -= (a - c) / d;
            c += (a - c) / d * d;
        }

        if (a == c && b == d) {
            cout << ops << "\n";
        } else {
            fail
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t; while (t--) solve();

    return 0;
}