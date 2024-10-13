#include <iostream>
#include <vector>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

int floyd(int v, const vector<int>& adj) {
    int t = adj[v], h = adj[adj[v]];

    while (t != h) {
        t = adj[t]; h = adj[adj[h]];
    }

    return t;
}

void dfs(int v, int col, vector<int>& c, const vector<int>& out, const vector<vector<int>>& in) {
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

    vector<int> out (n); vector<vector<int>> in (n);

    for (int i {0}; i < n; ++i) {
        cin >> out[i]; in[out[i]].push_back(i);
    }

    vector<int> c (n); int col = 0; for (int i {0}; i < n; ++i) {
        if (!c[i]) {
            ++col;
            dfs(i, col, c, out, in);
        }
    }

    for (int i : c) cout << i << " " << floyd(i, out) << "\n";

    return 0;
}