#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

#define tc int t {}; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb(i) push_back(i);
#define inf 1e18;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpii;
typedef vector<bool> vb;
typedef set<int> si;
typedef map<int, int> mi;
typedef map<int, vector<int>> mvi;
typedef map<int, pair<int, int>> mpii;
typedef map<int, bool> mb;

void solve() {
    int n {}; cin >> n;

    vi a (n), b (n); for (int i {0}; i < n; ++i) cin >> a[i];

    for (int i {0}; i < (1<<8); ++i) {
        for (int j {0}; j < n; ++j) b[j] = (a[j]^i);

        int t {0}; for (int j : b) t ^= j;

        if (!t) {
            cout << i << "\n"; return;
        }
    }

    cout << -1 << "\n";
}

int main() {
    io
    tc

    return 0;
}