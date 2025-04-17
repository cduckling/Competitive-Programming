#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define tc int t {}; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    int n {}; cin >> n;

    vector<int> a (n); for (int i {0}; i < n; ++i) cin >> a[i];

    map<int, int> m {}; for (int i : a) ++m[i];

    int p {0}; for (auto i : m) p += i.second / 2; cout << p << "\n";
}

int main() {
    io
    tc

    return 0;
}