#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define square(a) ((a % mod) * (a % mod) % mod)

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

ll mod = 1e9 + 7;

ll ops(const ll val, const ll a, const ll d, const vi& m) {
    ll ops = 0; for (ll i = 0; i < a; i++) ops += max(0ll, min(d, val - m[i])); return ops;
}

void solve() {
    ll n, d; cin >> n >> d;

    ll a, b; cin >> a >> b;

    vi m (n); for (ll i = 0; i < n; i++) cin >> m[i]; sort(m.begin(), m.end(), greater<ll>());

    pii r = {m[a - 1], m[0] + d};

    while (r.first != r.second) {
        const ll mid = (r.first + r.second) / 2;

        if (ops(mid, a, d, m) >= d * (a - b)) {
            r.second = mid;
        } else {
            r.first = mid + 1;
        }
    }

    vi res = m; for (ll i = 0; i < a; i++) res[i] = m[i] + max(0ll, min(d, r.first - m[i]));

    ll rem = ops(r.first, a, d, m) - d * (a - b); for (ll i = 0; i < a; i++) if (rem && m[i] < res[i] && res[i] < m[i] + d) res[i]--, rem--;

    ll sum = 0; for (ll i = 0; i < n; i++) sum += square(res[i]), sum %= mod;

    cout << (sum + mod) % mod << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();

    return 0;
}