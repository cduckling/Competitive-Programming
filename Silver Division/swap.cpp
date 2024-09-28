#include <iostream>
#include <cstdio>
using namespace std;

int n {}, m {}, k {};

int visited[100000];

void dfs(int node, int color, int adjacency[]) {
    if (visited[node]) {
        return;
    } else {
        visited[node] = color;
        dfs(adjacency[node], color, adjacency);
    }
}

int main() {
    freopen("swap.in", "r", stdin); freopen("swap.out", "w", stdout);

    cin >> n >> m >> k;

    int process[n];
    for (int i {0}; i < n; ++i) {
        process[i] = i;
    }
    for (int i {0}; i < m; ++i) {
        pair<int, int> r {}; cin >> r.first >> r.second; --r.first; --r.second;

        for (int j {r.first}; j <= (r.first + r.second) / 2; ++j) {
            swap(process[j], process[r.second + r.first - j]);
        }
    }

    int exercise[n];
    for (int i {0}; i < n; ++i) {
        exercise[process[i]] = i;
    }

    int color {0};
    for (int i {0}; i < n; ++i) {
        if (!visited[i]) {
            ++color;
            dfs(i, color, exercise);
        }
    }

    int cycles[color];
    for (int i {0}; i < color; ++i) {
        cycles[i] = 0;
    }
    for (int i {0}; i < n; ++i) {
        ++cycles[visited[i] - 1];
    }

    int cows[n];
    for (int i {0}; i < n; ++i) {
        int position {i};

        for (int j {0}; j < k % cycles[visited[i] - 1]; ++j) {
            position = exercise[position];
        }

        cows[position] = i;
    }

    for (int i {0}; i < n; ++i) {cout << cows[i] + 1 << "\n";}
}