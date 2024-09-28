#include <iostream>
#include <cstdio>
using namespace std;

int n {}, x {}, y {}, z {};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("milktemp.in", "r", stdin); freopen("milktemp.out", "w", stdout);

    cin >> n >> x >> y >> z;

    pair<int, int> cows[n];
    for (int i {0}; i < n; ++i) {
        cin >> cows[i].first >> cows[i].second;
    }

    int milk {0};

    for (int i {0}; i < n; ++i) {
        int m {0}, t {cows[i].first};

        for (int j {0}; j < n; ++j) {
            if (t < cows[j].first) {
                m += x;
            } else if (cows[j].first <= t && t <= cows[j].second) {
                m += y;
            } else {
                m += z;
            }
        }

        milk = max(milk, m);
    }

    cout << milk;

    return 0;
}
