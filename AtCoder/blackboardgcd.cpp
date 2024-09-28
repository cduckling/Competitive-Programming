#include <iostream>
using namespace std;

int n {};

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    cin >> n;

    int a[n + 2]; a[0] = 0; a[n + 1] = 0; for (int i {1}; i <= n; ++i) {
        cin >> a[i];
    }

    int left[n]; int l {0};
    for (int i {0}; i < n; ++i) {
        left[i] = gcd(l, a[i]);
        l = left[i];
    }

    int right[n]; int r {0};
    for (int i {n - 1}; i >= 0; --i) {
        right[i] = gcd(r, a[i + 2]);
        r = right[i];
    }

    int b {0}; for (int i {0}; i < n; ++i) {
        b = max(b, gcd(left[i], right[i]));
    } cout << b;
}