#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

typedef long long ll;

int main() {
    freopen("cow.in", "r", stdin); freopen("cow.out", "w", stdout);

    int n {}; cin >> n;

    vector<ll> c {};
    vector<ll> o (n + 1, 0);
    vector<ll> w {};

    for (int i {1}; i <= n; ++i) {
        char j {}; cin >> j;

        if (j == 'C') {
            c.push_back(i);
        } else if (j == 'O') {
            ++o[i];
        } else {
            w.push_back(i);
        }
    }

    for (int i {1}; i <= n; ++i) {o[i] += o[i - 1];}

    long long s {0};

    for (ll C : c) {
        for (ll W : w) {
            if (W > C) {
                s += o[W] - o[C];
            }
        }
    }

    cout << s;
}