#include <iostream>
#include <vector>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    int n {}; cin >> n;

    vector<bool> b (n); for (int i {0}; i < n; ++i) {
        char c {}; cin >> c; b[i] = (c == '1');
    }

    int c {0};

    if (b[0] || b[n - 1]) {
        cout << "YES\n"; return;
    }

    for (bool i : b) {
        if (!i) c = 0;
        if (i) ++c;

        if (c >= 2) {
            cout << "YES\n"; return;
        }
    }

    cout << "NO\n";
}

int main() {
    io
    tc

    return 0;
}