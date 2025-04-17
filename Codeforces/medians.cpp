#include <iostream>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    int n {}, k {}; cin >> n >> k;

    if (n == 1) {
        cout << 1 << "\n" << 1 << "\n";
    } else {
        if (k == 1 || k == n) {
            cout << -1 << "\n";
        } else {
            if (k % 2 == 0) {
                cout << 3 << "\n" << 1 << " " << k << " " << k + 1 << "\n";
            } else {
                cout << 5 << "\n";

                cout << 1 << " " << k - 1 << " " << k << " " << k + 1 << " " << k + 2 << "\n";
            }
        }
    }
}

int main() {
    io
    tc

    return 0;
}