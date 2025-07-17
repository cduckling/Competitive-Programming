#include <iostream>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    ll n {}, k {}; cin >> n >> k;

    ll leaves = ((n * (n + 1)) / 2) - (((n - k) * (n - k + 1)) / 2);
    if (leaves % 2 == 0) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    io
    tc

    return 0;
}