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
    vi Q; int N;

    SEGTREE(int n) {
        N = n; Q.assign(2 * n, 0);
    }

    SEGTREE(vi const &a) : SEGTREE(a.size()) {
        for (int i {0}; i < a.size(); i++) add(i, a[i]);
    }

    int query(int a, int b) {
        a += N, b += N;

        int val = 0;

        while (a <= b) {
            if (a % 2 == 1) val += Q[a++];
            if (b % 2 == 0) val += Q[b--];

            a /= 2; b /= 2;
        }

        return val;
    }

    void add(int pos, int c) {
        pos += N; Q[pos] += c;

        for (pos /= 2; pos >= 1; pos /= 2) Q[pos] = Q[2 * pos] + Q[2 * pos + 1];
    }
};

/*struct SEGTREE {
    vi Q; int N;

    SEGTREE(int n) {
        N = n; Q.assign(2 * n, 0);
    }

    SEGTREE(vi const &a) : SEGTREE(a.size()) {
        for (int i {0}; i < a.size(); i++) add(i, a[i]);
    }

    int query(int a, int b) {
        a += N, b += N;

        int val = 1e9;

        while (a <= b) {
            if (a % 2 == 1) val = min(val, Q[a++]);
            if (b % 2 == 0) val = min(val, Q[b--]);

            a /= 2; b /= 2;
        }

        return val;
    }

    void add(int pos, int c) {
        pos += N; Q[pos] += c;

        for (pos /= 2; pos >= 1; pos /= 2) Q[pos] = min(Q[2 * pos], Q[2 * pos + 1]);
    }
};*/

int main() {
    io

    int n {}, q {}; cin >> n >> q;

    vi a (n); for (int i {0}; i < n; ++i) cin >> a[i];

    SEGTREE segtree(a);

    for (int i {0}; i < q; ++i) {
        char c {}; cin >> c;

        if (c == '?') {
            int l {}, r {}; cin >> l >> r;

            cout << segtree.sum(l, r) << "\n";
        } else {
            int pos {}, d {}; cin >> pos >> d;

            segtree.add(pos, d);
        }
    }

    return 0;
}