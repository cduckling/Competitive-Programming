#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

int main() {
    io

    int n {}; cin >> n;

    vector<int> a {};
    for (int i {1}; i < n; ++i) {
        if (gcd(i, n) == 1) {
            a.push_back(i);
        }
    }

    ll r {1};
    for (int i : a) {
        r *= i; r %= n;
    }

    if (r == 1) {
        cout << a.size() << "\n";
        for (int i : a) {
            cout << i << " ";
        }
    } else {
        cout << a.size() - 1 << "\n";
        for (int i : a) {
            if (i != r) {
                cout << i << " ";
            }
        }
    }

    return 0;
}