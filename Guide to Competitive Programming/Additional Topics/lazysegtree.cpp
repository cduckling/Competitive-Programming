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
#define pb(i) push_back(i)
#define eb(i) emplace_back(i)
#define ceil(a, b) ((a + b - 1) / b)
#define inf (ll) 1e18
#define fail cout << -1 << "\n"; return;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<vector<vector<double>>> vvvd;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;
typedef vector<vector<pair<int, int>>> vvpii;
typedef vector<vector<vector<pair<int, int>>>> vvvpii;
typedef tuple<int, int, int> tii;
typedef vector<tuple<int, int, int>> vtii;
typedef vector<vector<tuple<int, int, int>>> vvtii;
typedef vector<vector<vector<tuple<int, int, int>>>> vvvtii;
typedef set<int> si;
typedef vector<set<int>> vsi;
typedef vector<vector<set<int>>> vvsi;
typedef map<int, int> mii;
typedef map<int, bool> mib;
typedef map<int, double> mid;
typedef vector<map<int, int>> vmii;
typedef vector<map<int, double>> vmid;
typedef vector<map<int, bool>> vmib;

struct SEGTREE {
    int n; vi t, lazy;

    SEGTREE(const int n) {
        this->n = n; t.assign(4 * n, 0), lazy.assign(4 * n, 0);
    }

    SEGTREE(const vi& a) : SEGTREE(a.size()) {
        build(1, 0, n - 1, a);
    }

    void build(const int k, const int l, const int r, const vi& a){
        if (l == r) {
            t[k] = a[l];
        } else {
            build(2 * k, l,  (l + r) / 2, a), build(2 * k + 1, (l + r) / 2 + 1, r, a);

            t[k] = t[2 * k] + t[2 * k + 1];
        }
    }

    void set(const int l, const int r, const int val) {
        set(l, r, val, 1, 0, n - 1);
    }

    void set(const int l, const int r, const int val, const int k, const int a, const int b) {
        if (r < a || l > b) return;

        if (l <= a && b <= r) {
            apply(k, b - a + 1, val);
        } else {
            push(k, a, b);

            set(l, r, val, 2 * k, a, (a + b) / 2), set(l, r, val, 2 * k + 1, (a + b) / 2 + 1, b);

            t[k] = t[2 * k] + t[2 * k + 1];
        }
    }

    int query(const int l, const int r) {
        return query(l, r, 1, 0, n - 1);
    }

    int query(const int l, const int r, const int k, const int a, const int b) {
        if (r < a || l > b) return 0;

        if (l <= a && b <= r) return t[k];

        push(k, a, b);

        return query(l, r, 2 * k, a, (a + b) / 2) + query(l, r, 2 * k + 1, (a + b) / 2 + 1, b);
    }

    void push(const int k, const int a, const int b) {
        apply(2 * k, (a + b) / 2 - a + 1, lazy[k]), apply(2 * k + 1, b - (a + b) / 2, lazy[k]);

        lazy[k] = 0;
    }

    void apply(const int k, const int len, const int val) {
        t[k] += val * len, lazy[k] += val;
    }
};

int main() {
    io

    int n, q; cin >> n >> q;

    vi a (n); for (int i = 0; i < n; ++i) cin >> a[i];

    SEGTREE g (a);

    for (int i = 0; i < q; ++i) {
        char c; cin >> c;

        if (c == '?') {
            int l, r; cin >> l >> r;

            cout << g.query(l, r) << "\n";
        } else {
            int l, r, d; cin >> l >> r >> d;

            g.set(l, r, d);
        }
    }

    return 0;
}
