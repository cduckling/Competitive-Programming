#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define inf 1e18
#define pb(a) push_back(a)
#define eb(a, b) emplace_back(a, b)

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<pair<ll, ll>> vpii;
typedef vector<vector<pair<ll, ll>>> vvpii;
typedef vector<bool> vb;

vi dijkstra(const ll n, const ll c, const ll r, ll k, const ll src, const vvpii& adj) {
    vi dist (n + 1, inf); dist[src] = 0;

    vb vis (n + 1);

    priority_queue<pii> pq; pq.emplace(0, src);

    while (!pq.empty() && k) {
        const ll ver = pq.top().second; pq.pop();

        if (!vis[ver] && dist[ver] && ver <= c) k--, vis[ver] = true;

        for (const pii i : adj[ver]) {
            if (dist[ver] + i.second < dist[i.first] && dist[ver] + i.second <= r) {
                dist[i.first] = dist[ver] + i.second;

                pq.emplace(-dist[i.first], i.first);
            }
        }
    }

    return dist;
}

void solve() {
    ll n, m, c, r, k; cin >> n >> m >> c >> r >> k;

    vvpii adj (n + 1); for (ll i = 1; i <= m; i++) {
        ll u, v, l; cin >> u >> v >> l;
        adj[u].eb(v, l), adj[v].eb(u, l);
    }

    vi wcd;

    for (ll i = c + 1; i <= n; i++) {
        vi dist = dijkstra(n, c, r, k, i, adj);

        ll cnt = 0; for (ll j = 1; j <= c; j++) if (dist[j] <= r) cnt++; if (cnt >= k) wcd.pb(i);;
    }

    cout << wcd.size() << "\n"; for (const ll i : wcd) cout << i << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();

    return 0;
}