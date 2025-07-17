#include <iostream>
#include <vector>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    ll n {}, m {}; cin >> n >> m;

    vector<vector<ll>> w (n, vector<ll> (m)); for (ll i {0}; i < n; ++i) for (ll j {0}; j < m; ++j) { char c {}; cin >> c; w[i][j] = c - '0'; }

    ll c {0};

    for (ll i {0}; i < min(n, m) / 2; ++i) {
        vector<ll> p {}; for (ll j {i}; j <= m - i - 1; ++j) p.push_back(w[i][j]); for (ll j {i + 1}; j <= n - i - 1; ++j) p.push_back(w[j][m - i - 1]);

        if (n - i - 1 > i) for (ll j {m - i - 2}; j >= i; --j) p.push_back(w[n - i - 1][j]); if (m - i - 1 > i) for (ll j {n - i - 2}; j > i; --j) p.push_back(w[j][i]);

        ll l {0}; for (ll j {0}; j < p.size(); ++j) if (p[j % p.size()] == 1 && p[(j + 1) % p.size()] == 5 && p[(j + 2) % p.size()] == 4 && p[(j + 3) % p.size()] == 3) ++l; c += l;
    }

    cout << c << "\n";
}

int main() {
    io
    tc

    return 0;
}