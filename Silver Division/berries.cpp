#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

bool s (int a, int b) {return a > b;}

int main() {
    freopen("berries.in", "r", stdin); freopen("berries.out", "w", stdout);

    int n {}, k {}; cin >> n >> k;

    vector<int> b (n, 0);
    for (int i {0}; i < n; ++i) {cin >> b[i];}
    sort(b.begin(), b.end());

    int berries {0};

    for (int e {1}; e <= b[n - 1]; ++e) {
        vector<int> b_ = b;

        int buckets {0}; pair<int, int> bessie {0, 0};

        for (int i {0}; i < n; ++i) {buckets += b_[i] / e; b_[i] %= e;}

        if (buckets < k / 2) {
            break;
        } else {
            buckets -= k / 2;
            bessie.first = {min(buckets, k / 2) * e}; bessie.second = {min(buckets, k / 2)};
            sort(b_.begin(), b_.end(), s);
            for (int i {0}; i < min(n, k / 2 - bessie.second); ++i) {bessie.first += b_[i];}
        }

        berries = max(berries, bessie.first);
    }

    cout << berries;
}