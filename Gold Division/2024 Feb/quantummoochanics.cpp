#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <set>
using namespace std;

#define ceil(a, b) ((a + b - 1) / (b))

typedef long long ll;
typedef vector<ll> vi;
typedef tuple<ll, ll, ll> tiii;
typedef set<ll> si;

void solve() {
    ll n; cin >> n;

    vi p (n + 1), s (n + 1); for (ll i = 1; i <= n; i++) cin >> p[i]; for (ll i = 1; i <= n; i++) cin >> s[i];

    vi d (n + 1); si ok; for (ll i = 1; i <= n; i++) ok.insert(i);

    priority_queue<tiii> pq; for (ll i = 1; i < n; i++) pq.emplace(-(2 * ceil(p[i + 1] - p[i], s[i] + s[i + 1]) - i % 2), i, i + 1);

    while (!pq.empty()) {
        const ll t = -get<0>(pq.top()), i = get<1>(pq.top()), j = get<2>(pq.top()); pq.pop();

        if (d[i] || d[j]) continue; d[i] = t, d[j] = t; ok.erase(i), ok.erase(j); if (ok.empty()) break;

        const ll a = ok.lower_bound(i) != ok.begin() ? *--ok.lower_bound(i) : -1, b = ok.upper_bound(j) != ok.end() ? *ok.upper_bound(j) : -1;

        if (a == -1 || b == -1) continue;

        pq.emplace(-(2 * ceil(p[b] - p[a], s[a] + s[b]) - a % 2), a, b);
    }

    cout << d[1]; for (ll i = 2; i <= n; i++) cout << " " << d[i]; cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    ll t; cin >> t; while (t--) solve();

    return 0;
}