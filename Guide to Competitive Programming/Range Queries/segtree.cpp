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

struct SEGTREE {
    int n; vi t;

    SEGTREE(const int n) {
        this->n = n; t.assign(2 * n, 0);
    }

    SEGTREE(const vi& a) : SEGTREE(a.size()) {
        for (int i = 0; i < n; i++) set(i, a[i]);
    }

    int query(int a, int b) {
        a += n, b += n;

        int val = 0;

        while (a <= b) {
            if (a % 2 == 1) val += t[a++];
            if (b % 2 == 0) val += t[b--];

            a /= 2, b /= 2;
        }

        return val;
    }

    void set(int pos, const int val) {
        pos += n; t[pos] = val;

        for (pos /= 2; pos >= 1; pos /= 2) t[pos] = t[2 * pos] + t[2 * pos + 1];
    }
};

int main() {
    io

    int n, q; cin >> n >> q;

    vi a (n + 1); for (int i = 1; i <= n; ++i) cin >> a[i];

    SEGTREE g (a);

    for (int i = 1; i <= q; ++i) {
        char c; cin >> c;

        if (c == '?') {
            int l, r; cin >> l >> r;

            cout << g.query(l, r) << "\n";
        } else {
            int pos, d; cin >> pos >> d;

            g.set(pos, d);
        }
    }

    return 0;
}
