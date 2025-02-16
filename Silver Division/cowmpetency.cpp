#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

#define pb(i) push_back(i)
#define fail {cout << -1 << "\n"; return;}

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pair<int, int>> vpii;
typedef vector<char> vc;
typedef set<int> si;

bool s(const pii& a, const pii& b) {
    if (a.second == b.second) return a.first < b.first; return a.second < b.second;
}

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
            if (a % 2 == 1) val = max(val, Q[a++]);
            if (b % 2 == 0) val = max(val, Q[b--]);

            a /= 2; b /= 2;
        }

        return val;
    }

    void add(int pos, int c) {
        pos += N; Q[pos] = c;

        for (pos /= 2; pos >= 1; pos /= 2) Q[pos] = max(Q[2 * pos], Q[2 * pos + 1]);
    }
};

void solve() {
    int n, q, C; cin >> n >> q >> C;

    vi c (n + 1); for (int i = 1; i <= n; i++) cin >> c[i];

    vpii ah (q); for (int i = 0; i < q; i++) cin >> ah[i].first >> ah[i].second; sort(ah.begin(), ah.end(), s);

    si dumb; for (int i = 1; i <= n; i++) if (c[i] == 0) dumb.insert(i);

    vpii flag; for (int i = 0; i < q; i++) {
        if (i > 0 && ah[i - 1].second == ah[i].second) continue;

        if (!flag.empty() && ah[i].first < flag[flag.size() - 1].second) fail

        flag.pb(ah[i]);
    }

    SEGTREE g (c);

    for (int i = 0; i < flag.size(); i++) {
        for (int j = 1; j <= flag[0].second - 1; j++) if (c[j] == 0) c[j] = 1, g.add(j, 1);

        if (i == 0) {
            if (g.query(1, flag[0].first) >= g.query(flag[0].first + 1, flag[0].second - 1)) {
                if (c[flag[0].second] == 0) {
                    c[flag[0].second] = g.query(1, flag[0].second - 1) + 1, g.add(flag[0].second, c[flag[0].second]);
                } else {
                    if (c[flag[0].second] <= g.query(1, flag[0].second - 1)) fail;
                }
            } else {
                auto it = dumb.upper_bound(flag[0].first); if (it == dumb.begin()) fail int pos = *--it;

                c[pos] = g.query(flag[0].first + 1, flag[0].second - 1), g.add(pos, c[pos]);

                if (c[flag[0].second] == 0) {
                    c[flag[0].second] = g.query(1, flag[0].second - 1) + 1, g.add(flag[0].second, c[flag[0].second]);
                } else {
                    if (c[flag[0].second] <= g.query(1, flag[0].second - 1)) fail;
                }
            }
        } else {
            if (g.query(1, flag[i].first) >= g.query(flag[i].first + 1, flag[i].second - 1)) {
                if (c[flag[i].second] == 0) {
                    c[flag[i].second] = g.query(1, flag[i].second - 1) + 1, g.add(flag[i].second, c[flag[i].second]);
                } else {
                    if (c[flag[i].second] <= g.query(1, flag[i].second - 1)) fail;
                }
            } else {
                auto it = dumb.upper_bound(flag[i].first); if (it == dumb.begin()) fail int pos = *--it;

                if (pos < flag[i - 1].second) fail

                c[pos] = g.query(flag[i].first + 1, flag[i].second - 1), g.add(pos, c[pos]);

                if (c[flag[i].second] == 0) {
                    c[flag[i].second] = g.query(1, flag[i].second - 1) + 1, g.add(flag[i].second, c[flag[i].second]);
                } else {
                    if (c[flag[i].second] <= g.query(1, flag[i].second - 1)) fail;
                }
            }
        }
    }

    for (const int i : c) if (i > C) fail

    cout << max(1, c[1]); for (int i = 2; i <= n; i++) cout << " " << max(1, c[i]); cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t; while (t--) solve();

    return 0;
}