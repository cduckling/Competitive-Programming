#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
using namespace std;

#define tc int t; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(a) (a).begin(), (a).end()
#define pb(i) push_back(i);
#define ceil(a, b) ((a + b - 1) / b)
#define inf 1e18

typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<set<int>> vsi;
typedef vector<pair<int, int>> vpii;
typedef vector<tuple<int, int, int>> vtiii;
typedef vector<bool> vb;
typedef multiset<int> msi;
typedef set<int> si;
typedef set<pair<int, int>> spii;
typedef set<tuple<int, int, int>> stiii;
typedef map<int, int> mi;
typedef map<int, vector<int>> mivi;
typedef map<int, pair<int, int>> mipii;
typedef map<int, bool> mib;

void solve() {
    int n, m; cin >> n >> m;

    vi a (n + 1); for (int i = 1; i <= n; i++) cin >> a[i];
    vi b (m + 1); for (int i = 1; i <= m; i++) cin >> b[i];

    vi pref (n + 1); for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i];

    vvi dp (n + 1, vi (m + 1));

    for (int i = n - 1; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {

        }
    }

    cout << dp[n][m] << "\n";
}

int main() {
    io
    tc

    return 0;
}