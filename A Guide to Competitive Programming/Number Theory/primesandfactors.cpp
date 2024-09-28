#include <iostream>
#include <vector>
using namespace std;

bool prime(int n) {
    if (n < 2) return false;

    for (int i {2}; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }

    return true;
}

vector<int> factors(int n) {
    vector<int> f {};

    for (int i {2}; i * i <= n; ++i) {
        while (n % i == 0) {
            f.push_back(i);
            n /= i;
        }
    }

    if (n > 1) f.push_back(n);

    return f;
}

int main() {
    int n {}; cin >> n;

    vector<int> f (factors(n));

    for (int i : f) {
        cout << i << " ";
    }
}