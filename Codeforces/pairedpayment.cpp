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
#define all(a) ++(a).begin(), (a).end()
#define pb(a) push_back(a)
#define eb(a, b) emplace_back(a, b)
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
typedef vector<char> vc;
typedef vector<vector<char>> vvc;

void solve() {
    ll n, m; cin >> n >> m;

    vvpii adj (n + 1); for (ll i = 1; i <= m; i++) {
        ll u, v, w; cin >> u >> v >> w;
        adj[u].eb(v, w), adj[v].eb(u, w);
    }

    vvi dp (n + 1, vi (51, inf)); dp[1][0] = 0;

    priority_queue<tiii> pq; pq.emplace(0, 1, 0);

    while (!pq.empty()) {
        const ll i = get<1>(pq.top()), j = get<2>(pq.top()); pq.pop();

        for (const pii k : adj[i]) if (j && dp[i][j] + k.sec * k.sec + 2 * j * k.sec < dp[k.fir][0]) {
            dp[k.fir][0] = dp[i][j] + k.sec * k.sec + 2 * j * k.sec;
            pq.emplace(-dp[k.fir][0], k.fir, 0);
        } else if (!j && dp[i][j] + k.sec * k.sec < dp[k.fir][k.sec]) {
            dp[k.fir][k.sec] = dp[i][j] + k.sec * k.sec;
            pq.emplace(-dp[k.fir][k.sec], k.fir, k.sec);
        }
    }

    for (int i = 1; i <= n; i++) cout << (dp[i][0] == inf ? -1 : dp[i][0]) << " "; cout << "\n";
}

int main() {
    io

    solve();

    return 0;
}