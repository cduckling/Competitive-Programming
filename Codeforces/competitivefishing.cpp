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
typedef tuple<int, int, int> tii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpii;
typedef vector<tuple<int, int, int>> vtiii;
typedef vector<bool> vb;
typedef set<int> si;
typedef map<int, int> mi;
typedef map<int, vector<int>> mvi;
typedef map<int, pair<int, int>> mpii;
typedef map<int, bool> mb;

void solve() {
    int n {}, k {}; cin >> n >> k;

    vb a (n + 1); for (int i {1}; i <= n; i++) { char v {}; cin >> v; a[i] = v == '1'; }

    vi p (n + 1); p[n] = a[n]; for (int i = n - 1; i >= 1; i--) p[i] = p[i + 1] + a[i];

    vi m {}; for (int i {1}; i < n; ++i) m.pb(2 * p[i + 1] - n + i); sort(m.begin(), m.end(), greater<int>());

    int pos = 0; while (k > 0 && pos < n - 1 && m[pos] > 0) k -= m[pos++]; cout << (k > 0 ? -1 : pos + 1) << "\n";
}

int main() {
    io
    tc

    return 0;
}