#include <iostream>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

void solve() {
    int n {}; cin >> n;

    if (n == 2) {
        cout << "1 1\n"
                "2 1\n";
    } else if (n == 3) {
        cout << "1 1\n"
                "3 2\n"
                "3 3\n";
    } else {
        for (int i {0}; i < n; ++i) {
            if (i == n - 2) {
                cout << n << " " << i + 1 << "\n";
            } else {
                cout << i + 1 << " " << i + 1 << "\n";
            }
        }
    }
}

int main() {
    io
    tc

    return 0;
}