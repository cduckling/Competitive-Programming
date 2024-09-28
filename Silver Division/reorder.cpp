#include <iostream>
#include <cstdio>
using namespace std;

int n {};

int visited[100];
int components[100];

void dfs(int node, int color, int adjacency[]) {
    if (visited[node]) {
        return;
    } else {
        visited[node] = color;
        ++components[color - 1];
        dfs(adjacency[node], color, adjacency);
    }
}

int main() {
    freopen("reorder.in", "r", stdin); freopen("reorder.out", "w", stdout);

    cin >> n;

    int a[n];
    for (int i {0}; i < n; ++i) {
        cin >> a[i]; --a[i];
    }

    int b[n];
    for (int i {0}; i < n; ++i) {
        cin >> b[i]; --b[i];
    }

    pair<int, int> c[n];
    for (int i {0}; i < n; ++i) {
        c[a[i]].first = i;
        c[b[i]].second = i;
    }

    int adjacency[n];
    for (int i {0}; i < n; ++i) {
        adjacency[c[i].first] = c[i].second;
    }

    int color {0};
    for (int i {0}; i < n; ++i) {
        if (!visited[i] && adjacency[i] != i) {
            ++color;
            dfs(i, color, adjacency);
        }
    }

    int longest {0};
    for (int i {0}; i < color; ++i) {
        longest = max(longest, components[i]);
    }

    cout << color << " " << (color == 0 ? -1 : longest);
}