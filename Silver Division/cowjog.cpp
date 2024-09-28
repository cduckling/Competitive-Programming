#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    freopen("cowjog.in", "r", stdin); freopen("cowjog.out", "w", stdout);

    int n {}; long long t {}; cin >> n >> t;

    if (n == 1) {cout << 1; return 0;}

    long long a[n];
    for (int i {0}; i < n; ++i) {long long j {}, k {}; cin >> j >> k; a[i] = {j + k * t};}

    long long g {1}; long long b {a[n - 1]};
    for (int i {n}; i > 0; --i) {if (a[i - 1] < b) {++g; b = {a[i - 1]};}}
    cout << g;
}