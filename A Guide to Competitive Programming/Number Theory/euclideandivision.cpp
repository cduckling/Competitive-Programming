#include <iostream>
using namespace std;

typedef long long ll;

const ll m = 1e9 + 7;

ll inverses[100000001];

ll inverse(ll x) {
    return x <= 1 ? x : m - m / x * inverse(m % x) % m;
}

int main() {
    inverses[1] = 1;

    int n {}; cin >> n;
    for (int i {2}; i <= n; ++i) {
        cout << inverse(i) << " ";
    }
}