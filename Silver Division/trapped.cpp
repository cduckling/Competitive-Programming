#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef long long ll;

int main() {
    freopen("trapped.in", "r", stdin); freopen("trapped.out", "w", stdout);

    int n {}; cin >> n;

    pair<int, int> a[n];
    for (int i {0}; i < n; ++i) {cin >> a[i].second >> a[i].first;}
    sort(a, a + n);

    ll e {0};

    for (int i {1}; i < n; ++i) {
        pair<int, int> b {i - 1, i};
        ll r {a[b.second].first - a[b.first].first};

        while (b.first != -1 && b.second != n && (r > a[b.second].second || r > a[b.first].second)) {
            if (r >= a[b.second].second) {++b.second;}
            if (r >= a[b.first].second) {--b.first;}
            r = {a[b.second].first - a[b.first].first};
        }

        if (b.first != -1 && b.second != n) {e += a[i].first - a[i - 1].first;}
    }

    cout << e;
}