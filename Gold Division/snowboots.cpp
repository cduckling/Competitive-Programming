#include <iostream>
#include <vector>
#include <set>
#include <tuple>
#include <algorithm>
#include <cstdio>
using namespace std;

#define inf 1e9

typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
typedef vector<int> vi;
typedef vector<tuple<int, int, int>> vtiii;
typedef set<int> si;
typedef set<pair<int, int>> spii;
typedef vector<bool> vb;

struct SEGTREE {
    int N; vi Q;

    SEGTREE(int n) {
        N = n; Q.assign(2 * n, 0);
    }

    SEGTREE(const vi& a) : SEGTREE(a.size()) {
        for (int i = 0; i < a.size(); i++) set(i, a[i]);
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

    void set(int pos, const int c) {
        pos += N; Q[pos] = c;

        for (pos /= 2; pos >= 1; pos /= 2) Q[pos] = max(Q[2 * pos], Q[2 * pos + 1]);
    }
};

void solve() {
    int n, b; cin >> n >> b;

    vi f (n + 1); for (int i = 1; i <= n; i++) cin >> f[i];

    vtiii sdi (b); for (int i = 0; i < b; i++) {
        cin >> get<0>(sdi[i]) >> get<1>(sdi[i]); get<2>(sdi[i]) = i;
    } sort(sdi.begin(), sdi.end());

    si ok; ok.insert(0), ok.insert(n);
    spii bad; for (int i = 1; i < n; i++) bad.insert({f[i], i});

    SEGTREE jump (n + 1); jump.set(n, n);

    vb boots (b);

    for (const tiii i : sdi) {
        const int s = get<0>(i), d = get<1>(i);

        while (!bad.empty() && bad.begin()->first <= s) {
            const int pos = bad.begin()->second; bad.erase(bad.begin()); ok.insert(pos);

            auto bef = --ok.lower_bound(pos), aft = ++ok.lower_bound(pos);

            jump.set(pos, pos - *bef), jump.set(*aft, *aft - pos);
        }

        boots[get<2>(i)] = d >= jump.query(0, n);
    }

    for (const int i : boots) cout << i << "\n";
}

int main() {
    freopen("snowboots.in", "r", stdin), freopen("snowboots.out", "w", stdout);

    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();

    return 0;
}