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
typedef vector<vector<char>> matrix;

void solve() {
    int n {}, k {}; cin >> n >> k;

    matrix a (n, vector<char> (n, 0));
    for (int i {0}; i < n; ++i) {
        for (int j {0}; j < n; ++j) {
            cin >> a[i][j];
        }
    }
    matrix b (n / k, vector<char> (n / k, 0));

    for (int i {0}; i < n; i += k) {
        for (int j {0}; j < n; j += k) {
            b[i / k][j / k] = a[i][j];
        }
    }

    for (int i {0}; i < n / k; ++i) {
        for (int j {0}; j < n / k; ++j) {
            cout << b[i][j];
        }

        cout << "\n";
    }
}

int main() {
    io
    tc

    return 0;
}