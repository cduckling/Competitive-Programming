#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    int n {}; cin >> n;

    vector<int> a (n); for (int i {0}; i < n; ++i) cin >> a[i];
    vector<int> b (n);

    int o {0};

    for (int i {0}; i < n; ++i) {
        if (a[i] == 0) continue; ++o;

        if (a[i] > 2 || i == n - 1) {
            a[i] = 0;
        } else {
            if (!b[i]) {
                a[i + 1] -= 2; a[i + 1] = max(0, a[i + 1]); b[i + 1] = 1;
            } else {
                if (a[i + 1] > 2) {a[i + 1] -= 2; a[i + 1] = max(2, a[i + 1]); b[i + 1] = 0; }
            }

            a[i] = 0;
        }
    }

    cout << o << "\n";
}

int main() {
    io
    tc

    return 0;
}