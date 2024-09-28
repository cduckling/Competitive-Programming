#include <iostream>
#include <vector>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

int main() {
    io

    int n {}; cin >> n;

    int pasture[n][n]; for (int i {0}; i < n; ++i) {
        for (int j {0}; j < n; ++j) cin >> pasture[i][j];
    }

    pair<int, int> beauty {};

    for (int i {0}; i < n; ++i) {
        int a {0}; for (int j {0}; j < n; j += 2) a += pasture[j][i];
        int b {0}; for (int j {1}; j < n; j += 2) b += pasture[j][i];

        beauty.first += max(a, b);
    }

    for (int i {0}; i < n; ++i) {
        int a {0}; for (int j {0}; j < n; j += 2) a += pasture[i][j];
        int b {0}; for (int j {1}; j < n; j += 2) b += pasture[i][j];

        beauty.second += max(a, b);
    }

    cout << max(beauty.first, beauty.second);

    return 0;
}