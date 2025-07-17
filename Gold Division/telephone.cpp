#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int b[50001], dist[50001]; bool s[51][51], vis[50001];

void solve() {
    int n {}, k {}; cin >> n >> k;

    for (int i {1}; i <= n; ++i) cin >> b[i];

    for (int i {1}; i <= k; ++i) for (int j {1}; j <= k; ++j) {
        char c {}; cin >> c;

        s[i][j] = c == '1';
    }

    vector<int> cows[k + 1]; for (int i {1}; i <= n; ++i) cows[b[i]].push_back(i);

    for (int i {1}; i <= n; ++i) dist[i] = 1e9;

    priority_queue<pair<int, int>> pq {}; pq.emplace(0, 1); dist[1] = 0;

    while (!pq.empty()) {
        const int pos = pq.top().second; pq.pop();

        if (vis[pos]) continue; vis[pos] = true; if (pos == n) break;

        for (int i {1}; i <= k; ++i) if (s[b[pos]][i]) for (int j : cows[i]) if (dist[j] > dist[pos] + abs(j - pos)) {
            dist[j] = dist[pos] + abs(j - pos);
            pq.emplace(-dist[j], j);
        }
    }

    if (dist[n] == 1e9) dist[n] = -1; cout << dist[n] << "\n";
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    solve();

    return 0;
}