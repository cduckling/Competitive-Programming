#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
    freopen("lazy.in", "r", stdin); freopen("lazy.out", "w", stdout);

    int n {}, k {}; cin >> n >> k;

    vector<int> f (4000044, 0);
    for (int i {0}; i < n; ++i) {int g {}, p {}; cin >> g >> p; f[p + 4] = g;}
    for (int i {1}; i < 4000044; ++i) {f[i] += f[i - 1];}

    int g {0};

    for (int i {2 * k + 1}; i < 4000044; ++i) {g = max(g, f[i] - f[i - 2 * k - 1]);}

    cout << g;
}