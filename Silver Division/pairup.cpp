#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main() {
    freopen("pairup.in", "r", stdin); freopen("pairup.out", "w", stdout);

    int n {}; cin >> n;

    pair<int, int> a[n];
    for (int i {0}; i < n; ++i) {cin >> a[i].second >> a[i].first;}
    sort(a, a + n);

    int m {0};

    pair<int, int> interval {0, n - 1};
    while (a[interval.first].second != 0 && a[interval.second].second != 0) {
        m = max(a[interval.first].first + a[interval.second].first, m);

        int s {min(a[interval.first].second, a[interval.second].second)};
        a[interval.first].second -= s; a[interval.second].second -= s;

        if (a[interval.first].second <= 0) {++interval.first;}
        if (a[interval.second].second <= 0) {--interval.second;}
    }

    cout << m;
}