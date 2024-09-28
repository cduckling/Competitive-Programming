#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int n {}, m {}, planting {0};

char visited[100000];

void floodfill(int node, char grass, vector<pair<int, char>> adj[]) {
    if (visited[node] == '.') {
        visited[node] = grass;
        for (auto i : adj[node]) {
            if (i.second == 'S') {
                floodfill(i.first, grass, adj);
            } else {
                if (grass == 'A') {
                    floodfill(i.first, 'B', adj);
                } else {
                    floodfill(i.first, 'A', adj);
                }
            }
        }
    } else {
        if (grass != visited[node]) {
            planting = -2147483648;
        }

        return;
    }
}

int main() {
    freopen("revegetate.in", "r", stdin); freopen("revegetate.out", "w", stdout);

    cin >> n >> m;

    vector<pair<int, char>> adj[n];
    for (int i {0}; i < m; ++i) {
        char restriction {}; cin >> restriction;
        pair<int, int> favorite {}; cin >> favorite.first >> favorite.second; --favorite.first; --favorite.second;
        adj[favorite.first].emplace_back(favorite.second, restriction);
        adj[favorite.second].emplace_back(favorite.first, restriction);
    }

    for (int i {0}; i < n; ++i) {
        visited[i] = '.';
    }

    for (int i {0}; i < n; ++i) {
        if (visited[i] == '.') {
            floodfill(i, 'A', adj);
            ++planting;
        }
    }

    cout << 1; for (int i {0}; i < planting; ++i) {cout << 0;}
}