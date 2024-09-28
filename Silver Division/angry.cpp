#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

bool sweep(vector<int> a, int r, int k) {
    pair<int, int> c {a[0], 1};

    for (int i : a) {
        if (i > c.first + 2 * r) {++c.second; c.first = i;}
    }

    return c.second <= k;
}

int main() {
    freopen("angry.in", "r", stdin); freopen("angry.out", "w", stdout);

    int n {}, k {}; cin >> n >> k;

    vector<int> a (n, 0);
    for (int i {0}; i < n; ++i) {cin >> a[i];}
    sort(a.begin(), a.end());

    if (n == 1) {
        cout << 0;
    } else {
        pair<int, int> interval {0, 1000000000};
        while (interval.first != interval.second) {
            int median {(interval.first + interval.second) / 2};

            if (sweep(a, median, k)) {
                interval.second = {median};
            } else {
                interval.first = {median + 1};
            }
        }

        cout << interval.first;
    }
}