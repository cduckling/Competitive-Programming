#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int extended(const int a, const int b, int& x, int& y) {
    if (b == 0) {
        x = 1; y = 0;
        return a;
    }
    int x_1 {}, y_1 {};
    int d = extended(b, a % b, x_1, y_1);
    x = y_1, y = x_1 - y_1 * (a / b);
    return d;
}

int main() {
    int a {}, b {}; cin >> a >> b;
    cout << gcd(a, b) << "\n";

    int x {}, y {};
    extended(a, b, x, y);
    cout << x << " " << y << "\n";

    cout << ((x * 7) % b + b) % b;
}