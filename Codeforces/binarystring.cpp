#include <iostream>
#include <vector>
using namespace std;

#define tc int t {}; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<int, int> pii;

int query(const int l, const int r) {
    cout << "? " << l << " " << r << endl;
    int a {}; cin >> a; return a;
}

void solve() {
    int n {}; cin >> n;

    vector<int> b (n + 1);

    int p {n - 1}, q = -1; while (p >= 1) {
        q = query(p, n);

        if (q > 0) break;

        --p;
    }

    if (p == 0) {
        cout << "! IMPOSSIBLE" << endl; return;
    }

    for (int i {p + 1}; i <= p + q; ++i) b[i] = 1;

    for (int i {p - 1}; i >= 1; --i) {
        int v = query(i, n);

        if (v > q) {
            b[i] = 0; q = v;
        } else {
            b[i] = 1;
        }
    }

    cout << "! "; for (int i {1}; i <= n; ++i) cout << b[i]; cout << endl;
}

int main() {
    io
    tc

    return 0;
}