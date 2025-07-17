#include <iostream>
#include <map>
#include <vector>
using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef map<int, int> mii;

int N; int Q[400002];

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

void add(int pos, const int c) {
    pos += N; Q[pos] += c;

    for (pos /= 2; pos >= 1; pos /= 2) Q[pos] = max(Q[2 * pos], Q[2 * pos + 1]);
}

int div(const int n, const vi& a) {
    int div = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            const pii occ = {query(i, i), query(j, j)};

            if (occ.first == 0 || occ.second == 0) continue;

            add(i, -occ.first), add(j, -occ.second);

            if (query(1, n) - occ.first - occ.second <= 0) div = max(div, abs(i - j));

            add(i, occ.first), add(j, occ.second);
        }
    }

    return div;
}

void solve() {
    int n, q; cin >> n >> q;

    vi a (n + 1); for (int i = 1; i <= n; i++) cin >> a[i];

    N = n; for (int i = 1; i <= n; i++) add(a[i], 1);

    for (int i = 0; i < q; i++) {
        int pos, val; cin >> pos >> val;

        add(a[pos], -1); a[pos] = val; add(val, 1);

        cout << div(n, a) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();

    return 0;
}