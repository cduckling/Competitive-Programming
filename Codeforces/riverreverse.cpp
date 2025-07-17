#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    int n {}, k {}, q {}; cin >> n >> k >> q;

    vector<vector<int>> a (n, vector<int> (k)); for (int i {0}; i < n; ++i) for (int j {0}; j < k; ++j) cin >> a[i][j];

    vector<vector<int>> b (k, vector<int> (n)); for (int j {0}; j < k; ++j) { b[j][0] = a[0][j]; for (int i {1}; i < n; ++i) b[j][i] = b[j][i - 1] | a[i][j]; }

    while (q--) {
        int m {}; cin >> m;

        pii range {1, n};

        for (int i {0}; i < m; ++i) {
            int r {}; char o {}; int c {}; cin >> r >> o >> c; --r;

            if (o == '>') {
                int j = upper_bound(b[r].begin(), b[r].end(), c) - b[r].begin() + 1;

                if (j > n) {
                    range.first = n + 1;
                } else {
                    range.first = max(range.first, j);
                }
            } else {
                int j = lower_bound(b[r].begin(), b[r].end(), c) - b[r].begin();
                range.second = min(range.second, j);
            }
        }

        if (range.first <= n && range.first <= range.second) {
            cout << range.first << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
}

int main() {
    io

    solve();

    return 0;
}