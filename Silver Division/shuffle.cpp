#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
using namespace std;

int n {}, positions {0};

bool visited[100000];

vector<int> detected {};

void dfs(int node, set<int> path, int adj[]) {
    if (visited[node]) {
        if (path.count(node) == 1) {detected.push_back(node);}
        return;
    } else {
        visited[node] = true;
        path.insert(node);
        dfs(adj[node], path, adj);
    }
}

void cycles (int node, int adj[]) {
    if (visited[node]) {
        return;
    } else {
        ++positions;
        visited[node] = true;
        cycles(adj[node], adj);
    }
}

int main() {
    freopen("shuffle.in", "r", stdin); freopen("shuffle.out", "w", stdout);

    cin >> n;

    int shuffle[n];
    for (int i {0}; i < n; ++i) {
        cin >> shuffle[i]; --shuffle[i];
    }

    for (int i {0}; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, {}, shuffle);
        }
    }

    for (int i {0}; i < n; ++i) {
        visited[i] = false;
    }

    for (int i : detected) {
        cycles(i, shuffle);
    }

    cout << positions;
}