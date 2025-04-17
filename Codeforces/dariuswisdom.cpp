#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

#define tc int t {}; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb(i) push_back(i);
#define inf 1e18;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpii;
typedef vector<bool> vb;
typedef set<int> si;
typedef map<int, int> mi;
typedef map<int, vector<int>> mvi;
typedef map<int, pair<int, int>> mpii;
typedef map<int, bool> mb;

void solve() {
    int n {}; cin >> n;

    vi h (n); for (int i {0}; i < n; ++i) cin >> h[i];

    si a {}, b {}, c {}; for (int i {0}; i < n; ++i) {
        if (h[i] == 0) {
            a.insert(i);
        } else if (h[i] == 1) {
            b.insert(i);
        } else {
            c.insert(i);
        }
    }

    vpii ops {};

    for (int i {0}; i < a.size(); ++i) {
        if (h[i] == 0) {
            ;
        } else if (h[i] == 1) {
            ops.emplace_back(i, *--a.end());

            --h[i]; ++h[*--a.end()];

            b.insert(*--a.end()); b.erase(i);
            a.erase(--a.end()); a.insert(i);
        } else {
            ops.emplace_back(i, *--b.end()); ops.emplace_back(i, *--a.end());

            --h[i]; ++h[*--b.end()]; --h[i]; ++h[*--a.end()];

            c.erase(i); c.insert(*--b.end());
            b.insert(i); b.erase(--b.end());
            b.erase(i); b.insert(*--a.end());
            a.insert(i); a.erase(--a.end());
        }
    }

    for (int i = a.size(); i < a.size() + b.size(); ++i) {
        if (h[i] == 1) {
            ;
        } else {
            ops.emplace_back(i, *--b.end());

            --h[i]; ++h[*--b.end()];

            c.erase(i); c.insert(*--b.end());
            b.insert(i); b.erase(--b.end());
        }
    }

    cout << ops.size() << "\n"; for (auto op : ops) cout << op.first + 1 << " " << op.second + 1 << "\n";
}

int main() {
    io
    tc

    return 0;
}