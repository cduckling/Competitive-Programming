#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    freopen("baseball.in", "r", stdin); freopen("baseball.out", "w", stdout);

    int n {}; cin >> n;

    int a[n];
    for (int i {0}; i < n; ++i) {cin >> a[i];}
    sort(a, a + n);

    int g {0};

    for (int i {0}; i < n; ++i) {
        for (int j {i + 1}; j < n; ++j) {
            for (int k {j + 1}; k < n; ++k) {
                pair<int, int> t {a[j] - a[i], a[k] - a[j]};
                if (t.second >= t.first && t.second <= t.first * 2) {++g;}
            }
        }
    }

    cout << g;
}