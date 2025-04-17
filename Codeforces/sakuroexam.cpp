#include <iostream>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    int a {}, b {}; cin >> a >> b;

    for (int i {0}; i <= a; ++i) {
        for (int j {0}; j <= b; ++j) {
            if ((i + 2 * j - (a - i) - 2 * (b - j)) == 0) {
                cout << "YES\n"; return;
            }
        }
    }

    cout << "NO\n";
}

int main() {
    io
    tc

    return 0;
}