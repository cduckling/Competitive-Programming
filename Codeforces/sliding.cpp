#include <iostream>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    ll n {}, m {}, r {}, c {}; cin >> n >> m >> r >> c;

    cout << - max(0ll, n - (((r - 1) * m + c) + m - 1) / m) + max(0LL, n - (((r - 1) * m + c) + m - 1) / m) * m + n * m - ((r - 1) * m + c) << "\n";
}

int main() {
    io
    tc

    return 0;
}