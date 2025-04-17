#include <iostream>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    ll a {}, b {}; cin >> a >> b;

    if (a >= b) {
        cout << a << "\n";
    } else {
        cout << max(0ll, 2 * a - b) << "\n";
    }
}

int main() {
    io
    tc

    return 0;
}