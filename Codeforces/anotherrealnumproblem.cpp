#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<ll, ll> pii;

ll mod = 1e9 + 7;

ll modpow(ll b, ll e) {
    b %= mod; ll r {1};
    while (e > 0) {
        if (e % 2 == 1) r = r * b % mod;

        b = b * b % mod;
        e /= 2;
    }

    return r;
}

void solve() {
    ll n {}; cin >> n;

    vector<ll> a (n); for (ll i {0}; i < n; ++i) cin >> a[i];
    vector<pii> b (n); for (ll i {0}; i < n; ++i) {
        ll c = a[i];

        while (c % 2 == 0) {
            ++b[i].second; c /= 2;
        }

        b[i].first = c;
    }

    priority_queue<pii> pq {}; pq.emplace(-b[0].first, -b[0].second);

    ll m = a[0]; cout << m % mod;

    for (ll i {1}; i < n; ++i) {
        while (!pq.empty() && (b[i].second >= 30 || -pq.top().first <= (b[i].first * modpow(2, b[i].second)))) {
            pii t = pq.top(); pq.pop();
            t.first = -t.first; t.second = -t.second;

            m -= (t.first * modpow(2, t.second)) % mod;
            m += t.first;

            b[i].second += t.second;
        }

        m += (b[i].first * modpow(2, b[i].second)) % mod;

        pq.emplace(-b[i].first, -b[i].second);

        cout << " " << m % mod;
    }

    cout << "\n";
}

int main() {
    io
    tc

    return 0;
}