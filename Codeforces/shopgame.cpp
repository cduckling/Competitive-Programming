#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<ll, ll> pii;

bool s (pii a, pii b) {
    return b.second > a.second;
}

void solve() {
    ll n {}, k {}; cin >> n >> k;

    vector<ll> a (n); for (ll i {0}; i < n; ++i) cin >> a[i];
    vector<ll> b (n); for (ll i {0}; i < n; ++i) cin >> b[i];

    if (k == 0) {
        ll g {0}; for (ll i {0}; i < n; ++i) if (b[i] >= a[i]) g += b[i] - a[i]; cout << g << "\n"; return;
    }

    vector<pii> c (n); for (ll i {0}; i < n; ++i) c[i] = {a[i], b[i]}; sort(c.begin(), c.end(), s);

    vector<ll> m (n); priority_queue<ll> pq {};
    for (ll i {n - k}; i < n; ++i) {
        m[n - k] += c[i].first; pq.push(c[i].first);
    }
    for (ll i {n - k - 1}; i >= 0; --i) {
        if (c[i].first < pq.top()) {
            m[i] = m[i + 1] - pq.top() + c[i].first;
            pq.pop(); pq.push(c[i].first);
        } else {
            m[i] = m[i + 1];
        }
    }

    ll p {0}, g {0};

    for (ll i {0}; i < n - k; ++i) {
        if (c[i].second >= c[i].first) p += c[i].second - c[i].first;
        g = max(g, p - m[i + 1]);
    }

    cout << g << "\n";
}

int main() {
    io
    tc

    return 0;
}