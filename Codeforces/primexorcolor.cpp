#include <iostream>
#include <vector>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    int n {}; cin >> n;

    if (n == 0) {
        cout << "1\n1\n";
    } else if (n == 1) {
        cout << "1\n1\n";
    } else if (n == 2) {
        cout << "2\n1 2\n";
    } else if (n == 3) {
        cout << "2\n1 2 2\n";
    } else if (n == 4) {
        cout << "3\n1 2 2 3\n";
    } else if (n == 5) {
        cout << "3\n1 2 2 3 3\n";
    }

    if (n < 6) return;

    vector<int> c (n);
    for (int i {1}; i <= n; ++i) {
        if (i % 2 == 0) {
            if ((i>>1) % 2 == 0) {
                c[i - 1] = 1;
            } else {
                c[i - 1] = 3;
            }
        } else {
            if ((i>>1) % 2 == 0) {
                c[i - 1] = 2;
            } else {
                c[i - 1] = 4;
            }
        }
    }

    vector<bool> d (5); for (int i : c) d[i] = true; int dist = 0; for (bool i : d) dist += i;
    cout << dist << "\n"; for (int i : c) cout << i << " "; cout << "\n";

}

/*
 * If EVEN
 * 00,10
 */

int main() {
    io
    tc

    return 0;
}