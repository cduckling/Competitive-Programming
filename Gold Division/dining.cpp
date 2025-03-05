#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;

#define eb(a, b) emplace_back(a, b)
#define inf 1e18

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;
typedef vector<vector<pair<ll, ll>>> vvpii;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;

void solve() {
    ll n, m, k; cin >> n >> m >> k;

    vvpii adj (n + 1); for (int i = 0; i < m; i++) {
        ll a, b, t; cin >> a >> b >> t;
        adj[a].eb(b, t), adj[b].eb(a, t);
    }

    vi dist (n + 1, inf); vb vis (n + 1);

    priority_queue<pii> pq; pq.emplace(0, n); dist[n] = 0;

    while (!pq.empty()) {
        const int ver = pq.top().second; pq.pop();

        if (vis[ver]) continue; vis[ver] = true;

        for (const pii j : adj[ver]) {
            if (dist[ver] + j.second < dist[j.first]) {
                dist[j.first] = dist[ver] + j.second;
                pq.emplace(-dist[j.first], j.first);
            }
        }
    }

    vpii py (k); for (int i = 0; i < k; i++) cin >> py[i].first >> py[i].second;

    for (int i = 1; i <= n; i++) vis[i] = false;

    vi yum (n + 1, inf);

    for (const auto [p, y] : py) pq.emplace(-(dist[p] - y), p), yum[p] = dist[p] - y;

    while (!pq.empty()) {
        const ll ver = pq.top().second; pq.pop();

        if (vis[ver]) continue; vis[ver] = true;

        for (const pii j : adj[ver]) {
            if (yum[ver] + j.second < yum[j.first]) {
                yum[j.first] = yum[ver] + j.second;
                pq.emplace(-(yum[ver] + j.second), j.first);
            }
        }
    }

    for (int i = 1; i < n; i++) cout << (yum[i] <= dist[i]) << "\n";
}

int main() {
    freopen("dining.in", "r", stdin); freopen("dining.out", "w", stdout);

    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();

    return 0;
}