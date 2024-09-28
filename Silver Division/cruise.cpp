#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    freopen("cruise.in", "r", stdin); freopen("cruise.out", "w", stdout);

    int n {}, m {}, k {}; cin >> n >> m >> k;

    int ports[n][2];
    for (int i {0}; i < n; ++i) {
        cin >> ports[i][0] >> ports[i][1];
        --ports[i][0]; --ports[i][1];
    }

    int directions[m];
    for (int i {0}; i < m; ++i) {
        char j {};
        cin >> j;

        directions[i] = (j == 'L') ? 0 : 1;
    }

    int port {0};
    for (int i {0}; i < m * k; ++i) {
        port = ports[port][directions[i % m]];
    }
    cout << port + 1;
}