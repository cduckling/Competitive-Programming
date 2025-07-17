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
typedef tuple<int, int, int> tiii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpii;
typedef vector<tuple<int, int, int>> vtiii;
typedef vector<bool> vb;
typedef multiset<int> msi;
typedef set<int> si;
typedef map<int, int> mi;
typedef map<int, vector<int>> mvi;
typedef map<int, pair<int, int>> mpii;
typedef map<int, bool> mb;

void solve() {
    int n {}, m {}; cin >> n >> m;

    vi s (m); for (int i {0}; i < m; ++i) cin >> s[i]; sort(s.begin(), s.end(), greater<int>());

    vi a (n + 1, 1); for (int i {1}; i <= n; ++i) for (int j {2}; j <= n / i; ++j) a[i * j] = a[i] + 1;

    for (int i {1}; i <= n; ++i) {
        if (a[i] - 1 >= m) {
            cout << -1 << "\n"; return;
        }

        a[i] = s[a[i] - 1];
    }

    for (int i {1}; i <= n; ++i) cout << a[i] << " "; cout << "\n";
}

int main() {
    io
    tc

    return 0;
}