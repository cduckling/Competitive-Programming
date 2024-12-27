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

int floyd(int v, const vi& adj) {
    int t = adj[v], h = adj[adj[v]];

    while (t != h) {
        t = adj[t]; h = adj[adj[h]];
    }

    return t;
}

void dfs(int v, int col, vi& c, const vi& out, const vvi& in) {
    if (c[v]) {
        return;
    } else {
        c[v] = col;

        dfs(out[v], col, c, out, in);
        for (int i : in[v]) dfs(i, col, c, out, in);
    }
}

int main() {
    io

    int n {}; cin >> n;

    vi out (n); vvi in (n);

    for (int i {0}; i < n; ++i) {
        cin >> out[i]; in[out[i]].push_back(i);
    }

    vi c (n); int col = 0; for (int i {0}; i < n; ++i) {
        if (!c[i]) {
            ++col;
            dfs(i, col, c, out, in);
        }
    }

    for (int i : c) cout << i << " " << floyd(i, out) << "\n";

    return 0;
}