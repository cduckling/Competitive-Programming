#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;
typedef vector<vector<int>> matrix;

void dfs(const matrix& Grid, matrix& Visited, const pair<int, int> Cell, const int C) {
    int i = Cell.first, j = Cell.second;

    if (Visited[i][j] || !Grid[i][j]) {
        return;
    } else {
        Visited[i][j] = C;

        dfs(Grid, Visited, {i + 1, j}, C);
        dfs(Grid, Visited, {i - 1, j}, C);
        dfs(Grid, Visited, {i, j + 1}, C);
        dfs(Grid, Visited, {i, j - 1}, C);
    }
}

void solve() {
    int N {}, M {}; cin >> N >> M;

    matrix Grid (N + 2, vector<int> (M + 2));
    for (int i {1}; i <= N; ++i) {
        for (int j {1}; j <= M; ++j) {
            char k {}; cin >> k;

            Grid[i][j] = (k == '#');
        }
    }

    matrix Visited (N + 2, vector<int> (M + 2)); int C {0};
    for (int i {1}; i <= N; ++i) {
        for (int j {1}; j <= M; ++j) {
            if (!Visited[i][j] && Grid[i][j]) {
                ++C;
                dfs(Grid, Visited, {i, j}, C);
            }
        }
    }

    vector<int> Colors (C + 1);
    for (int i {1}; i <= N; ++i) {
        for (int j {1}; j <= M; ++j) {
            ++Colors[Visited[i][j]];
        }
    }

    int maximum {0};

    for (int i {1}; i <= N; ++i) {
        unordered_set<int> connected {};
        int component {0};

        for (int j {1}; j <= M; ++j) {
            if (!Visited[i][j]) {
                ++component;
            } else {
                connected.insert(Visited[i][j]);
            }

            if (Visited[i - 1][j]) {
                connected.insert(Visited[i - 1][j]);
            }

            if (Visited[i + 1][j]) {
                connected.insert(Visited[i + 1][j]);
            }
        }

        for (int j : connected) {
            component += Colors[j];
        }

        maximum = max(maximum, component);
    }

    for (int i {1}; i <= M; ++i) {
        unordered_set<int> connected {};
        int component {0};

        for (int j {1}; j <= N; ++j) {
            if (!Visited[j][i]) {
                ++component;
            } else {
                connected.insert(Visited[j][i]);
            }

            if (Visited[j][i - 1]) {
                connected.insert(Visited[j][i - 1]);
            }

            if (Visited[j][i + 1]) {
                connected.insert(Visited[j][i + 1]);
            }
        }

        for (int j : connected) {
            component += Colors[j];
        }

        maximum = max(maximum, component);
    }

    cout << maximum << "\n";
}

int main() {
    io
    tc

    return 0;
}