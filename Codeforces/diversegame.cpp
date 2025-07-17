#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    int n {}, m {}; cin >> n >> m;

    vector<vector<int>> a (n, vector<int> (m)); for (int i {0}; i < n; ++i) {
        for (int j {0}; j < m; ++j) {
            cin >> a[i][j];
        }
    }

    if (n == 1 && m == 1) {
        cout << -1 << "\n";
    } else if (m == 1) {
        for (int i {1}; i < n; ++i) {
            swap(a[i - 1][0], a[i][0]);
        }

        for (int i {0}; i < n; ++i) {
            for (int j {0}; j < m; ++j) {
                cout << a[i][j] << " ";
            }

            cout << "\n";
        }
    } else {
        for (int i {0}; i < n; ++i) {
            for (int j {1}; j < m; ++j) {
                swap(a[i][j - 1], a[i][j]);
            }
        }

        for (int i {0}; i < n; ++i) {
            for (int j {0}; j < m; ++j) {
                cout << a[i][j] << " ";
            }

            cout << "\n";
        }
    }
}

int main() {
    io
    tc

    return 0;
}