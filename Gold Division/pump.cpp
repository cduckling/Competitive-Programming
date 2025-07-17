#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>
using namespace std;

#define eb(a, b) emplace_back(a, b)

typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;
typedef vector<pair<ll, ll>> vpii;
typedef vector<vector<pair<ll, ll>>> vvpii;

struct pipe {
    ll u, v, c, f;
};

bool cmp(const pipe& a, const pipe& b) {
    return a.f > b.f;
}

void solve() {
    ll n, m; cin >> n >> m;

    vector<pipe> p (m); for (ll i = 0; i < m; i++) {
        ll u, v, c, f; cin >> u >> v >> c >> f;

        p[i].u = u, p[i].v = v, p[i].c = c, p[i].f = f;
    } sort(p.begin(), p.end(), cmp);

    vvpii adj (n + 1);

    vi cost (n + 1), vis (n + 1);

    priority_queue<pii> pq;

    ll r = 0;

    for (ll i = 0; i < m; i++) {
        for (ll j = 1; j <= n; j++) cost[j] = 1e9, vis[j] = false; while (!pq.empty()) pq.pop();

        const ll u = p[i].u, v = p[i].v, c = p[i].c, f = p[i].f;

        adj[u].eb(v, c), adj[v].eb(u, c);

        pq.emplace(0, 1); cost[1] = 0;

        while (!pq.empty()) {
            const ll ver = pq.top().second; pq.pop();

            if (vis[ver]) continue; vis[ver] = true;

            for (const pii j : adj[ver]) {
                if (cost[ver] + j.second < cost[j.first]) {
                    cost[j.first] = cost[ver] + j.second;
                    pq.emplace(-cost[j.first], j.first);
                }
            }
        }

        if (cost[n] == static_cast<ll>(1e9)) continue;

        r = max(r, (static_cast<ll>(1e6) * f) / cost[n]);
    }

    cout << r << "\n";
}

int main() {
    freopen("pump.in", "r", stdin); freopen("pump.out", "w", stdout);

    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();

    return 0;
}