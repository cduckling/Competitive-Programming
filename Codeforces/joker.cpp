#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
using namespace std;

#define tc int t; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(a) (a).begin(), (a).end()
#define pb(i) push_back(i);
#define ceil(a, b) ((a + b - 1) / b)
#define inf 1e18

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

bool in(const pii r, const int v) {
    return r.first <= v && v <= r.second;
}

void solve() {
    int n, l, q; cin >> n >> l >> q;
    int r = l, p = 0, s = n + 1;
    for (int i = 1, x; i <= q; i++) {
        cin >> x;
        (p && x > p) && p++;
        (s <= n && x < s) && s--;
        if (l) {
            if (x > r) {
                r++;
            } else if (x < l) {
                l--;
            } else {
                (l == r) && (l = r = 0);
                if (!p) {
                    p = 1, s = n;
                }
            }
        }
        cout << (l ? min(p, l - 1) + n + 1 - max(s, r + 1) + r - l + 1 : min(p, s - 1) + n + 1 - s) << ' ';
    }

    cout << "\n";
}

int main() {
    io
    tc

    return 0;
}