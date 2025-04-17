#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    int n {}, r {}; cin >> n >> r;

    int h {0}, c {0};

    for (int i {0}; i < n; ++i) {
        int p {0}; cin >> p;

        if (p % 2 == 0) {
            h += p; r -= p / 2;
        } else {
            h += p - 1; ++c; r -= p / 2;
        }
    }

    for (int i {1}; i <= c; ++i) {
        --r;

        if (2 * r >= (c - i)) {
            ++h;
        } else {
            break;
        }
    }

    cout << h << "\n";
}

int main() {
    io
    tc

    return 0;
}