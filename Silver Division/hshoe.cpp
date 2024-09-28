#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int n {}, b {0};

void dfs(pair<int, int> square, pair<int, int> parentheses, int path, vector<vector<int>> grid) {
    ++path;

    if (grid[square.first][square.second] >= 0) {
        return;
    } else {
        if (grid[square.first][square.second] == -1) {
            if (parentheses.second) {
                return;
            } else {
                grid[square.first][square.second] = path;
                ++parentheses.first;
            }
        } else {
            if (parentheses.first == parentheses.second) {
                return;
            } else {
                grid[square.first][square.second] = path;
                ++parentheses.second;
            }
        }

        if (parentheses.first == parentheses.second) {
            b = max(b, parentheses.first + parentheses.second);
            return;
        }

        for (int i {0}; i < 4; ++i) {
            switch (i) {
                case 0:
                    dfs({square.first - 1, square.second}, parentheses, path, grid);
                    break;
                case 1:
                    dfs({square.first + 1, square.second}, parentheses, path, grid);
                    break;
                case 2:
                    dfs({square.first, square.second - 1}, parentheses, path, grid);
                    break;
                case 3:
                    dfs({square.first, square.second + 1}, parentheses, path, grid);
                    break;
            }
        }
    }
}

int main() {
    freopen("hshoe.in", "r", stdin); freopen("hshoe.out", "w", stdout);

    cin >> n;

    vector<vector<int>> grid (7, vector<int> (7, 0));

    for (int i {1}; i <= n; ++i) {
        for (int j {1}; j <= n; ++j) {
            char k {}; cin >> k;

            if (k == '(') {
                grid[i][j] = -1;
            } else {
                grid[i][j] = -2;
            }
        }
    }

    dfs({1, 1}, {0, 0}, 0, grid);

    cout << b;
}