#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define inf static_cast<ll>(2 * 1e9)

typedef long long ll;
typedef vector<ll> vi;

void solve() {
    ll n; cin >> n;

    vi a (2 * n + 1); for (ll i = 1; i <= n; i++) cin >> a[i]; for (ll i = n + 1; i <= 2 * n; i++) a[i] = a[i - n];

    vi dp (2 * n + 1); stack<ll> s; for (ll i = 1; i <= 2 * n; i++) {
        if (s.empty()) {
            dp[i] = -1; s.push(i);
        } else {
            while (!s.empty() && a[s.top()] > a[i]) s.pop(); dp[i] = s.empty() ? -1 : s.top(); s.push(i);
        }
    }

    ll sum = 0; for (ll i = 1; i <= n; i++) sum += a[i];

    vi time (n + 1); for (ll i = n + 1; i <= 2 * n; i++) {
        ll prev = inf; for (ll j = i - 1; j > dp[i]; j--) time[i - j] -= min(prev, a[j]) - a[i], prev = min(prev, a[j]);
    }

    for (ll i = 1; i <= n; i++) time[i] += time[i - 1]; for (ll i = 1; i <= n; i++) cout << time[i] + sum << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();

    return 0;
}