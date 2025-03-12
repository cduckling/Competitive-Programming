#include <iostream>
#include <vector>
using namespace std;

#define pb(i) push_back(i)

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;

struct SEGTREE {
    vi Q; ll N;

    SEGTREE(ll n) {
        N = n; Q.assign(2 * n, 0);
    }

    SEGTREE(const vi& a) : SEGTREE(a.size()) {
        for (ll i {0}; i < a.size(); i++) set(i, a[i]);
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
        pos += N; Q[pos] = c;

        for (pos /= 2; pos >= 1; pos /= 2) Q[pos] = Q[2 * pos] + Q[2 * pos + 1];
    }
};

void solve() {
    ll n; cin >> n;

    vi b (n + 1); for (ll i = 1; i <= n; i++) cin >> b[i];

    vi cur (n + 1); cur[b[1]] = 1;

    SEGTREE pref (n + 1); pref.set(1, 1);

    ll cnt = 0;

    for (ll i = 2; i <= n; i++) {
        cnt += pref.query(cur[b[i]] + 1, i - 1);

        pref.set(cur[b[i]], 0); cur[b[i]] = i; pref.set(i, 1);
    }

    cout << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();

    return 0;
}