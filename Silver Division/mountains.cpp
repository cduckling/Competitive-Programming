#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int n {};

int main() {
    freopen("mountains.in", "r", stdin); freopen("mountains.out", "w", stdout);

    cin >> n;

    pair<int, int> mountains[n];
    for (int i {0}; i < n; ++i) {
        int a {}, b {}; cin >> a >> b;
        mountains[i] = {a - b, a + b};
    }
    sort(mountains, mountains + n);

    int e {0}, h {0};
    for (int i {0}; i < n; ++i) {
        if (e >= mountains[i].second) {
            ++h;
        }

        e = max(e, mountains[i].second);
    }

    cout << n - h;
}