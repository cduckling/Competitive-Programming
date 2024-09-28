#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int n {}, m {}, c {};
bool time(vector<int> t, int w) {
    pair<int, int> b {-1, 0}; int p {0};

    for (int i {0}; i < n; ++i) {
        if (t[i] > p || b.second == c) {p = {t[i] + w}; ++b.first; b.second = {1};}
        else {++b.second;}
    }

    return (b.first == m - 1 && b.second == c) || b.first < m;
}

int main() {
    freopen("convention.in", "r", stdin); freopen("convention.out", "w", stdout);

    cin >> n >> m >> c;

    vector<int> t (n, 0);
    for (int i {0}; i < n; ++i) {cin >> t[i];}
    sort(t.begin(), t.end());

    pair<int, int> interval {0, t[n - 1] - t[0]};
    while (interval.first != interval.second) {
        int s {(interval.first + interval.second) / 2};

        if (time(t, s)) {
            interval.second = s;
        } else {
            interval.first = s + 1;
        }
    }

    cout << interval.first;
}