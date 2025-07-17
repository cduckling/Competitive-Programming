#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

bool q(const int a, const int b) {
    cout << "? " << a << " " << b << endl;
    bool c {}; cin >> c; return c;
}

void solve() {
    int n {}; cin >> n;

    vector<int> p (n); p[1] = 0;

    int e {2}; while (q(1, e)) ++e; for (int i {2}; i < e; ++i) p[i] = 0; p[e] = 1;

    int c {2};

    for (int i {e + 1}; i < n; ++i) {
        while (q(i, c)) ++c; p[i] = c; ++c;
    }

    cout << "! "; for (int i {1}; i < n; ++i) cout << p[i] << " "; cout << endl;
}

int main() {
    io
    tc

    return 0;
}