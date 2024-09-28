#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

int p {}; void path(int v, const vector<vector<int>>& adj, int r, int d_) {
    if (p < d_) {
        p = d_;
    }

    ++d_;
    for (int i : adj[r]) {
        if (i == v) continue;

        path(r, adj, i, d_);
    }
}

void distances(int node, int v, const vector<vector<int>>& adj, vector<int>& dist_d) {
    for (int i : adj[node]) {
        if (i == v) continue;

        dist_d[i] = dist_d[node] + 1;
        distances(i, node, adj, dist_d);
    }
}

void solve() {
    int n {}, a {}, b {}; cin >> n >> a >> b; --a; --b;

    vector<vector<int>> adj (n, vector<int> ()); for (int i {1}; i < n; ++i) {
        int x {}, y {}; cin >> x >> y; --x; --y;
        adj[x].push_back(y); adj[y].push_back(x);
    }

    vector<int> dist_a (n), dist_b (n); distances(a, a, adj, dist_a); distances(b, b, adj, dist_b);
    vector<int> distance (n); for (int i {0}; i < n; ++i) {
        distance[i] = dist_a[i] + dist_b[i];
    } sort(distance.begin(), distance.end());

    int d {0}; for (auto i : distance) {
        if (i == distance[0]) {
            ++d;
        } else {
            break;
        }
    }

    int r {};

    for (int i {0}; i < n; ++i) {
        if (distance[0] % 2 == 0) {
            if (dist_a[i] == distance[0] / 2 && dist_b[i] == distance[0] / 2) {
                r = i; break;
            }
        } else {
            if (dist_a[i] == distance[0] / 2 && dist_b[i] == distance[0] / 2 + 1) {
                r = i; break;
            }
        }
    }

    p = 0; path(r, adj, r, 1);
    cout << 2 * (n - 1) - p + d / 2 + 1 << "\n";
}

int main() {
    io
    tc

    return 0;
}