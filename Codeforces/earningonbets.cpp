#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    int n {}; cin >> n;

    vector<int> a (n); for (int i {0}; i < n; ++i) {
        cin >> a[i];
    }

    int l {1}; for (int i {0}; i < n; ++i) {
        l = lcm(l, a[i]);
    }

    vector<int> b (n); for (int i {0}; i < n; ++i) {
        b[i] = l / a[i];
    }

    int s {0}; for (int i : b) {
        s += i;
    }

    if (l <= s) {
        cout << -1 << "\n";
    } else {
        for (int i: b) {
            cout << i << " ";
        }

        cout << "\n";
    }
}

int main() {
    io
    tc

    return 0;
}