#include <iostream>
#include <cmath>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    ll n {}, k {}; cin >> n >> k;

    if (k == 1) {
        cout << n << "\n";
    } else {
        ll o = 0;

        while (n > 0) {
            o += n % k; n /= k;
        }

        cout << o << "\n";
    }
}

int main() {
    io
    tc

    return 0;
}