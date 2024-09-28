#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

int e[31];

int main() {
    io

    e[0] = 1; for (int i {1}; i <= 30; ++i) e[i] = e[i - 1] * 2;

    int n {}; cin >> n;

    vector<int> a (n); for (int i {0}; i < n; ++i) cin >> a[i];

    vector<vector<int>> m (n, vector<int> (static_cast<int>(log2(n)) + 1));
    for (int i {0}; i < n; ++i) m[i][0] = a[i];

    for (int l {1}; l <= log2(n); ++l) {
        for (int p {0}; p < n - e[l] + 1; ++p) {
            m[p][l] = min(m[p][l - 1], m[p + e[l - 1]][l - 1]);
        }
    }

    int q {}; cin >> q;

    for (int i {0}; i < q; ++i) {
        int u {}, v {}; cin >> u >> v;

        int l = static_cast<int>(log2(v - u + 1));

        cout << min(m[u][l], m[v - e[l] + 1][l]) << "\n";
    }

    return 0;
}