#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;

int main() {
    freopen("div7.in", "r", stdin); freopen("div7.out", "w", stdout);

    int n {}; cin >> n;

    ll a[n + 1]; a[0] = 0;
    for (int i {1}; i <= n; ++i) {cin >> a[i];}
    for (int i {1}; i <= n; ++i) {a[i] += a[i - 1];}

    int c {0};

    for (int i {0}; i <= n; ++i) {
        for (int j {i}; j <= n; ++j) {
            if ((a[j] - a[i]) % 7 == 0) {c = max(c, j - i);}
        }
    }

    cout << c;
}