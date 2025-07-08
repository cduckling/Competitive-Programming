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
#define pb(i) push_back(i)
#define eb(i) emplace_back(i)
#define ceil(a, b) ((a + b - 1) / b)
#define inf (ll) 1e18
#define fail cout << -1 << "\n"; return;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<vector<vector<double>>> vvvd;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<pair<int, int>>> vvpii;
typedef vector<vector<vector<pair<int, int>>>> vvvpii;
typedef tuple<int, int, int> tii;
typedef vector<tuple<int, int, int>> vtii;
typedef vector<vector<tuple<int, int, int>>> vvtii;
typedef vector<vector<vector<tuple<int, int, int>>>> vvvtii;
typedef set<int> si;
typedef vector<set<int>> vsi;
typedef vector<vector<set<int>>> vvsi;
typedef map<int, int> mii;
typedef map<int, bool> mib;
typedef map<int, double> mid;
typedef vector<map<int, int>> vmii;
typedef vector<map<int, double>> vmid;
typedef vector<map<int, bool>> vmib;

void dfs(const int ver, const int col, vi& vis, const vi& out, const vvi& in) {
    if (vis[ver]) return; vis[ver] = col; dfs(out[ver], col, vis, out, in); for (const int i : in[ver]) dfs(i, col, vis, out, in);
}

void dfs(const int ver, const int no, vi& dp, const vvi& in) {
    vi c; for (const int i : in[ver]) if (i != no) c.pb(i), dfs(i, -1, dp, in);

    dp[ver] = 1; for (const int i : c) dp[ver] += dp[i];
}

int main() {
    io

    int n; cin >> n;

    vi out (n + 1); for (int i = 1; i <= n; i++) cin >> out[i];

    vvi in (n + 1); for (int i = 1; i <= n; i++) in[out[i]].pb(i);

    vi vis (n + 1); int col = 0; for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i, ++col, vis, out, in);

    vvi c (col + 1); for (int i = 1; i <= n; i++) c[vis[i]].pb(i);

    vvi cycle (col + 1); for (int i = 1; i <= col; i++) {
        int a = out[c[i][0]], b = out[out[c[i][0]]]; while (a != b) a = out[a], b = out[out[b]];
        a = c[i][0]; while (a != b) a = out[a], b = out[b]; b = a;
        cycle[i].pb(a); a = out[a]; while (a != b) cycle[i].pb(a), a = out[a];
    }

    vi dp (n + 1); for (int i = 1; i <= col; i++) for (int j = 0; j < cycle[i].size(); j++) dfs(cycle[i][j], cycle[i][(cycle[i].size() + j - 1) % cycle[i].size()], dp, in);

    return 0;
}
