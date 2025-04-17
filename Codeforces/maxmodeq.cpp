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

struct SEGTREE {
    vi Q; int N;

    SEGTREE(int n) {
        N = n; Q.assign(2 * n, 0);
    }

    SEGTREE(const vi& a) : SEGTREE(a.size()) {
        for (int i {0}; i < a.size(); i++) add(i, a[i]);
    }

    int query(int a, int b) {
        a += N, b += N;

        int val = 0;

        while (a <= b) {
            if (a % 2 == 1) val = gcd(val, Q[a++]);
            if (b % 2 == 0) val = gcd(val, Q[b--]);

            a /= 2; b /= 2;
        }

        return val;
    }

    void add(int pos, int c) {
        pos += N; Q[pos] += c;

        for (pos /= 2; pos >= 1; pos /= 2) Q[pos] = gcd(Q[2 * pos], Q[2 * pos + 1]);
    }
};
void solve() {
    int n, q; cin >> n >> q;

    vi a (n); for (int i = 0; i < n; i++) cin >> a[i]; for (int i = 0; i < n - 1; i++) a[i] = abs(a[i] - a[i + 1]);

    SEGTREE g (a);

    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;

        cout << g.query(l - 1, r - 2) << " ";
    }

    cout << "\n";
}

int main() {
    io
    tc

    return 0;
}