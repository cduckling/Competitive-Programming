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

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb(i) push_back(i);
#define inf 1e18;

typedef long long ll;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpii;
typedef vector<tuple<int, int, int>> vtiii;
typedef vector<bool> vb;
typedef set<int> si;
typedef map<int, int> mi;
typedef map<int, vector<int>> mvi;
typedef map<int, pair<int, int>> mpii;
typedef map<int, bool> mb;

struct BIT {
    vi Q; int N;

    BIT(int n) {
        N = n; Q.assign(n, 0);
    }

    BIT(vi const &a) : BIT(a.size()) {
        for (int i {0}; i < a.size(); i++) add(i, a[i]);
    }

    int pref(int r) {
        int tot = 0; for (; r >= 0; r = (r & (r + 1)) - 1) tot += Q[r]; return tot;
    }

    int range(int l, int r) {
        return pref(r) - pref(l - 1);
    }

    void add(int pos, int c) {
        for (; pos < N; pos = pos | (pos + 1)) Q[pos] += c;
    }
};

int main() {
    io

    int n {}, q {}; cin >> n >> q;

    vi a (n); for (int i {0}; i < n; ++i) cin >> a[i];

    BIT bit (a, n);

    for (int i {0}; i < q; ++i) {
        int pos {}, c {}; cin >> pos >> c;

        bit.add(pos, c);

        cout << bit.pref(n - 1) << "\n";
    }

    return 0;
}