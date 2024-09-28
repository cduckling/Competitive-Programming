#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int n {}, m {};

char farms[100000]; int visited[100000]; vector<int> adjacency[100000];

void dfs(int barn, int color, char milk) {
    if (visited[barn] || milk != farms[barn]) {
        return;
    } else {
        visited[barn] = color;
        for (int b : adjacency[barn]) {dfs(b, color, milk);}
    }
}

int main() {
    freopen("milkvisits.in", "r", stdin); freopen("milkvisits.out", "w", stdout);

    cin >> n >> m;

    for (int i {0}; i < n; ++i) {
        cin >> farms[i];
    }
    for (int i {1}; i < n; ++i) {
        int x {}, y {}; cin >> x >> y; --x; --y;
        adjacency[x].push_back(y);
        adjacency[y].push_back(x);
    }

    int color {0};
    for (int i {0}; i < n; ++i) {
        if (!visited[i]) {
            ++color;
            dfs(i, color, farms[i]);
        }
    }

    for (int i {0}; i < m; ++i) {
        pair<int, int> path {}; cin >> path.first >> path.second; --path.first; --path.second;
        char milk {}; cin >> milk;

        cout << ((visited[path.first] == visited[path.second]) ? (farms[path.first] == milk) : 1);
    }
}