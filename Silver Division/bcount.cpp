#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main() {
    freopen("bcount.in", "r", stdin); freopen("bcount.out", "w", stdout);

    int n {}, q {}; cin >> n >> q;

    vector<int> h (n + 1, 0);
    vector<int> g (n + 1, 0);
    vector<int> j (n + 1, 0);

    for (int i {1}; i <= n; ++i) {int c {}; cin >> c; ++(c == 1 ? (h) : (c == 2 ? g : j))[i];}
    for (int i {1}; i <= n; ++i) {h[i] += h[i - 1]; g[i] += g[i - 1]; j[i] += j[i - 1];}
    for (int i {0}; i < q; ++i) {int a {}, b {}; cin >> a >> b; cout << h[b] - h[a - 1] << " " << g[b] - g[a - 1] << " " << j[b] - j[a - 1] << "\n";}
}