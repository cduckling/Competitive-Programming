#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define tc ll t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void solve() {
    ll n {}; cin >> n;

    vector<ll> a (n + 1); for (ll i {1}; i <= n; ++i) cin >> a[i];

    map<ll, vector<ll>> adj {};

    for (ll i {2}; i <= n; ++i) adj[a[i] - 1 + i].push_back(a[i] - 1 + i + i - 1);

    map<ll, ll> dp {};

    for (auto i = adj.rbegin(); i != adj.rend(); ++i) {
        const auto& k = *i;

        for (ll j : k.second) dp[k.first] = max(dp[k.first], (adj[j].empty() ? j : dp[j]));
    }

    cout << max(n, dp[n]) << "\n";
}

int main() {
    io
    tc

    return 0;
}