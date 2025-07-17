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
#define eb(a, b, c) emplace_back(a, b, c)
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

#define fail {cout << -1 << "\n"; return;}

void solve() {
    ll n, m, p, q; cin >> n >> m >> p >> q;

    vvc b (n + 2, vc (m + 2, '?')); for (ll i = 1; i <= n; i++) for (ll j = 1; j <= m; j++) cin >> b[i][j];

    for (ll i = 1; i <= n; i++) for (ll j = 1; j <= m; j++) if (b[i][j] == '.' && (b[i - 1][j] == '.' || b[i + 1][j] == '.' || b[i][j - 1] == '.' || b[i][j + 1] == '.')) {
        cout << 0 << "\n"; return;
    }

    vpii ok; for (ll i = 1; i <= n; i++) for (ll j = 1; j <= m; j++) if (b[i][j] == '.') ok.emplace_back(i, j); if (ok.size() < 2) fail

    vvi cost (n + 2, vi (m + 2, inf)); vvb vis (n + 2, vb (m + 2));

    priority_queue<tiii> pq; for (ll i = 1; i <= n; i++) for (ll j = 1; j <= m; j++) if (b[i][j] == '.') cost[i][j] = 0, pq.emplace(0, i, j);

    while (!pq.empty()) {
        const tiii cur = pq.top(); pq.pop();

        const ll i = get<1>(cur), j = get<2>(cur);

        if (vis[i][j]) continue; vis[i][j] = true;

        switch (b[i + 1][j]) {
            case 'L': if (cost[i + 1][j + 1] > cost[i][j] + p) cost[i + 1][j + 1] = cost[i][j] + p, pq.emplace(-cost[i + 1][j + 1], i + 1, j + 1); break;
            case 'R': if (cost[i + 1][j - 1] > cost[i][j] + p) cost[i + 1][j - 1] = cost[i][j] + p, pq.emplace(-cost[i + 1][j - 1], i + 1, j - 1); break;
            case 'U': if (cost[i + 2][j] > cost[i][j] + q) cost[i + 2][j] = cost[i][j] + q, pq.emplace(-cost[i + 2][j], i + 2, j); break;
            case 'D': break;
        }

        switch (b[i - 1][j]) {
            case 'L': if (cost[i - 1][j + 1] > cost[i][j] + p) cost[i - 1][j + 1] = cost[i][j] + p, pq.emplace(-cost[i - 1][j + 1], i - 1, j + 1); break;
            case 'R': if (cost[i - 1][j - 1] > cost[i][j] + p) cost[i - 1][j - 1] = cost[i][j] + p, pq.emplace(-cost[i - 1][j - 1], i - 1, j - 1); break;
            case 'U': break;
            case 'D': if (cost[i - 2][j] > cost[i][j] + q) cost[i - 2][j] = cost[i][j] + q, pq.emplace(-cost[i - 2][j], i - 2, j); break;
        }

        switch (b[i][j - 1]) {
            case 'L': break;
            case 'R': if (cost[i][j - 2] > cost[i][j] + q) cost[i][j - 2] = cost[i][j] + q, pq.emplace(-cost[i][j - 2], i, j - 2); break;
            case 'U': if (cost[i + 1][j - 1] > cost[i][j] + p) cost[i + 1][j - 1] = cost[i][j] + p, pq.emplace(-cost[i + 1][j - 1], i + 1, j - 1); break;
            case 'D': if (cost[i - 1][j - 1] > cost[i][j] + p) cost[i - 1][j - 1] = cost[i][j] + p, pq.emplace(-cost[i - 1][j - 1], i - 1, j - 1); break;
        }

        switch (b[i][j + 1]) {
            case 'L': if (cost[i][j + 2] > cost[i][j] + q) cost[i][j + 2] = cost[i][j] + q, pq.emplace(-cost[i][j + 2], i, j + 2); break;
            case 'R': break;
            case 'U': if (cost[i + 1][j + 1] > cost[i][j] + p) cost[i + 1][j + 1] = cost[i][j] + p, pq.emplace(-cost[i + 1][j + 1], i + 1, j + 1); break;
            case 'D': if (cost[i - 1][j + 1] > cost[i][j] + p) cost[i - 1][j + 1] = cost[i][j] + p, pq.emplace(-cost[i - 1][j + 1], i - 1, j + 1); break;
        }
    }

    ll res = inf; for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) res = min(res, min(cost[i][j] + cost[i - 1][j], min(cost[i][j] + cost[i + 1][j], min(cost[i][j] + cost[i][j - 1], cost[i][j] + cost[i][j + 1])))); cout << (res >= inf ? -1 : res) << "\n";
}

int main() {
    io

    solve();

    return 0;
}