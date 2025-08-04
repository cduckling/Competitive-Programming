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

#define square(a) ((a) * (a))

void base(const ll n, const ll k, vvi& dist, const vvpii& adj) {
    vb vis (n + 1); priority_queue<pii> pq; pq.emplace(0, 1);

    while (!pq.empty()) {
        const ll ver = pq.top().sec; pq.pop();

        if (vis[ver]) continue; vis[ver] = true;

        for (const pii i : adj[ver]) if (dist[0][ver] + i.sec < dist[0][i.fir]) {
            dist[0][i.fir] = dist[0][ver] + i.sec;
            pq.emplace(-dist[0][i.fir], i.fir);
        }
    }
}

void calc(const ll n, const ll r, const pii solve, const pii pos, vvi& dist, const vvpii& adj) {
    if (solve.fir > solve.sec) return;

    const ll mid = (solve.fir + solve.sec) / 2;

    ll res = pos.fir; for (int i = pos.fir; i <= min(mid, pos.sec); i++) if (dist[r - 1][i] + square(i - mid) < dist[r - 1][res] + square(res - mid)) res = i;

    dist[r][mid] = min(dist[r][mid], dist[r - 1][res] + square(res - mid));

    if (solve.fir == solve.sec) return;

    calc(n, r, {solve.fir, mid - 1}, {pos.fir, res}, dist, adj);
    calc(n, r, {mid + 1, solve.sec}, {res, pos.sec}, dist, adj);
}

void solve() {
    ll n, m, k; cin >> n >> m >> k;

    vvpii adj (n + 1); for (ll i = 1; i <= m; i++) {
        ll u, v, w; cin >> u >> v >> w;
        adj[u].eb(v, w), adj[v].eb(u, w);
    }

    vvi dist (k + 1, vi (n + 1, inf)); dist[0][1] = 0; base(n, k, dist, adj);

    for (ll r = 1; r <= k; r++) {
        calc(n, r, {1, n}, {1, n}, dist, adj);

        reverse(++dist[r - 1].begin(), dist[r - 1].end()), reverse(++dist[r].begin(), dist[r].end()); calc(n, r, {1, n}, {1, n}, dist, adj); reverse(++dist[r - 1].begin(), dist[r - 1].end()), reverse(++dist[r].begin(), dist[r].end());

        vb vis (n + 1); priority_queue<pii> pq; for (int i = 1; i <= n; i++) pq.emplace(-dist[r][i], i);

        while (!pq.empty()) {
            const ll ver = pq.top().sec; pq.pop();

            if (vis[ver]) continue; vis[ver] = true;

            for (const pii i : adj[ver]) if (dist[r][ver] + i.sec < dist[r][i.fir]) {
                dist[r][i.fir] = dist[r][ver] + i.sec;
                pq.emplace(-dist[r][i.fir], i.fir);
            }
        }
    }

    for (ll j = 1; j <= n; j++) cout << dist[k][j] << " "; cout << "\n";
}

int main() {
    io

    solve();

    return 0;
}