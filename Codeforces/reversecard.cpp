#include <iostream>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    int n {}, m {}; cin >> n >> m;

    int p {0};

    for (int b {1}; b <= m; ++b) {
        int r = {n / b};

        int p_ {p};

        for (int a {1}; a <= r; ++a) {
            if ((a + 1) % b == 0) ++p;
        }

        if (p == p_) break;
    }

    cout << p << "\n";
}

int main() {
    io
    tc

    return 0;
}