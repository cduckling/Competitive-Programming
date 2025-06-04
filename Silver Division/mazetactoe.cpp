#include <iostream>
#include <vector>
#include <set>
#include <sstream>
using namespace std;

int n;

pair<int, int> bessie; vector<pair<int, int>> moves; vector<vector<set<pair<int, int>>>> adj (25, vector<set<pair<int, int>>> (25));

vector<vector<string>> maze;

bool visited[25][25]; void dfs(pair<int, int> a, pair<int, int> c) {
    if (visited[c.first][c.second]) {
        return;
    } else {
        visited[c.first][c.second] = true;

        if (maze[c.first][c.second] == "###") {
            return;
        } else if (maze[c.first][c.second] == "..." || a == c) {
            dfs(a, {c.first - 1, c.second});
            dfs(a, {c.first + 1, c.second});
            dfs(a, {c.first, c.second - 1});
            dfs(a, {c.first, c.second + 1});
        } else {
            adj[a.first][a.second].insert(c);
            return;
        }
    }
}

set<vector<vector<char>>> configurations;
bool won(vector<vector<char>>& game) {
    for (int i = 0; i < 3; ++i) {
        string a, b;

        for (int j = 0; j < 3; ++j) {
            a += game[i][j];
            b += game[j][i];
        }

        if (a == "MOO" || a == "OOM" || b == "MOO" || b == "OOM") {
            return true;
        }
    }

    string a, b;
    a += game[0][0]; a += game[1][1]; a += game[2][2];
    b += game[0][2]; b += game[1][1]; b += game[2][0];

    return a == "MOO" || a == "OOM" || b == "MOO" || b == "OOM";
}
bool finished(vector<vector<char>>& game) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (game[i][j] == '.') {
                return false;
            }
        }
    }

    return true;
}

void recurse(pair<int, int> cell, vector<vector<set<pair<int, int>>>> adj_, vector<vector<char>> game) {
    string move {maze[cell.first][cell.second]};

    if (move != "BBB") {
        stringstream s; s << move[0] << " " << move[1] << " " << move[2];
        char a; int b, c; s >> a >> b >> c; --b; --c;

        if (game[b][c] == '.') {
            game[b][c] = a;
        }

        if (finished(game)) {
            return;
        }

        if (won(game)) {
            configurations.insert(game);
            return;
        }
    }

    for (pair<int, int> i : adj_[cell.first][cell.second]) {
        adj_[i.first][i.second].erase(cell);

        for (pair<int, int> j : adj_[cell.first][cell.second]) {
            adj_[i.first][i.second].insert(j);
        }

        adj_[i.first][i.second].erase(i);
    }

    for (pair<int, int> i : adj_[cell.first][cell.second]) {
        recurse(i, adj_, game);
    }
}

int main() {
    cin >> n;

    vector<vector<string>> Maze (n, vector<string> (n, "")); for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char a, b, c; cin >> a >> b >> c;
            Maze[i][j] += a; Maze[i][j] += b; Maze[i][j] += c;

            if (Maze[i][j] == "BBB") {
                bessie = {i, j};
            } else if (Maze[i][j] == "..." || Maze[i][j] == "###") {
                ;
            } else {
                moves.emplace_back(i, j);
            }
        }
    }

    maze = Maze;

    dfs(bessie, bessie); for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            visited[i][j] = false;
        }
    } for (pair<int, int> move : moves) {
        dfs(move, move);
        for (int i {0}; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                visited[i][j] = false;
            }
        }
    }

    vector<vector<char>> game (3, vector<char> (3, '.'));
    recurse(bessie, adj, game);
    cout << configurations.size();
}
