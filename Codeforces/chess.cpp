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

    pii q {}; cin >> q.first >> q.second; if (!q.first && !q.second) {
        cout << "YES\n"; return;
    }

    string p {}; cin >> p;

    pii a {0, 0};

    for (int i {0}; i < 1e4; ++i) {
        for (char j : p) {
            switch (j) {
                case 'N': ++a.second; break;
                case 'S': --a.second; break;
                case 'W': --a.first; break;
                case 'E': ++a.first; break;
            }

            if (a == q) {
                cout << "YES\n"; return;
            }
        }
    }

    cout << "NO\n";
}

int main() {
    io
    tc

    return 0;
}