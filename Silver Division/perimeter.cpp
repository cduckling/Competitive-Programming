#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

typedef vector<vector<char>> c;
typedef vector<vector<int>> b;

int n {};

c cream {};
b blobs {};

bool s(pair<int, int> a, pair<int, int> b) {return (a.first == b.first) ? (a.second > b.second) : (a.first < b.first);}

void dfs(pair<int, int> s, int blob) {
    if (cream[s.first][s.second] == '.' || blobs[s.first][s.second]) {
        return;
    } else {
        blobs[s.first][s.second] = blob;

        dfs({s.first - 1, s.second}, blob);
        dfs({s.first + 1, s.second}, blob);
        dfs({s.first, s.second - 1}, blob);
        dfs({s.first, s.second + 1}, blob);
    }
}

int main() {
    freopen("perimeter.in", "r", stdin); freopen("perimeter.out", "w", stdout);

    cin >> n;

    c Cream (n + 2, vector<char> (n + 2, '.'));
    b Blobs (n + 2, vector<int> (n + 2, 0));

    cream = Cream;
    blobs = Blobs;

    for (int i {1}; i <= n; ++i) {
        for (int j {1}; j <= n; ++j) {
            cin >> cream[i][j];
        }
    }

    int blob {0};
    for (int i {1}; i <= n; ++i) {
        for (int j {1}; j <= n; ++j) {
            if (!blobs[i][j] && cream[i][j] == '#') {
                ++blob;
                dfs({i, j}, blob);
            }
        }
    }

    pair<int, int> scoops[blob];
    for (int i {0}; i < blob; ++i) {scoops[i] = {0, 0};}

    for (int i {1}; i <= n; ++i) {
        for (int j {1}; j <= n; ++j) {
            int color = blobs[i][j];

            ++scoops[color - 1].first;
            scoops[color - 1].second += 4 - (color == blobs[i - 1][j]) - (color == blobs[i + 1][j]) - (color == blobs[i][j - 1]) - (color == blobs[i][j + 1]);
        }
    }

    sort(scoops, scoops + blob, s);

    cout << scoops[blob - 1].first << " " << scoops[blob - 1].second;
}