#include <iostream>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    ll l {}, r {}; cin >> l >> r;

    pair<ll, ll> llerval {0, 1000000}; while (llerval.first != llerval.second) {
        ll mid = (llerval.first + llerval.second + 1) / 2;

        if ((((mid * (mid + 1)) / 2) + l) <= r) {
            llerval.first = mid;
        } else {
            llerval.second = mid - 1;
        }
    }

    cout << llerval.first + 1 << "\n";
}

int main() {
    io
    tc

    return 0;
}