#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

#define pb(a) push_back(a)

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;

bool p[1001];

void solve() {
    ll n, mod; cin >> n >> mod;

    vi P; for (ll i = 2; i <= n; i++) if (!p[i]) P.pb(i); const ll num = P.size();

    vvi dp (num, vi (n + 1)); for (ll i = 0; i <= n; i++) {
        dp[num - 1][i] = 1; ll cur = P[num - 1]; while (cur <= i) dp[num - 1][i] += cur, dp[num - 1][i] %= mod, cur *= P[num - 1];
    }

    for (ll i = num - 2; i >= 0; i--) for (ll j = 0; j <= n; j++) {
        dp[i][j] = dp[i + 1][j]; ll cur = P[i]; while (cur <= j) dp[i][j] += cur * dp[i + 1][j - cur], dp[i][j] %= mod, cur *= P[i];
    }

    cout << (dp[0][n] + mod) % mod << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    freopen("exercise.in", "r", stdin), freopen("exercise.out", "w", stdout);

    for (ll i = 2; i <= 1000; i++) if (!p[i]) for (ll j = 2 * i; j <= 1000; j += i) p[j] = true;

    solve();

    return 0;
}