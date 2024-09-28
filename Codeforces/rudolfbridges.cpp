#include <iostream>
#include <vector>
#include <set>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    ll n {}, m {}, k {}, d {}; cin >> n >> m >> k >> d;

    vector<ll> cost (n + 1);

    for (ll i {0}; i < n; ++i) {
        vector<ll> r (m); for (ll j {0}; j < m; ++j) {cin >> r[j]; ++r[j];}

        vector<ll> dp (m, 9000000000000000000); dp[0] = 1;
        multiset<ll> dp_ {1}; for (ll j {1}; j <= min(d + 1, m - 1); ++j) {dp[j] = r[j] + r[0]; dp_.insert(dp[j]);}

        for (ll j {d + 2}; j < m; ++j) {
            dp_.erase(dp_.find(dp[j - d - 2])); dp[j] = r[j] + *dp_.begin(); dp_.insert(dp[j]);
        }

        cost[i + 1] = dp[m - 1];
    }

    for (ll i {1}; i <= n; ++i) cost[i] += cost[i - 1];

    ll install {9000000000000000000}; for (ll i {1}; i <= n - k + 1; ++i) install = min(install, cost[i + k - 1] - cost[i - 1]); cout << install << "\n";
}

int main() {
    io
    tc

    return 0;
}