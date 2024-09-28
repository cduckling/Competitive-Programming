#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int n {}, m {};

int visited[100000];
vector<int> components[100000];

void dfs(int node, int color, vector<int> adj[]) {
    if (visited[node]) {
        return;
    } else {
        visited[node] = color;
        components[color - 1].push_back(node);
        for (int i : adj[node]) {dfs(i, color, adj);}
    }
}

void floodfill(int node, int color, vector<pair<int, int>> adj[], int min) {
    if (visited[node]) {
        return;
    } else {
        visited[node] = color;
        for (auto i : adj[node]) {
            if (i.second >= min) {
                floodfill(i.first, color, adj, min);
            }
        }
    }
}

int main() {
    freopen("wormsort.in", "r", stdin); freopen("wormsort.out", "w", stdout);

    cin >> n >> m;

    int scattered[n]; bool sorted {true};
    for (int i {0}; i < n; ++i) {
        cin >> scattered[i]; --scattered[i];
        if (i != scattered[i]) {sorted = false;}
    }

    vector<pair<int, int>> adj[n];
    for (int i {0}; i < m; ++i) {
        pair<int, int> wormhole {}; cin >> wormhole.first >> wormhole.second; --wormhole.first; --wormhole.second;
        int width {}; cin >> width;

        adj[wormhole.first].emplace_back(wormhole.second, width);
        adj[wormhole.second].emplace_back(wormhole.first, width);
    }

    if (sorted) {
        cout << -1;
    } else {
        vector<int> sorting[n];
        for (int i {0}; i < n; ++i) {
            sorting[i].push_back(scattered[i]);
        }

        int color {0};
        for (int i {0}; i < n; ++i) {
            if (!visited[i]) {
                ++color;
                dfs(i, color, sorting);
            }
        }

        pair<int, int> interval {1, 1000000000};

        while (interval.first != interval.second) {
            for (int i {0}; i < n; ++i) {visited[i] = 0;}
            int median {(interval.first + interval.second + 1) / 2};

            int c {0};
            for (int i {0}; i < n; ++i) {
                if (!visited[i]) {
                    ++c;
                    floodfill(i, c, adj, median);
                }
            }

            bool p {true};
            for (int i {0}; i < color; ++i) {
                int k {visited[components[i][0]]};

                for (int j : components[i]) {
                    if (k != visited[j]) {p = false;}
                }
            }

            if (p) {
                interval.first = median;
            } else {
                interval.second = median - 1;
            }
        }

        cout << interval.first;
    }
}