
#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}

typedef long long ll;

void solve() {
    int n {}, m {}; cin >> n >> m;

    vector<vector<int>> a (n, vector<int> (m)); for (int i {0}; i < n; ++i) {
        for (int j {0}; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> b (n, vector<int> (m)); for (int i {0}; i < n; ++i) {
        for (int j {0}; j < m; ++j) {
            cin >> b[i][j];
        }
    }

    map<set<int>, bool> rows {}; for (int i {0}; i < n; ++i) {
        set<int> r {};
        for (int j {0}; j < m; ++j) {
            r.insert(b[i][j]);
        }
        rows[r] = true;
    }

    map<set<int>, bool> columns {}; for (int i {0}; i < m; ++i) {
        set<int> c {};
        for (int j {0}; j < n; ++j) {
            c.insert(b[j][i]);
        }
        columns[c] = true;
    }

    for (int i {0}; i < n; ++i) {
        set<int> r {};
        for (int j {0}; j < m; ++j) {
            r.insert(a[i][j]);
        }

        if (!rows[r]) {
            cout << "NO\n"; return;
        }
    }

    for (int i {0}; i < m; ++i) {
        set<int> c {};
        for (int j {0}; j < n; ++j) {
            c.insert(a[j][i]);
        }

        if (!columns[c]) {
            cout << "NO\n"; return;
        }
    }

    cout << "YES\n";
}

int main() {
    tc
}