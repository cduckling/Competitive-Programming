#include <iostream>
#include <vector>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    int n {}; cin >> n;

    vector<pii> a (n); for (int i {0}; i < n; ++i) cin >> a[i].first >> a[i].second;

    int w {0}, h {0}; for (auto i : a) {
        w = max(w, i.first);
        h = max(h, i.second);
    }

    cout << 2 * (h + w) << "\n";
}

int main() {
    io
    tc

    return 0;
}