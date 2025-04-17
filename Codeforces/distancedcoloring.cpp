#include <iostream>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    int n {}, m {}, k {}; cin >> n >> m >> k;

    if (n >= k && m >= k) {
        cout << k * k << "\n";
    } else if (n >= k || m >= k) {
        cout << k * min(n, m) << "\n";
    } else {
        cout << n * m << "\n";
    }
}

int main() {
    io
    tc

    return 0;
}