#include <iostream>
#include <set>
using namespace std;

#define tc int t {}; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    int n {}; cin >> n;

    if (n <= 4) {
        cout << -1 << "\n"; return;
    }

    set<int> o {}, e {}; for (int i {1}; i <= n; ++i) {
        if (i % 2 == 0) {
            e.insert(i);
        } else {
            o.insert(i);
        }
    }

    e.erase(4); o.erase(5);

    for (int i : o) cout << i << " "; cout << 5 << " " << 4; for (int i : e) cout << " " << i; cout << "\n";
}

int main() {
    io
    tc

    return 0;
}