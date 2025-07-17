#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    int n {}; cin >> n;

    vector<int> a (n + 1); for (int i {1}; i <= n; ++i) cin >> a[i];

    map<int, vector<int>> pos {}; for (int i {1}; i <= n; ++i) pos[a[i]].push_back(i);

    vector<pii> r (n + 1, {n + 1, 0}); for (int i {1}; i <= n; ++i) {
        r[i] = r[i - 1];

        if (pos[i].empty()) continue;

        r[i].first = min(r[i].first, pos[i][0]);
        r[i].second = max(r[i].second, pos[i][pos[i].size() - 1]);
    }

    bool s = true; for (int i {1}; i <= n; ++i) if (r[i].second != 0 && r[i].second - r[i].first + 1 > i) s = false; if (!s) {
        cout << 0 << "\n"; return;
    }

    pair<int, int> p {1, n};

    for (int i {1}; i <= n; ++i) if (r[i] != r[i - 1]) p.first = max(p.first, r[i].first - (i - (r[i].second - r[i].first + 1)));
    for (int i {1}; i <= n; ++i) if (r[i] != r[i - 1]) p.second = min(p.second, i - (r[i].second - r[i].first + 1) + r[i].second);

    cout << p.second - p.first + 1 << "\n";
}

int main() {
    io
    tc

    return 0;
}