#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    freopen("maxcross.in", "r", stdin); freopen("maxcross.out", "w", stdout);

    int n {}, k {}, b {}; cin >> n >> k >> b;

    int a[n + 1];
    for (int i {0}; i <= n; ++i) {a[i] = 0;}
    for (int i {1}; i <= b; ++i) {int s {}; cin >> s; ++a[s];}
    for (int i {1}; i <= n; ++i) {a[i] += a[i - 1];}

    int s {k}; for (int i {k}; i <= n; ++i) {s = min(s, a[i] - a[i - k]);} cout << s;
}