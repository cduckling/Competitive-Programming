#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    int n {}; cin >> n;

    vector<int> a (n); for (int i {0}; i < n; ++i) cin >> a[i]; sort(a.begin(), a.end());

    pair<int, int> r {2, n};

    while (r.first != r.second) {
        const int mid = (r.first + r.second + 1) / 2;

        bool w = false;

        for (int i {0}; i <= n - mid; ++i) if (a[i] + a[i + 1] > a[i + mid - 1]) w = true;

        if (w) {
            r.first = mid;
        } else {
            r.second = mid - 1;
        }
    }

    cout << n - r.first << "\n";
}

int main() {
    io
    tc

    return 0;
}