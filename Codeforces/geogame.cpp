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

#define tc int t; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(a) (a).begin(), (a).end()
#define pb(i) push_back(i);
#define inf 1e18;

typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<set<int>> vsi;
typedef vector<pair<int, int>> vpii;
typedef vector<tuple<int, int, int>> vtiii;
typedef vector<bool> vb;
typedef multiset<int> msi;
typedef set<int> si;
typedef set<pair<int, int>> spii;
typedef set<tuple<int, int, int>> stiii;
typedef map<int, int> mi;
typedef map<int, vector<int>> mivi;
typedef map<int, pair<int, int>> mipii;
typedef map<int, bool> mib;

vi pts[2][2];

void solve() {
    int n; cin >> n;

    pii s; cin >> s.first >> s.second; s.first %= 2, s.second %= 2;

    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;

        pts[x % 2][y % 2].pb(i);
    }

    si a, b; for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) for (const int k : pts[i][j]) ((s.first + s.second + i + j) % 2 == 0 ? a : b).insert(k + 1);

    bool p = a.size() >= b.size();

    if (p) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
           if (p) {
               if (b.empty()) {
                   cout << *a.begin() << endl; a.erase(a.begin());
               } else {
                   cout << *b.begin() << endl; b.erase(b.begin());
               }
           } else {
                int j; cin >> j; a.erase(j); b.erase(j);
           }
        } else {
            if (!p) {
                if (a.empty()) {
                    cout << *b.begin() << endl; b.erase(b.begin());
                } else {
                    cout << *a.begin() << endl; a.erase(a.begin());
                }
            } else {
                int j; cin >> j; a.erase(j); b.erase(j);
            }
        }
    }

    for (int i = 0; i < 2; i++) for (int j = 0; j < 2; j++) pts[i][j].clear();
}

int main() {
    io
    tc

    return 0;
}