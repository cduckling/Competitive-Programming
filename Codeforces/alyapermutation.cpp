#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    int n {}; cin >> n;

    vector<int> a (n);

    if (n % 2 == 0) {
        int r {0}; for (int i {0}; i < 31; ++i) if ((1<<i) <= n && ((1<<i)&n) == 0) r += (1<<i);

        cout << (n|r) << "\n";

        if (r == 1) {
            for (int i {2}; i <= n - 1; ++i) cout << i << " "; cout << 1 << " " << n << "\n"; return;
        }

        set<int> s; for (int i {1}; i <= n; ++i) s.insert(i); s.erase(1); s.erase(r - 1); s.erase(r); s.erase(n);
        for (const int& i : s) cout << i << " "; cout << 1  << " " << r - 1 << " " << r << " " << n << "\n";
    } else {
        cout << n << "\n"; for (int i {2}; i <= n - 2; ++i) cout << i << " "; cout << 1 << " " << n - 1 << " " << n << "\n";
    }
}

int main() {
    io
    tc

    return 0;
}