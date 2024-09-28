#include <iostream>
#include <vector>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    int n {}; cin >> n;

    vector<int> a (n); for (int i {0}; i < n; ++i) { char j {}; cin >> j; a[i] = (j == '1'); } const vector<int> A = a;
    vector<int> b (n); for (int i {0}; i < n; ++i) { char j {}; cin >> j; b[i] = (j == '1'); } const vector<int> B = b;

    for (int i {1}; i < n - 1; ++i) if (!b[i] && (!a[i - 1] && !a[i + 1])) b[i] = 1;
    for (int i {1}; i < n - 1; ++i) if (!a[i] && (b[i - 1] && b[i + 1])) a[i] = 1;

    vector<int> pref (n); pref[0] = a[0]; for (int i {1}; i < n; ++i) pref[i] = a[i] + pref[i - 1];

    int q {}; cin >> q; for (int i {0}; i < q; ++i) {
        int l {}, r {}; cin >> l >> r; --l; --r;

        if (r - l == 0) {
            cout << A[l] << "\n";
        } else if (r - l == 1) {
            cout << A[l] + A[r] << "\n";
        } else if (r - l == 2) {
            cout << A[l] + A[r] + (A[l + 1] || (B[l] && B[r])) << "\n";
        } else {
            int t = pref[r - 2] - pref[l - 1 + 2] + A[l] + A[r];
            if (A[l + 1] || (B[l] && a[l + 1])) ++t; if (A[r - 1] || (B[r] && a[r - 1])) ++t;
            cout << t << "\n";
        }
    }
}

int main() {
    io
    tc

    return 0;
}