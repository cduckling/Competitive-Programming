#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int n {}, human {0}, cow {0};

vector<vector<char>> painting {};
vector<vector<int>> regions {};

void dfs(pair<int, int> s, char color, bool o) {
    char c {painting[s.first][s.second]};

    if (c == 'O' || regions[s.first][s.second]) {
        return;
    } else if (o) {
        if (c != color) {return;}
    } else {
        if (c == 'B' && color == 'G') {
            return;
        } else if (c == 'B' && color == 'R') {
            return;
        } else if (c == 'G' && color == 'B') {
            return;
        } else if (c == 'R' && color == 'B') {
            return;
        }
    }

    regions[s.first][s.second] = human;
    dfs({s.first - 1, s.second}, color, o);
    dfs({s.first + 1, s.second}, color, o);
    dfs({s.first, s.second - 1}, color, o);
    dfs({s.first, s.second + 1}, color, o);
}

int main() {
    freopen("cowart.in", "r", stdin); freopen("cowart.out", "w", stdout);

    cin >> n;

    vector<vector<char>> p (n + 2, vector<char> (n + 2, 'O'));
    vector<vector<int>> r (n + 2, vector<int> (n + 2, 0));

    painting = p;
    regions = r;

    for (int i {1}; i <= n; ++i) {
        for (int j {1}; j <= n; ++j) {
            cin >> painting[i][j];
        }
    }

    for (int i {1}; i <= n; ++i) {
        for (int j {1}; j <= n; ++j) {
            if (!regions[i][j]) {
                ++human;
                dfs({i, j}, painting[i][j], true);
            }
        }
    }

    regions = r;

    for (int i {1}; i <= n; ++i) {
        for (int j {1}; j <= n; ++j) {
            if (!regions[i][j]) {
                ++cow;
                dfs({i, j}, painting[i][j], false);
            }
        }
    }

    cout << human << " " << cow;
}