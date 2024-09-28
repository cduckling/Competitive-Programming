#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    freopen("highcard.in", "r", stdin); freopen("highcard.out", "w", stdout);

    int n {}; cin >> n;

    bool c[2 * n];
    for (int i {0}; i < 2 * n; ++i) {c[i] = true;}

    int e[n];
    for (int i {0}; i < n; ++i) {cin >> e[i]; --e[i];  c[e[i]] = false;}
    sort (e, e + n);

    int b[n]; int l {0};
    for (int i {0}; i < 2 * n; ++i) {if (c[i]) {b[l] = {i}; ++l;}} l = {0};

    int w {0};
    for (int i {0}; i < n; ++i) {while (b[l] < e[i]) {++l; if (l >= n) {break;}} ++w; ++l; if (l >= n) {break;}}
    cout << w;
}