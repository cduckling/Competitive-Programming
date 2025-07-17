#include <iostream>
#include <vector>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    int n {}; cin >> n;

    int t {}, f {}; vector<int> a (2 * n); for (int i {0}; i < 2 * n; ++i) {
        cin >> a[i];

        if (a[i]) {
            ++t;
        } else {
            ++f;
        }
    }

    cout << n - (t / 2 + f / 2) << " " << min(t, f) << "\n";
}

int main() {
    io
    tc

    return 0;
}