#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

bool s (int a, int b) {return a > b;}

int main() {
    freopen("lemonade.in", "r", stdin); freopen("lemonade.out", "w", stdout);

    int n {}; cin >> n;

    if (n == 1) {cout << 1; return 0;}

    int a[n];
    for (int i {0}; i < n; ++i) {cin >> a[i];}
    sort(a, a + n, s);

    for (int i {0}; i < n; ++i) {if (i > a[i]) {cout << i; return 0;}} cout << n;
}