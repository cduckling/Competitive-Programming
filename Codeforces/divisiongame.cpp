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
    int n {}, k {}; cin >> n >> k;

    vi a (n); for (int i {0}; i < n; i++) cin >> a[i];

    for (int i {0}; i < n; ++i) {
        bool g = true;

        for (int j {0}; j < n; ++j) {
            if (i == j) continue;

            if (abs(a[i] - a[j]) % k == 0) g = false;
        }

        if (g) {
            cout << "YES\n" << i + 1 << "\n"; return;
        }
    }

    cout << "NO\n";
}

int main() {
    io
    tc

    return 0;
}