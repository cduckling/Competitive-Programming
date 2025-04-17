#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

#define tc int t {}; cin >> t; while (t--) {solve();}
#define io ios_base::sync_with_stdio(false); cin.tie(NULL);

typedef long long ll;

void dfs(pair<int, int> node, int color, const vector<vector<char>>& grid, vector<vector<int>>& visited) {
    if (visited[node.first][node.second] != 0) {
        return;
    } else if (grid[node.first][node.second] == 'x') {
        visited[node.first][node.second] = -1;  return;
    } else {
        visited[node.first][node.second] = color;

        dfs({node.first - 1, node.second}, color, grid, visited);
        dfs({node.first + 1, node.second}, color, grid, visited);
        dfs({node.first, node.second - 1}, color, grid, visited);
        dfs({node.first, node.second + 1}, color, grid, visited);
    }
}

void solve() {
    int n {}; cin >> n;

    vector<vector<char>> grid (4, vector<char> (n + 2, 'x')); for (int i {1}; i <= 2; ++i) {
        for (int j {1}; j <= n; ++j) {
            cin >> grid[i][j];
        }
    }

    int color {0}; vector<vector<int>> visited (4, vector<int> (n + 2));

    for (int i {1}; i <= 2; ++i) {
        for (int j {1}; j <= n; ++j) {
            if (visited[i][j] == 0 && grid[i][j] != 'x') {
                ++color;
                dfs({i, j}, color, grid, visited);
            }
        }
    }

    int p {0};

    for (int i {1}; i <= 2; ++i) {
        for (int j {1}; j <= n; ++j) {
            if (grid[i][j] == 'x') continue;

            if (i == 1) {
                if (grid[i][j - 1] == '.' && grid[i][j + 1] == '.' && grid[i + 1][j] == '.' && grid[i + 1][j - 1] == 'x' && grid[i + 1][j + 1] == 'x') {
                    ++p;
                }
            } else {
                if (grid[i][j - 1] == '.' && grid[i][j + 1] == '.' && grid[i - 1][j] == '.'  && grid[i - 1][j - 1] == 'x'  && grid[i - 1][j + 1] == 'x') {
                    ++p;
                }
            }
        }
    }

    //x.x
    //.x.

    cout << p << "\n";
}

int main() {
    io
    tc

    return 0;
}