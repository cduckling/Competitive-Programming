#include <iostream>
#include <vector>
using namespace std;

int phi(int n) {
    int a {n};

    for (int p {2}; p * p <= n; ++p) {
        if (n % p == 0) {
            while (n % p == 0) {
                n /= p;
            }

            a /= p;
            a *= (p - 1);
        }
    }

    if (n > 1) {
        a /= n;
        a *= (n - 1);
    }

    return a;
}

int main() {
    int n {}; cin >> n;

    cout << phi(n);
}