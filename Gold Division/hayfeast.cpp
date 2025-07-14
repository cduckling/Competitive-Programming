#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

#define inf 1e18

typedef long long ll;
typedef vector<ll> vi;

struct SEGTREE {
    ll n; vi t;

    SEGTREE(const ll n) {
        this->n = n; t.assign(2 * n, 0);
    }

    SEGTREE(const vi& a) : SEGTREE(a.size()) {
        for (ll i = 0; i < n; i++) set(i, a[i]);
    }

    ll query(ll a, ll b) {
        a += n, b += n;

        ll val = 0;

        while (a <= b) {
            if (a % 2 == 1) val = max(val, t[a++]);
            if (b % 2 == 0) val = max(val, t[b--]);

            a /= 2; b /= 2;
        }

        return val;
    }

    void set(ll pos, const ll val) {
        pos += n; t[pos] = val; for (pos /= 2; pos >= 1; pos /= 2) t[pos] = max(t[2 * pos], t[2 * pos + 1]);
    }
};

void solve() {
    ll n, m; cin >> n >> m;

    vi f (n + 1), S (n + 1); for (ll i = 1; i <= n; i++) cin >> f[i] >> S[i]; for (ll i = 1; i <= n; i++) f[i] += f[i - 1]; SEGTREE s (S);

    ll res = inf;

    auto it = f.begin();

    for (ll i = 1; i <= n; i++) {
        ll j = lower_bound(it, f.end(), m + f[i - 1]) - f.begin(); if (j > n) break; res = min(res, s.query(i, j));
    }

    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    freopen("hayfeast.in", "r", stdin), freopen("hayfeast.out", "w", stdout);

    solve();

    return 0;
}