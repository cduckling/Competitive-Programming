#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int n {}, m {};

bool visited[3000];
bool closed[3000];

void dfs(int barn, vector<vector<int>>& adjacency) {
    if (visited[barn] || closed[barn]) {
        return;
    } else {
        visited[barn] = true;
        for (int b : adjacency[barn]) {dfs(b, adjacency);}
    }
}

int main() {
    freopen("closing.in", "r", stdin); freopen("closing.out", "w", stdout);

    cin >> n >> m;

    vector<vector<int>> adjacency (n, vector<int> ());
    for (int i {0}; i < m; ++i) {
        pair<int, int> edge {};
        cin >> edge.first >> edge.second;
        --edge.first; --edge.second;

        adjacency[edge.first].push_back(edge.second);
        adjacency[edge.second].push_back(edge.first);
    }

    for (int i {0}; i < n; ++i) {
        for (int j {0}; j < n; ++j) {if (!closed[j]) {dfs(j, adjacency); break;}}

        bool c {true};
        for (int j {0}; j < n; ++j) {if (!closed[j] && !visited[j]) {c = false;} visited[j] = false;}
        if (c) {cout << "YES\n";} else {cout << "NO\n";}

        int closing {}; cin >> closing; --closing;
        closed[closing] = true;
    }
}