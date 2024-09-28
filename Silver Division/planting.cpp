#include <iostream>
#include <cstdio>
using namespace std;

int adjacency[100000];

int main() {
    freopen("planting.in", "r", stdin); freopen("planting.out", "w", stdout);

    int n {}; cin >> n;

    for (int i {1}; i < n; ++i) {
        pair<int, int> path {}; cin >> path.first >> path.second; --path.first; --path.second;
        ++adjacency[path.first];
        ++adjacency[path.second];
    }

    int grass {0};
    for (int i {0}; i < n; ++i) {
        grass = max(grass, adjacency[i]);
    }
    cout << grass + 1;
}