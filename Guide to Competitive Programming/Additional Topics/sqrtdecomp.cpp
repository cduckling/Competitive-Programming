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

ll sqrt(const ll& n) {
    pair<ll, ll> r {0, 1e10};

    while (r.first != r.second) {
        ll mid = (r.first + r.second + 1) / 2;

        if (mid * mid <= n) {
            r.first = mid;
        } else {
            r.second = mid - 1;
        }
    }

    return r.first;
}

int root = 0;

struct SQRTDECOMP {
    vi A, Q; int N;

    SQRTDECOMP(const vi& a, int n) {
        N = n; A = a;

        Q.assign(root, 1e9);

        for (int i = 0; i < n; i++) Q[i / root] = min(Q[i / root], a[i]);
    }

    int query(const int l, const int r) {
        int m = 1e9;

        for (int i = l; i <= r;) {
            if (i % root == 0 && i + root - 1 <= r) {
                m = min(m, Q[i / root]); i += root;
            } else {
                m = min(m, A[i]); ++i;
            }
        }

        return m;
    }

    void update(const int pos, const int val) {
        A[pos] = val;

        Q[pos / root] = 1e9;

        for (int i = (pos / root) * root; i < min((pos / root + 1) * root, N); ++i) Q[pos / root] = min(Q[pos / root], A[i]);
    }
};

int main() {
    io

    int n, q; cin >> n >> q; root = sqrt(n) + 1;

    vi a (n); for (int i = 0; i < n; ++i) cin >> a[i];

    SQRTDECOMP g(a, n);

    for (int i = 0; i < q; ++i) {
        char o; cin >> o;

        if (o == 'U') {
            int pos, val; cin >> pos >> val;

            g.update(pos, val);
        } else {
            int l, r; cin >> l >> r;

            cout << g.query(l, r) << "\n";
        }
    }

    return 0;
}