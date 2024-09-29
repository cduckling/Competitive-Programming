#include <iostream>
#include <vector>
using namespace std;

#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    io

    int n {}, m {}; cin >> n >> m;

    vector<tuple<int, int, int>> edges (m); for (int i {0}; i < m; ++i) {
        int a {}, b {}, c {}; cin >> a >> b >> c; edges[i] = {a, b, c};
    }

    vector<int> dist (n, 1e9); dist[0] = 0;

    for (int i {1}; i < n; ++i) {
        for (auto e : edges) {
            int a {}, b {}, c {}; tie(a, b, c) = e;

            dist[a] = min(dist[a], dist[b] + c);
            dist[b] = min(dist[b], dist[a] + c);
        }
    }

    for (int i : dist) cout << i << " ";

    return 0;
}