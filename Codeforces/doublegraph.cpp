#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <numeric>
using namespace std;

#define tc ll t; cin >> t; while (t--) solve();
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(a) (a).begin(), (a).end()
#define pb(i) push_back(i)
#define eb(i) emplace_back(i)
#define ceil(a, b) ((a + b - 1) / b)
#define inf (ll) 1e18
#define fail {cout << -1 << "\n"; return;}

typedef long long ll;
typedef pair<ll, ll> pii;
typedef tuple<ll, ll, ll> tiii;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef vector<set<ll>> vsi;
typedef vector<pair<ll, ll>> vpii;
typedef vector<tuple<ll, ll, ll>> vtiii;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef multiset<ll> msi;
typedef set<ll> si;
typedef set<pair<ll, ll>> spii;
typedef set<tuple<ll, ll, ll>> stiii;
typedef map<ll, ll> mii;
typedef map<ll, vector<ll>> mivi;
typedef map<ll, pair<ll, ll>> mipii;
typedef map<ll, set<ll>> misi;
typedef map<ll, bool> mib;

void solve() {
    ll n; pii s, m; cin >> n >> s.first >> s.second;

    vvi adj[2]; adj[0].resize(n + 1), adj[1].resize(n + 1);

    vpii edge[2];

    cin >> m.first;

    for (ll i = 0; i < m.first; i++) {
        ll u, v; cin >> u >> v;
        adj[0][u].pb(v), adj[0][v].pb(u);
        edge[0].emplace_back(min(u, v), max(u, v));
    }

    cin >> m.second;

    for (ll i = 0; i < m.second; i++) {
        ll u, v; cin >> u >> v;
        adj[1][u].pb(v), adj[1][v].pb(u);
        edge[1].emplace_back(min(u, v), max(u, v));
    }

    vvi cost (n + 1, vi (n + 1, inf));
    vvb vis (n + 1, vb (n + 1));

    priority_queue<tiii> pq; pq.emplace(0, s.first, s.second); cost[s.first][s.second] = 0;

    while (!pq.empty()) {
        const ll u = get<1>(pq.top()), v = get<2>(pq.top()); pq.pop();

        if (vis[u][v]) continue; vis[u][v] = true;

        for (const ll i : adj[0][u]) {
            for (const ll j : adj[1][v]) {
                if (cost[u][v] + abs(i - j) < cost[i][j]) {
                    cost[i][j] = cost[u][v] + abs(i - j);
                    pq.emplace(-cost[i][j], i, j);
                }
            }
        }
    }

    ll c = inf;

    for (const pii i : edge[0]) {
        for (const pii j : edge[1]) {
            if (i == j) {
                c = min(c, cost[i.first][i.first]);
                c = min(c, cost[i.second][i.second]);
            }
        }
    }

    if (c == inf) fail

    cout << c << "\n";
}

int main() {
    io
    tc

    return 0;
}