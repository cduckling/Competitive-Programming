#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    int n {}, m {}, q {}; cin >> n >> m >> q;

    vector<int> t (m); for (int i {0}; i < m; ++i) cin >> t[i]; sort(t.begin(), t.end());

    for (int i {0}; i < q; ++i) {
        int d {}; cin >> d;

        if (d < t[0]) {
            cout << d - 1 + (t[0] - (d - 1)) - 1 << "\n";
        } else if (d > t[t.size() - 1]) {
            cout << (n - d) + n - (t[t.size() - 1] + (n - d)) << "\n";
        } else {
            int j = upper_bound(t.begin(), t.end(), d) - t.begin();

            cout << (t[j] - t[j - 1]) / 2 << "\n";
        }
    }
}

int main() {
    io
    tc

    return 0;
}