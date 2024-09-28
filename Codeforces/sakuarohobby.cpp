#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<int, bool> pib;

void dfs(int ver, const int c, vector<bool>& v, const vector<pib>& p, map<int, vector<int>>& cyc) {
    if (v[ver]) {
        return;
    } else {
        v[ver] = true;
        cyc[c].push_back(ver);

        dfs(p[ver].first, c, v, p, cyc);
    }
}

void solve() {
    int n {}; cin >> n;

    vector<pib> p (n); for (int i {0}; i < n; ++i) {
        cin >> p[i].first; --p[i].first;
    } for (int i {0}; i < n; ++i) {
        char b {}; cin >> b;
        p[i].second = (b == '1');
    }

    vector<bool> v (n);
    map<int, vector<int>> cyc {};

    int c = 0;
    for (int i {0}; i < n; ++i) {
        if (!v[i]) {
            ++c;

            dfs(i, c, v, p, cyc);
        }
    }

    map<int, int> b {};
    for (const auto& i : cyc) {
        int blk = 0; for (int j : i.second) blk += !p[j].second;
        for (int j : i.second) b[j] = blk;
    }

    for (const auto& i : b) cout << i.second << " "; cout << "\n";
}

int main() {
    io
    tc

    return 0;
}