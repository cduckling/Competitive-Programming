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
typedef vector<char> vc;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;
typedef vector<pair<int, int>> vpii;
typedef vector<bool> vb;
typedef set<int> si;
typedef map<int, int> mi;
typedef map<int, vector<int>> mvi;
typedef map<int, pair<int, int>> mpii;
typedef map<int, bool> mb;

void bfs(int n, int m, const vvc& maze, vvb& vis, vvi& exit) {
    queue<pii> q {};

    for (int i {1}; i <= n; ++i) for (int j {1}; j <= m; ++j) exit[i][j] = 1;

    for (int i {1}; i <= m; i++) if (maze[1][i] == 'U') {q.emplace(1, i); vis[1][i] = true; }
    for (int i {1}; i <= m; i++) if (maze[n][i] == 'D') {q.emplace(n, i); vis[n][i] = true; }

    for (int i {1}; i <= n; i++) if (maze[i][1] == 'L') {q.emplace(i, 1); vis[i][1] = true; }
    for (int i {1}; i <= n; i++) if (maze[i][m] == 'R') {q.emplace(i, m); vis[i][m] = true; }

    while (!q.empty()) {
        pii v = q.front(); q.pop(); int r = v.first, c = v.second; exit[r][c] = 2;

        if (maze[r - 1][c] == 'D' && !vis[r - 1][c]) {q.emplace(r - 1, c); vis[r - 1][c] = true; }

        if (maze[r + 1][c] == 'U' && !vis[r + 1][c]) {q.emplace(r + 1, c); vis[r + 1][c] = true; }

        if (maze[r][c - 1] == 'R' && !vis[r][c - 1]) {q.emplace(r, c - 1); vis[r][c - 1] = true; }

        if (maze[r][c + 1] == 'L' && !vis[r][c + 1]) {q.emplace(r, c + 1); vis[r][c + 1] = true; }
    }
}

void solve() {
    int n {}, m {}; cin >> n >> m;

    vvc maze (n + 2, vc (m + 2, ' ')); for (int i {1}; i <= n; i++) for (int j {1}; j <= m; j++) cin >> maze[i][j];

    vvb vis (n + 2, vb (m + 2)); vvi exit (n + 2, vi (m + 2)); bfs(n, m, maze, vis, exit);

    int b {0};

    for (int i {1}; i <= n; ++i) {
        for (int j {1}; j <= m; ++j) {
            if (maze[i][j] == '?') {
                if (exit[i - 1][j] == 1 || exit[i + 1][j] == 1 || exit[i][j - 1] == 1 || exit[i][j + 1] == 1) ++b;
            } else {
                if (exit[i][j] == 1) ++b;
            }
        }

    }

    cout << b << "\n";
}

int main() {
    io
    tc

    return 0;
}