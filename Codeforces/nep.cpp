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
typedef tuple<int, int, int> tiii;
typedef vector<tuple<int, int, int>> vtiii;
typedef vector<vector<tuple<int, int, int>>> vvtiii;
typedef vector<vector<vector<tuple<int, int, int>>>> vvvtiii;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef set<int> si;
typedef vector<set<int>> vsi;
typedef vector<vector<set<int>>> vvsi;
typedef map<int, int> mii;
typedef map<int, bool> mib;
typedef map<int, double> mid;
typedef vector<map<int, int>> vmii;
typedef vector<map<int, double>> vmid;
typedef vector<map<int, bool>> vmib;

vpii adj(const pii a) {
    return {{a.first - 1, a.second}, {a.first + 1, a.second}, {a.first, a.second - 1}, {a.first, a.second + 1}};
}

void solve() {
    int n; cin >> n;

    vpii xy (n); for (int i = 0; i < n; i++) cin >> xy[i].first >> xy[i].second;

    set<pii> pts; for (int i = 0; i < n; i++) pts.insert(xy[i]);
    map<pii, int> inv; for (int i = 0; i < n; i++) inv[xy[i]] = i;

    queue<int> q; vpii dp (n); vb vis (n); for (int i = 0; i < n; i++) {
        for (const pii j : adj(xy[i])) {
            if (!pts.count(j)) {
                dp[i] = j; vis[i] = true; q.push(i);
            }
        }
    }

    while (!q.empty()) {
        const int pos = q.front(); q.pop();

        for (const pii i : adj(xy[pos])) {
            if (pts.count(i) && !vis[inv[i]]) {
                vis[inv[i]] = true; dp[inv[i]] = dp[pos]; q.push(inv[i]);
            }
        }
    }

    for (const pii i : dp) cout << i.first << " " << i.second << "\n";
}

int main() {
    io

    solve();

    return 0;
}