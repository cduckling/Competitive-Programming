#include <iostream>
#include <set>
#include <cstdio>
using namespace std;

int n {}, g {};

set<int> groups[500000];

int main() {
    freopen("invite.in", "r", stdin); freopen("invite.out", "w", stdout);

    cin >> n >> g;

    for (int i {0}; i < g; ++i) {
        int s {}; cin >> s;

        for (int j {0}; j < s; ++j) {
            int k {}; cin >> k;
            groups[i].insert(k);
        }
    }

    set<int> a {1};
    while (true) {
        bool p {true};

        for (int i {0}; i < g; ++i) {
            for (int a_ : a) {
                groups[i].erase(a_);
            }

            if (groups[i].size() == 1) {
                p = false;
                a.insert(*groups[i].begin());
            }
        }

        if (p) {
            break;
        }
    }

    cout << a.size();
}