#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

#define inf (1e9)
#define pb(i) push_back(i)

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<bool> vb;

struct SEGTREE {
    int N; vi Q;

    SEGTREE() {}

    SEGTREE(const int n) {
        N = n; Q.assign(2 * n, inf);
    }

    int query(int a, int b) {
        a += N, b += N;

        int val = inf;

        while (a <= b) {
            if (a % 2 == 1) val = min(val, Q[a++]);
            if (b % 2 == 0) val = min(val, Q[b--]);

            a /= 2; b /= 2;
        }

        return val;
    }

    void set(int pos, const int c) {
        pos += N; Q[pos] = c;

        for (pos /= 2; pos >= 1; pos /= 2) Q[pos] = min(Q[2 * pos], Q[2 * pos + 1]);
    }
};

void solve() {
    int n, m, k; cin >> n >> m >> k;

    string s; cin >> s; s = " " + s;

    vvi a (m, vi (m)); for (int i = 0; i < m; i++) for (int j = 0; j < m; j++) cin >> a[i][j];

    vvi cost = a; for (int i = 0; i < m; i++) {
        priority_queue<pii> pq; for (int j = 0; j < m; j++) pq.emplace(-a[i][j], j);

        vb vis (m);

        while (!pq.empty()) {
            const int j = pq.top().second; pq.pop();

            if (vis[j]) continue; vis[j] = true;

            for (int v = 0; v < m; v++) {
                if (!vis[v] && cost[i][j] + a[j][v] < cost[i][v]) {
                    cost[i][v] = cost[i][j] + a[j][v];
                    pq.emplace(-cost[i][v], v);
                }
            }
        }
    }

    vvi pref (m, vi (n + 1)); for (int i = 0; i < m; i++) for (int j = 1; j <= n; j++) pref[i][j] = pref[i][j - 1] + cost[s[j] - 'a'][i];

    vi dp (n + 1, inf);

    vector<SEGTREE> back (m); for (int i = 0; i < m; i++) back[i] = SEGTREE (n + 1), back[i].set(0, 0);

    for (int i = k; i <= n; i++) {
        for (int j = 0; j < m; j++) dp[i] = min(dp[i], pref[j][i] + back[j].query(0, i - k));
        for (int j = 0; j < m; j++) back[j].set(i, dp[i] - pref[j][i]);
    }

    cout << dp[n] << "\n";
}

int main() {
    freopen("cowmbat.in", "r", stdin); freopen("cowmbat.out", "w", stdout);

    ios_base::sync_with_stdio(false); cin.tie(NULL);

    solve();

    return 0;
}