#include <iostream>
#include <vector>
#include <set>
using namespace std;

int p[200001], m[200001];

struct SEGTREE {
    vector<int> Q; int N;

    SEGTREE(int n) {
        N = n; Q.assign(2 * n, 0);
    }

    SEGTREE(vector<int> const &a) : SEGTREE(a.size()) {
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
};

void solve() {
    int n {}; cin >> n;

    for (int i {1}; i <= n; ++i) cin >> p[i]; for (int i {1}; i <= n; ++i) m[p[i]] = i;

    set<int> lo {}; int v = 0;

    SEGTREE g (n + 1); for (int i {1}; i <= n; ++i) g.add(i, p[i]);

    cout << 0 << "\n";

    for (int i {1}; i < n; ++i) {
        lo.insert(m[i]); int d = 0; while (*--lo.end() > m[i]) {
            lo.erase(--lo.end()); ++d;
        } if (d) --v;

        g.add(m[i], 1e9 - i);

        if (lo.size() == 1 && *lo.begin() > 1) {
            ++v;
        } else if (lo.size() > 1) {
            int r = *--lo.end() - *----lo.end() - 1;

            if (r) {
                int a = g.query(1, *----lo.end()), b = g.query(1, *--lo.end());

                if (b < a) ++v;
            }
        }

        cout << v << "\n";
    }

    cout << 0 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();

    return 0;
}