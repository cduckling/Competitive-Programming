#include <iostream>
#include <set>
#include <cstdio>
using namespace std;

bool cards[100000];

int main() {
    freopen("cardgame.in", "r", stdin); freopen("cardgame.out", "w", stdout);

    int n {}; cin >> n;

    int elsie[n];
    for (int i {0}; i < n; ++i) {
        cin >> elsie[i];
        --elsie[i];
        cards[elsie[i]] = true;
    }

    int bessie[n]; int c {0};
    for (int i {0}; i < 2 * n; ++i) {
        if (!cards[i]) {bessie[c] = i; ++c;}
    }

    set<int> a {}, b {};
    for (int i {0}; i < n / 2; ++i) {
        a.insert(bessie[i]);
    }
    for (int i {n / 2}; i < n; ++i) {
        b.insert(bessie[i]);
    }

    int wins {0};

    for (int i {0}; i < n / 2; ++i) {
        if (b.lower_bound(elsie[i]) == b.end()) {
            b.erase(*b.begin());
        } else {
            ++wins;
            b.erase(b.lower_bound(elsie[i]));
        }
    }

    for (int i {n / 2}; i < n; ++i) {
        if (a.lower_bound(elsie[i]) == a.begin()) {
            a.erase(--a.end());
        } else {
            ++wins;
            a.erase(--a.lower_bound(elsie[i]));
        }
    }

    cout << wins;
}