#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
using namespace std;

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt,lzcnt,abm,bmi,bmi2,fma,tune=native")

#define tc ll t; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(a) (a).begin(), (a).end()
#define pb(i) push_back(i)
#define eb(i) emplace_back(i)
#define inf (ll) 1e18
#define fir first
#define sec second

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<vector<vector<ll>>> vvvi;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<vector<vector<double>>> vvvd;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<vector<vector<bool>>> vvvb;
typedef pair<ll, ll> pii;
typedef vector<pair<ll, ll>> vpii;
typedef vector<vector<pair<ll, ll>>> vvpii;
typedef vector<vector<vector<pair<ll, ll>>>> vvvpii;
typedef tuple<ll, ll, ll> tiii;
typedef vector<tuple<ll, ll, ll>> vtiii;
typedef vector<vector<tuple<ll, ll, ll>>> vvtiii;
typedef vector<vector<vector<tuple<ll, ll, ll>>>> vvvtiii;
typedef vector<string> vs;
typedef vector<vector<string>> vvs;
typedef set<ll> si;
typedef vector<set<ll>> vsi;
typedef vector<vector<set<ll>>> vvsi;
typedef set<pair<ll, ll>> spii;
typedef vector<set<pair<ll, ll>>> vspii;
typedef map<ll, ll> mii;
typedef map<ll, bool> mib;
typedef map<ll, double> mid;
typedef vector<map<ll, ll>> vmii;
typedef vector<map<ll, double>> vmid;
typedef vector<map<ll, bool>> vmib;

void solve() {
    ll n, k; cin >> n >> k;

    vvi a (n + 1, vi (n + 1)); for (ll i = 1; i <= n; i++) for (ll j = i; j <= n; j++) cin >> a[i][j];

    vvi dp (n + 1); dp[0] = {0}, dp[1] = {a[1][1], 0}; sort(all(dp[1]), greater<ll>());

    priority_queue<tiii> pq;

    for (ll i = 2; i <= n; i++) {
        while (!pq.empty()) pq.pop();

        for (ll j = 1; j < i; j++) pq.emplace(a[j + 1][i] + dp[j - 1][0], j, 0); pq.emplace(dp[i - 1][0], i, 0), pq.emplace(a[1][i], 0, 0);

        for (ll j = 0; j < k && !pq.empty(); j++) {
            const tiii cur = pq.top(); pq.pop(); dp[i].pb(get<0>(cur));

            const ll r = get<1>(cur), c = get<2>(cur);

            if (r == 0 || c + 1 >= dp[r - 1].size()) continue;

            if (r == i) {
                pq.emplace(dp[r - 1][c + 1], r, c + 1);
            } else {
                pq.emplace(a[r + 1][i] + dp[r - 1][c + 1], r, c + 1);
            }
        }
    }

    for (ll i = 0; i < k; i++) cout << dp[n][i] << " "; cout << "\n";
}

int main() {
    io
    tc

    return 0;
}