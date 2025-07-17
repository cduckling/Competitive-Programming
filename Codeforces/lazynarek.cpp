#include <iostream>
#include <vector>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

char a[26];
ll b[26];

const string narek = "narek";

pair<char, ll> g (const string& s, char c) {
    pair<char, ll> r {c, 0};

    for (char i : s) if (i == r.first) {
        r.first = a[r.first - 'a'];
        ++r.second;
    }

    return r;
}

void solve() {
    ll n {}, m {}; cin >> n >> m;

    vector<string> p (n); for (ll i {0}; i < n; ++i) for (ll j {0}; j < m; ++j) { char c {}; cin >> c; if (a[c - 'a']) p[i] += c; }

    vector<vector<ll>> dp (n, vector<ll> (5, -1000000000)); for (ll i {0}; i < n; ++i) dp[i][0] = 0;

    dp[0][b[g(p[0], 'n').first - 'a']] = max(dp[0][b[g(p[0], 'n').first - 'a']], static_cast<ll>(2 * g(p[0], 'n').second - p[0].length()));

    for (ll i {1}; i < n; ++i) {
        for (ll j {0}; j < 5; ++j) dp[i][j] = dp[i - 1][j];

        for (ll j {0}; j < 5; ++j) {
            if (dp[i - 1][j] == -1000000000) continue;

            pair<char, ll> r = g(p[i], narek[j]);

            dp[i][b[r.first - 'a']] = max(dp[i][b[r.first - 'a']], static_cast<ll>(dp[i - 1][j] + 2 * r.second - p[i].length()));
        }
    }

    ll s {0}; for (ll i {0}; i < 5; ++i) s = max(s, dp[n - 1][i] - 2 * i); cout << s << "\n";
}

int main() {
    io

    a['n' - 'a'] = 'a'; a['a' - 'a'] = 'r'; a['r' - 'a'] = 'e'; a['e' - 'a'] = 'k'; a['k' - 'a'] = 'n';

    b['n' - 'a'] = 0; b['a' - 'a'] = 1; b['r' - 'a'] = 2; b['e' - 'a'] = 3; b['k' - 'a'] = 4;

    tc

    return 0;
}