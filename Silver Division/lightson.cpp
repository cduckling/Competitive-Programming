#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

typedef pair<int, int> room;

int n {}, m {};

vector<room> switches[102][102];
bool lit[102][102];
bool visited[102][102];

void dfs(room r) {
    if (!visited[r.first][r.second]) {
        visited[r.first][r.second] = true;

        if (lit[r.first][r.second]) {
            for (room i : switches[r.first][r.second]) {
                if (visited[i.first][i.second] && !lit[i.first][i.second]) {
                    lit[i.first][i.second] = true;
                    visited[i.first][i.second] = false;
                    dfs(i);
                } else {
                    lit[i.first][i.second] = true;
                }
            }

            dfs({r.first - 1, r.second});
            dfs({r.first + 1, r.second});
            dfs({r.first, r.second - 1});
            dfs({r.first, r.second + 1});

        }
    }
}

int main() {
    freopen("lightson.in", "r", stdin); freopen("lightson.out", "w", stdout);

    cin >> n >> m;

    for (int i {0}; i < m; ++i) {
        int x {}, y {}, a {}, b {};
        cin >> x >> y >> a >> b;

        switches[x][y].emplace_back(a, b);
    }

    lit[1][1] = true;
    dfs({1, 1});

    int illuminated {0};
    for (int i {1}; i < 101; ++i) {
        for (int j {1}; j < 101; ++j) {
            if (lit[i][j]) {
                ++illuminated;
            }
        }
    }

    cout << illuminated;
}