#include <iostream>
#include <numeric>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    int l {}, r {}; cin >> l >> r;

    cout << (r - l - (l % 2 == 0) + 2) / 4 << "\n";
}

int main() {
    io
    tc

    return 0;
}