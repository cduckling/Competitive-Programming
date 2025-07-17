#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

#define pb(i) push_back(i)

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;

struct SEGTREE {
    ll N; vi Q;

    SEGTREE(const ll n) {
        N = n; Q.assign(2 * n, 0);
    }

    ll query(ll a, ll b) {
        a += N, b += N;

        ll val = 0;

        while (a <= b) {
            if (a % 2 == 1) val += Q[a++];
            if (b % 2 == 0) val += Q[b--];

            a /= 2; b /= 2;
        }

        return val;
    }

    void set(ll pos, const ll c) {
        pos += N; Q[pos] += c;

        for (pos /= 2; pos >= 1; pos /= 2) Q[pos] = Q[2 * pos] + Q[2 * pos + 1];
    }
};

void solve() {
    ll n; cin >> n;

    vi a (n + 1); for (ll i = 1; i <= n; i++) cin >> a[i];

    ll inv = 0;

    SEGTREE freq (n + 1); for (ll i = 1; i <= n; i++) inv += freq.query(a[i] + 1, n), freq.set(a[i], 1);

    vvi pos (n + 1); for (ll i = 1; i <= n; i++) pos[a[i]].pb(i);

    SEGTREE pref (n + 1);

    vi res (n + 1); res[n] = inv; for (ll i = n - 1; i >= 0; i--) {
        res[i] = res[i + 1]; for (const ll j : pos[i + 1]) pref.set(j, 1); for (const ll j : pos[i]) res[i] -= pref.query(1, j - 1);
    }

    for (ll i = 0; i < n; i++) cout << res[i] << "\n";
}

int main() {
    freopen("haircut.in", "r", stdin); freopen("haircut.out", "w", stdout);

    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();

    return 0;
}