#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
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
#define inf (int) 1e9
#define f first
#define s second

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
typedef set<pair<int, int>> spii;
typedef vector<set<pair<int, int>>> vspii;
typedef map<int, int> mii;
typedef map<int, bool> mib;
typedef map<int, double> mid;
typedef vector<map<int, int>> vmii;
typedef vector<map<int, double>> vmid;
typedef vector<map<int, bool>> vmib;

#define fail {cout << -1 << "\n"; return;}

int edit(const vi& beg, const vi& end) {
    int diff = 0; for (int i = 0; i < beg.size(); i++) if (beg[i] != end[i]) diff++; return diff;
}

void solve() {
    int n, m; cin >> n >> m;

    vvi a (n + 1, vi (m + 1)); for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        char c; cin >> c; a[i][j] = c == '1';
    }

    if (n >= 4) fail

    int ops = inf;

    if (n == 1) {
        ops = 0;
    } else if (n == 2) {
        int OPS = 0;

        for (int i = 1; i <= m; i++) {
            const int sum = a[1][i] + a[2][i];

            if (i % 2 == 0) {
                if (sum != 1) OPS++;
            } else {
                if (sum == 1) OPS++;
            }
        }

        ops = min(ops, OPS); OPS = 0;

        for (int i = 1; i <= m; i++) {
            const int sum = a[1][i] + a[2][i];

            if (i % 2 == 0) {
                if (sum == 1) OPS++;
            } else {
                if (sum != 1) OPS++;
            }
        }

        ops = min(ops, OPS); OPS = 0;
    } else if (n == 3) {
        int OPS = 0;

        for (int i = 1; i <= m; i++) {
            if (i % 2 == 0) {
                OPS += min(edit({a[1][i], a[2][i], a[3][i]}, {1, 1, 0}), edit({a[1][i], a[2][i], a[3][i]}, {0, 0, 1}));
            } else {
                OPS += min(edit({a[1][i], a[2][i], a[3][i]}, {0, 1, 1}), edit({a[1][i], a[2][i], a[3][i]}, {1, 0, 0}));
            }
        }

        ops = min(ops, OPS); OPS = 0;

        for (int i = 1; i <= m; i++) {
            if (i % 2 != 0) {
                OPS += min(edit({a[1][i], a[2][i], a[3][i]}, {1, 1, 0}), edit({a[1][i], a[2][i], a[3][i]}, {0, 0, 1}));
            } else {
                OPS += min(edit({a[1][i], a[2][i], a[3][i]}, {0, 1, 1}), edit({a[1][i], a[2][i], a[3][i]}, {1, 0, 0}));
            }
        }

        ops = min(ops, OPS); OPS = 0;

        for (int i = 1; i <= m; i++) {
            if (i % 2 == 0) {
                OPS += min(edit({a[1][i], a[2][i], a[3][i]}, {1, 0, 1}), edit({a[1][i], a[2][i], a[3][i]}, {0, 1, 0}));
            } else {
                OPS += min(edit({a[1][i], a[2][i], a[3][i]}, {1, 1, 1}), edit({a[1][i], a[2][i], a[3][i]}, {0, 0, 0}));
            }
        }

        ops = min(ops, OPS); OPS = 0;

        for (int i = 1; i <= m; i++) {
            if (i % 2 != 0) {
                OPS += min(edit({a[1][i], a[2][i], a[3][i]}, {1, 0, 1}), edit({a[1][i], a[2][i], a[3][i]}, {0, 1, 0}));
            } else {
                OPS += min(edit({a[1][i], a[2][i], a[3][i]}, {1, 1, 1}), edit({a[1][i], a[2][i], a[3][i]}, {0, 0, 0}));
            }
        }

        ops = min(ops, OPS); OPS = 0;
    }

    cout << ops << "\n";
}

int main() {
    io

    solve();

    return 0;
}