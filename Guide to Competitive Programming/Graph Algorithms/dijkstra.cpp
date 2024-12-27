#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <cmath>
#include <numeric>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb(i) push_back(i);
#define inf 1e18;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<pair<int, int>> vpii;
typedef vector<bool> vb;
typedef set<int> si;
typedef map<int, int> mi;
typedef map<int, vector<int>> mvi;
typedef map<int, pair<int, int>> mpii;
typedef map<int, bool> mb;

void dijkstra(const vector<vector<pii>>& adj, vi& dist, vb& vis) {
    priority_queue<pii> pq {}; pq.emplace(0, 0); dist[0] = 0;

    while (!pq.empty()) {
        const int v = pq.top().second; pq.pop();

        if (vis[v]) continue; vis[v] = true;

        for (const pii& i : adj[v]) {
            if (dist[v] + i.second < dist[i.first]) {
                dist[i.first] = dist[v] + i.second;
                pq.emplace(-dist[i.first], i.first);
            }
        }
    }
}

int main() {
    io

    int n {}, m {}; cin >> n >> m;

    vector<vector<pii>> adj (n); for (int i {0}; i < m; ++i) {
        int u {}, v {}, w {}; cin >> u >> v >> w;

        adj[u].emplace_back(v, w); adj[v].emplace_back(u, w);
    }

    vi dist (n, 1e9); vb vis (n); dijkstra(adj, dist, vis);

    for (const int& i : dist) cout << i << " "; cout << "\n";

    return 0;
}