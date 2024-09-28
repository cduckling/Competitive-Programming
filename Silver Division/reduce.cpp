#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef vector<pair<int, int>> pairs;
typedef pair<int, int> group;

bool s (group a, group b) {return a.second < b.second;}

int sold {1600000000};
void sell(pairs a, pairs b, int p) {
    if (p == 3) {
        sold = {min((a[0].first - a[a.size() - 1].first) * (b[0].second - b[b.size() - 1].second), sold)};
    } else {
        ++p;

        vector<pairs> l (4, a);
        vector<pairs> m (4, b);
        vector<group> o (4, {0, 0});

        o[0] = a[0]; o[1] = a[a.size() - 1];
        o[2] = b[0]; o[3] = b[b.size() - 1];

        l[0].erase(l[0].begin()); l[1].erase(--l[1].end());
        m[2].erase(m[2].begin()); m[3].erase(--m[3].end());

        for (int i {0}; i < 4; ++i) {
            if (i < 2) {
                for (auto j {m[i].begin()}; j != m[i].end(); ++j) {if (*j == o[i]) {m[i].erase(j); break;}}
            } else {
                for (auto j {l[i].begin()}; j != l[i].end(); ++j) {if (*j == o[i]) {l[i].erase(j); break;}}
            }
        }

        sell(l[0], m[0], p);
        sell(l[1], m[1], p);
        sell(l[2], m[2], p);
        sell(l[3], m[3], p);
    }
}

int main() {
    freopen("reduce.in", "r", stdin); freopen("reduce.out", "w", stdout);

    int n {}; cin >> n;

    pairs a (n, {0, 0});
    pairs b (n, {0, 0});

    for (int i {0}; i < n; ++i) {cin >> a[i].first >> a[i].second; b[i] = a[i];}

    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), s);

    sell(a, b, 0);

    cout << sold;
}