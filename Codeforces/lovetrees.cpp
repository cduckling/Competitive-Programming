#include <iostream>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    int n {}; cin >> n;

    if (n % 2 == 0) {
        for (int i {0}; i < n - 2; ++i) cout << 3; cout << 66; cout << "\n";
    } else {
        if (n <= 3) {
            cout << -1 << "\n";
        } else {
            for (int i {0}; i < n - 4; ++i) cout << 3; cout << 6366; cout << "\n";
        }
    }
}

int main() {
    io
    tc

    return 0;
}