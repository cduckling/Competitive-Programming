#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

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

int main() {
    io freopen("poetry.in", "r", stdin); freopen("poetry.out", "w", stdout);

    ll n {}, m {}, k {}; cin >> n >> m >> k;

    vector<pair<ll, ll>> words (n); for (ll i {0}; i < n; ++i) {
        cin >> words[i].first >> words[i].second; --words[i].second;
    }
    vector<ll> scheme (26); for (ll i {0}; i < m; ++i) {
        char r {}; cin >> r; ++scheme[r - 'A'];
    }

    vector<ll> dp (k + 1); dp[0] = 1; for (auto word : words) {
        ++dp[word.first]; dp[word.first] %= mod;
    } for (ll i {1}; i <= k; ++i) {
        if (!dp[i]) continue;

        for (auto word : words) {
            if (word.first + i > k) continue;

            dp[i] %= mod; dp[word.first + i] += dp[i]; dp[word.first + i] %= mod;
        }
    }

    vector<ll> c (n); for (auto word: words) {
        dp[k - word.first] %= mod; c[word.second] += dp[k - word.first]; c[word.second] %= mod;
    }

    ll poems {1};
    for (ll i {0}; i < 26; ++i) {
        if (!scheme[i]) continue;

        ll p {0};
        for (ll c_ : c) {
            if (!c_) continue;

            p += modpow(c_ % mod, scheme[i] % (mod - 1)) % mod; p %= mod;
        }

        poems *= p; poems %= mod;
    }

    cout << poems % mod;

    return 0;
}