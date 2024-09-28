#include <iostream>
#include <array>
#include <set>
#include <cstdio>
using namespace std;

int s {3000000};

void balance (array<multiset<int>, 4> a, multiset<int> b, int c) {
    if (c < 4) {
        for (auto i {b.begin()}; i != b.end(); ++i) {
            for (auto j {next(i)}; j != b.end(); ++j) {
                for (auto k {next(j)}; k != b.end(); ++k) {
                    a[c] = {*i, *j, *k};
                    multiset<int> d = b;
                    d.erase(d.find(*i)); d.erase(d.find(*j)); d.erase(d.find(*k));
                    balance(a, d, c + 1);
                }
            }
        }
    } else {
        array<int, 4> d {0, 0, 0, 0};
        for (int i {0}; i < 4; ++i) {for (int j : a[i]) {d[i] += j;}}
        pair<int, int> t {3000000, 0};
        for (int i : d) {t.first = min(t.first, i); t.second = max(t.second, i);}
        s = min(s, t.second - t.first);
    }
}

int main() {
    freopen("bteams.in", "r", stdin); freopen("bteams.out", "w", stdout);

    multiset<int> cows {};
    for (int i {0}; i < 12; ++i) {int j {}; cin >> j; cows.insert(j);}

    balance({}, cows, 0);

    cout << s;
}