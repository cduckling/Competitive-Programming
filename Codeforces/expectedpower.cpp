#include <iostream>
#include <vector>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<ll, ll> pii;

const ll m = 1e9 + 7, inv = 285700002;

void solve() {
    ll n {}; cin >> n;

    vector<pii> e (n); for (ll i {0}; i < n; ++i) cin >> e[i].first; for (ll i {0}; i < n; ++i) cin >> e[i].second;

    vector<vector<ll>> dp (n, vector<ll> (1024));

    dp[0][0] = ((10000 - e[0].second) * inv) % m; dp[0][e[0].first] = (e[0].second * inv) % m;

    for (ll i {1}; i < n; ++i) for (ll j {0}; j <= 1023; ++j) dp[i][j] = (dp[i - 1][j] * (((10000 - e[i].second) % m * inv % m) % m) % m + (dp[i - 1][j^(e[i].first)] * (e[i].second * inv % m)) % m) % m;

    ll t {0}; for (int i {0}; i <= 1023; ++i) t = (t + ((i * i) % m * dp[n - 1][i] % m)) % m; cout << t % m << "\n";
}

int main() {
    io
    tc

    return 0;
}