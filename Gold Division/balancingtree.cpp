#include <iostream>
#include <vector>
#include <random>
using namespace std;

#define pb(a) push_back(a)
#define fir first
#define sec second

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vpii;

bool b = false;

pii u(pii a, pii b) {
    pii res = {max(a.fir, b.fir), min(a.sec, b.sec)};

    if (res.fir > res.sec) return {-1, 0}; return res;
}

bool dfs(const int ver, const int par, const int mid, pii ok, vi& s, const vpii& lr, const vvi& adj) {
    vi c; for (const int i : adj[ver]) if (i != par) c.pb(i);

    pii poss = u(lr[ver], ok); if (poss.fir == -1) return false;

    if (poss.fir - mid >= ok.fir) {
        s[ver] = poss.fir;
    } else {
        s[ver] = min(poss.sec, ok.fir + mid);
    }

    ok = u(ok, {s[ver] - mid, s[ver] + mid}); if (ok.fir == -1) return false;

    bool res = true; for (const int i : c) res &= dfs(i, ver, mid, ok, s, lr, adj); if (!res) return false; return true;
}

bool check(const int mid, vi& s, vpii& lr, const vvi& adj) {
    for (int i = lr[1].fir; i <= lr[1].sec; i++) {
        s[1] = i; if (dfs(1, -1, mid, {max(i - mid, 0), i + mid}, s, lr, adj)) return true;
    }

    return false;
}

void solve() {
    int n; cin >> n;

    vi p (n + 1); for (int i = 2; i <= n; ++i) cin >> p[i];

    vvi adj (n + 1); for (int i = 2; i <= n; i++) adj[i].pb(p[i]), adj[p[i]].pb(i);

    vpii lr (n + 1); for (int i = 1; i <= n; i++) cin >> lr[i].fir >> lr[i].sec;

    vi s (n + 1);

    pii r = {0, 1e9};

    while (r.fir != r.sec) {
        const int mid = (r.fir + r.sec) / 2;

        if (check(mid, s, lr, adj)) {
            r.sec = mid;
        } else {
            r.fir = mid + 1;
        }
    }

    cout << r.fir << "\n";

    if (b) {
        check(r.fir, s, lr, adj); cout << s[1]; for (int i = 2; i <= n; i++) cout << " " << s[i]; cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin >> t; cin >> b; while (t--) solve();

    return 0;
}