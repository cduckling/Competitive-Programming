#include <iostream>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    ll x {}, n {}; cin >> n >> x;

    ll t {0};

    for (int a {1}; a <= x - 2; ++a) {
        for (int b {1}; b <= min(x - a - 1, (n - 2) / a); ++b) t += min(x - a - b, (n - a * b) / (b + a));
    }

    cout << t << "\n";
}

int main() {
    io
    tc

    return 0;
}