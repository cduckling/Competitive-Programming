#include <iostream>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<ll, ll> pii;

ll path(const ll n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}

void solve() {
    ll l {}, r {}, i {}, k {}; cin >> l >> r >> i >> k;

    pii range {};

    const ll a = (l - k + (1LL << i) - 1), b = (1LL << i), c = (r - k), d = (1LL << i);

    range.first = a / b - ((a % b != 0) && ((b > 0 && a % b < 0) || (b < 0 && a % b > 0)));
    range.second = c / d - ((c % d != 0) && ((d > 0 && c % d < 0) || (d < 0 && c % d > 0)));

    ll v {0}; if (range.first <= range.second) v = ((range.second - range.first + 1) % 2 ? k : 0) ^ ((path(range.second) ^ path(range.first - 1)) << i);
    
    cout << (path(r) ^ path(l - 1) ^ v) << "\n";
}

int main() {
    io
    tc

    return 0;
}