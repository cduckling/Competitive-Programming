#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    int n {}; cin >> n;

    vector<char> b (n); for (int i {0}; i < n; ++i) cin >> b[i];
    vector<bool> a (n); for (int i {0}; i < n; ++i) {
        a[i] = b[i] == '1';
    }

    int d {1}; while (d * d < n) ++d;

    if (d * d == n) {
        for (int i {0}; i < n; i += d) {
            if (i == 0) {
                for (int j {i}; j < i + d; ++j) {
                    if (!a[j]) {
                        cout << "NO\n"; return;
                    }
                }
            } else if (i == (n - d)) {
                for (int j {i}; j < i + d; ++j) {
                    if (!a[j]) {
                        cout << "NO\n"; return;
                    }
                }
            } else {
                if (!(a[i]) || !(a[i + d - 1])) {
                    cout << "NO\n"; return;
                }

                for (int j {i + 1}; j < i + d - 1; ++j) {
                    if (a[j]) {
                        cout << "NO\n"; return;
                    }
                }
            }
        }
    } else {
        cout << "NO\n"; return;
    }

    cout << "YES\n";
}

int main() {
    io
    tc

    return 0;
}