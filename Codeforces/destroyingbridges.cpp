#include <iostream>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    int n {}, k {}; cin >> n >> k;

    if (k >= n - 1) {
        cout << 1 << "\n";
    } else {
        cout << n << "\n";
    }
}

int main() {
    io
    tc

    return 0;
}